/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * ---------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 *
 *    This is gx_head main.
 *
 * ----------------------------------------------------------------------------
 */

#include "guitarix.h"       // NOLINT

#include <giomm/init.h>     // NOLINT
#include <gtkmm/main.h>     // NOLINT
#include <gxwmm/init.h>     // NOLINT
#include <string>           // NOLINT

/****************************************************************
 ** class PosixSignals
 **
 ** Block unix signals and catch them in a special thread.
 ** Blocking is inherited by all threads created after an
 ** instance of PosixSignals
 */

class PosixSignals {
private:
    sigset_t waitset;
    Glib::Thread *thread;
    volatile bool exit;
    void signal_helper_thread();
    void quit_slot();
    void gx_ladi_handler();
    void create_thread();
public:
    PosixSignals();
    ~PosixSignals();
};


PosixSignals::PosixSignals()
    : waitset(),
      thread(),
      exit(false) {
    sigemptyset(&waitset);
    /* ----- block signal USR1 ---------
    ** inherited by all threads which are created later
    ** signals are processed synchronously by signal_helper_thread
    */
    sigaddset(&waitset, SIGUSR1);
    sigaddset(&waitset, SIGCHLD);
    sigaddset(&waitset, SIGINT);
    sigaddset(&waitset, SIGQUIT);
    sigaddset(&waitset, SIGTERM);
    sigaddset(&waitset, SIGHUP);
    sigaddset(&waitset, SIGKILL);

    // ----- leave alone these signals: generated by programming errors
    // SIGABRT
    // SIGSEGV

    sigprocmask(SIG_BLOCK, &waitset, NULL);
    create_thread();
}

PosixSignals::~PosixSignals() {
    if (thread) {
	exit = true;
	kill(getpid(), SIGINT);
	thread->join();
    }
    sigprocmask(SIG_UNBLOCK, &waitset, NULL);
}

void PosixSignals::create_thread() {
    try {
	thread = Glib::Thread::create(
	    sigc::mem_fun(*this, &PosixSignals::signal_helper_thread), true);
    } catch (Glib::ThreadError& e) {
	throw gx_system::GxFatalError(
	    boost::format(_("Thread create failed (signal): %1%")) % e.what());
    }
}

void PosixSignals::quit_slot() {
    gx_system::GxExit::get_instance().exit_program();
}

void PosixSignals::gx_ladi_handler() {
    gx_system::gx_print_warning(
	_("signal_handler"), _("signal USR1 received, save settings"));
    gx_gui::GxMainInterface::get_instance().gx_settings.auto_save_state();
}


// --- wait for USR1 signal to arrive and invoke ladi handler via mainloop
void PosixSignals::signal_helper_thread() {
    const char *signame;
    guint source_id_usr1 = 0;
    pthread_sigmask(SIG_BLOCK, &waitset, NULL);
    bool seen = false;
    while (true) {
	int sig;
        int ret = sigwait(&waitset, &sig);
	if (exit) {
	    break;
	}
        if (ret != 0) {
            assert(errno == EINTR);
	    continue;
	}
	switch (sig) {
	case SIGUSR1:
	    if (Gtk::Main::level() < 1) {
		gx_system::gx_print_info(_("system startup"),
					 _("signal usr1 skipped"));
		break;
	    }
	    // do not add a new call if another one is already pending
	    if (source_id_usr1 == 0 ||
		g_main_context_find_source_by_id(NULL, source_id_usr1) == NULL) {
		const Glib::RefPtr<Glib::IdleSource> idle_source = Glib::IdleSource::create();
		idle_source->connect(
		    sigc::bind_return<bool>(
			sigc::mem_fun(*this, &PosixSignals::gx_ladi_handler),false));
		idle_source->attach();
		source_id_usr1 = idle_source->get_id();
	    }
	    break;
	case SIGCHLD:
	    Glib::signal_idle().connect_once(
		sigc::ptr_fun(gx_child_process::gx_sigchld_handler));
	    break;
	case SIGINT:
	case SIGQUIT:
	case SIGTERM:
	case SIGHUP:
	    switch (sig) {
	    case SIGINT:
		signame = _("ctrl-c");
		break;
	    case SIGQUIT:
		signame = "SIGQUIT";
		break;
	    case SIGTERM:
		signame = "SIGTERM";
		break;
	    case SIGHUP:
		signame = "SIGHUP";
		break;
	    }
	    if (!seen && Gtk::Main::level() == 1) {
		printf("\nquit (%s)\n", signame);
		Glib::signal_idle().connect_once(sigc::mem_fun(*this, &PosixSignals::quit_slot));
	    } else {
		gx_system::GxExit::get_instance().exit_program(
		    (boost::format("\nQUIT (%1%)\n") % signame).str());
	    }
	    seen = true;
	    break;
	default:
	    assert(false);
        }
    }
}


/****************************************************************
 ** class ErrorPopup
 ** show UI popup for kError messages
 */

class ErrorPopup {
private:
    string msg;
    bool active;
    Gtk::MessageDialog *dialog;
    void show_msg();
    void on_response(int);
public:
    ErrorPopup();
    ~ErrorPopup();
    void on_message(const string& msg, gx_system::GxMsgType tp, bool plugged);
};

ErrorPopup::ErrorPopup()
    : msg(),
      active(false),
      dialog(0) {
}

ErrorPopup::~ErrorPopup() {
    delete dialog;
}

void ErrorPopup::on_message(const string& msg_, gx_system::GxMsgType tp, bool plugged) {
    if (plugged) {
	return;
    }
    if (tp == gx_system::kError) {
	msg = "";//"\n \n \n";
	msg += msg_;
	if (active) {
	    if (dialog) {
		dialog->set_message(msg);
	    }
	} else {
	    active = true;
	    show_msg();
	}
    }
}

void ErrorPopup::on_response(int) {
    delete dialog;
    dialog = 0;
    active = false;
}

void ErrorPopup::show_msg() {
    dialog = new Gtk::MessageDialog(msg, false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
    dialog->set_keep_above(true);
    //Gtk::VBox *ma = dialog->get_message_area(); // not in Gtkmm 0.20
    //FIXME: no comment :-)
    Gtk::VBox *ma = dynamic_cast<Gtk::VBox*>(
	*(++dynamic_cast<Gtk::HBox*>(
	      *dialog->get_vbox()->get_children().begin())->get_children().begin()));
    // add an alignment parent to the label widget inside the message area
    // should better define our own dialog instead of hacking MessageDialog...
    Gtk::Alignment *align = new Gtk::Alignment();
    align->show();
    dynamic_cast<Gtk::Label*>(*ma->get_children().begin())->reparent(*align);
    ma->pack_start(*manage(align));
    align->set_padding(50,20,0,10);
    Gtk::VBox *vbox = dynamic_cast<Gtk::VBox *>(dialog->get_child());
    vbox->set_redraw_on_allocate(true);
    vbox->signal_expose_event().connect(
	sigc::group(&gx_cairo::error_box_expose,GTK_WIDGET(vbox->gobj()),sigc::_1,(void*)0),false);
    dialog->set_title(_("GUITARIX ERROR"));
    dialog->signal_response().connect(
	sigc::mem_fun(*this, &ErrorPopup::on_response));
    dialog->show();
}

/****************************************************************
 ** class GxSplashBox
 ** show splash screen at start up
 */

class GxSplashBox {
 private:
    Gtk::Window m_window;
 public:
    explicit GxSplashBox();
    ~GxSplashBox();
};
GxSplashBox::~GxSplashBox() {}

GxSplashBox::GxSplashBox()
    : m_window(Gtk::WINDOW_TOPLEVEL) {
    m_window. set_redraw_on_allocate(true);
    m_window.set_app_paintable();
    m_window.signal_expose_event().connect(
        sigc::group(&gx_cairo::splash_expose,GTK_WIDGET(m_window.gobj()),
        sigc::_1,(void*)0),false);
    m_window.set_decorated(false);
    m_window.set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
    m_window.set_position(Gtk::WIN_POS_CENTER );
    m_window.set_default_size(280,80);
    m_window.show_all();
    while(Gtk::Main::events_pending())
        Gtk::Main::iteration(false); 
}

/****************************************************************
 ** main()
 */

#ifndef NDEBUG
void start_main(gx_system::CmdlineOptions& options, gx_engine::ParamMap& pmap);

int debug_display_glade(gx_system::CmdlineOptions& options, const string& fname, const string& rcfile) {
    gx_engine::parameter_map.set_init_values();
    Gtk::Window *w = 0;
    if (!fname.empty()) {
	gx_ui::GxUI ui;
	Glib::RefPtr<gx_gui::GxBuilder> bld = gx_gui::GxBuilder::create_from_file(fname, &ui);
	w = bld->get_first_window();
    }
    gx_ui::GxUI::updateAllGuis(true);
    gtk_rc_parse(rcfile.c_str());
    gtk_rc_reset_styles(gtk_settings_get_default());
    if (w) {
	Gtk::Main::run(*w);
	delete w;
    } else {
	start_main(options, gx_engine::parameter_map);
    }
    return 0;
}
#endif

namespace gx_engine {
//FIXME should not be global but needed for UI atm.
ParamMap parameter_map;
}

int main(int argc, char *argv[]) {
#ifdef DISABLE_NLS
// break
#elif IS_MACOSX
// break
#elif ENABLE_NLS
    bindtextdomain(GETTEXT_PACKAGE, LOCALEDIR);
    bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
    textdomain(GETTEXT_PACKAGE);
#endif

    try {
	// ----------------------- init basic subsystems ----------------------
	Glib::thread_init();
	Glib::init();
	Gxw::init();

	gx_system::CmdlineOptions options;
	Gtk::Main main(argc, argv, options);
    GxSplashBox * Splash =  new GxSplashBox();

	gx_system::GxExit::get_instance().signal_msg().connect(
	    sigc::ptr_fun(gx_gui::show_error_msg));  // show fatal errors in UI
	ErrorPopup popup;
	gx_system::Logger::get_logger().signal_message().connect(
	    sigc::mem_fun(popup, &ErrorPopup::on_message));

	options.process(argc, argv);

	// ---------------- Check for working user directory  -------------
	gx_preset::GxSettings::check_settings_dir(options);

	PosixSignals posixsig; // catch unix signals in special thread
	gx_engine::GxEngine engine(
	    options.get_plugin_dir(), gx_engine::parameter_map, gx_engine::get_group_table());

	// ------ initialize parameter list ------
	gx_engine::audio.register_parameter(gx_engine::parameter_map);
	gx_gui::guivar.register_gui_parameter(gx_engine::parameter_map);
	gx_engine::parameter_map.set_init_values();

	// ------ time measurement (debug) ------
#ifndef NDEBUG
	gx_system::add_time_measurement();

	if (argc > 1) {
	    if (!options.get_rcset().empty()) {
		gx_gui::gx_actualize_skin_index(options.skin, options.get_rcset());
	    }
	    string rcfile = options.get_style_filepath(
		"gx_head_" + options.skin.skin_list[gx_engine::audio.fskin] + ".rc");
	    return debug_display_glade(options, argv[1], rcfile);
	}
#endif
	// ----------------------- init GTK interface----------------------

	gx_gui::GxMainInterface gui(engine, options, gx_engine::parameter_map);
	gui.setup();
	// ----------------------- run GTK main loop ----------------------
	gx_ui::GxUI::updateAllGuis(true);
	gui.show();
    delete Splash;
	gui.run();
    } catch (const Glib::OptionError &e) {
	cerr << e.what() << endl;
	cerr << _("use \"guitarix -h\" to get a help text") << endl;
	return 1;
    } catch (const gx_system::GxFatalError &e) {
	cerr << e.what() << endl;
	return 1;
    }
    return 0;
}