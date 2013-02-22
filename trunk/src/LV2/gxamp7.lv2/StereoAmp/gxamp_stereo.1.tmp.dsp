#
# Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
# --------------------------------------------------------------------------
#


@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix bufsz: <http://lv2plug.in/ns/ext/buf-size#> .
@prefix atom:  <http://lv2plug.in/ns/ext/atom#> .
@prefix urid:  <http://lv2plug.in/ns/ext/urid#> .
@prefix opt:  <http://lv2plug.in/ns/ext/options#> .
@prefix guiext: <http://lv2plug.in/ns/extensions/ui#>.
@prefix work:  <http://lv2plug.in/ns/ext/worker#> .

<http://guitarix.sourceforge.net#me>
	a foaf:Person ;
	foaf:name "Hermann Meyer" ;
	foaf:mbox <mailto:brummer@web.de> ;
	rdfs:seeAlso <http://guitarix.sourceforge.net> .

<http://guitarix.sourceforge.net/plugins/gxamp>
	a doap:Project ;
	doap:maintainer <http://guitarix.sourceforge.net#me> ;
	doap:name "GxAmplifier" .

<http://guitarix.sourceforge.net/plugins/gxamp#12ax7_stereo>
    a lv2:Plugin ,
        lv2:AmplifierPlugin ;
    doap:maintainer <http://guitarix.sourceforge.net#me> ;
    doap:name "GxAmplifier stereo";
    doap:license <http://opensource.org/licenses/isc> ;
    lv2:project <http://guitarix.sourceforge.net/plugins/gxamp> ;
    lv2:optionalFeature lv2:hardRTCapable ;
    lv2:requiredFeature urid:map ,
        bufsz:boundedBlockLength ,
        work:schedule ;
    bufsz:minBlockLength 64 ;
    bufsz:maxBlockLength 8192 ;
    lv2:extensionData work:interface ;

  guiext:ui <http://guitarix.sourceforge.net/plugins/gxamp#gui>;
  
    lv2:port [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 0 ;
        lv2:symbol "fslider0_" ;
        lv2:name "MasterGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 1 ;
        lv2:symbol "fslider1_" ;
        lv2:name "PreGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 2 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Distortion";
        lv2:default 20.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 100.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 3 ;
        lv2:symbol "fslider3_" ;
        lv2:name "Drive";
        lv2:default 0.25 ;
        lv2:minimum 0.01 ;
        lv2:maximum 1.0 ;
    ] ,[
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 4 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Middle";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 5 ;
        lv2:symbol "fslider1_" ;
        lv2:name "Bass";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 6 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Treble";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 7 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Cabinet";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 8 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Presence";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 9 ;
        lv2:symbol "control" ;
        lv2:name "Control"
    ] , [
        a lv2:OutputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 10 ;
        lv2:symbol "notify" ;
        lv2:name "Notify"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 11 ;
        lv2:symbol "out" ;
        lv2:name "Out"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 12 ;
        lv2:symbol "in" ;
        lv2:name "in"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 13 ;
        lv2:symbol "out1" ;
        lv2:name "Out1"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 14 ;
        lv2:symbol "in1" ;
        lv2:name "in1"
    ] .

<http://guitarix.sourceforge.net/plugins/gxamp#12AT7_stereo>
    a lv2:Plugin ,
        lv2:AmplifierPlugin ;
    doap:maintainer <http://guitarix.sourceforge.net#me> ;
    doap:name "GxAmplifier-II stereo";
    doap:license <http://opensource.org/licenses/isc> ;
    lv2:project <http://guitarix.sourceforge.net/plugins/gxamp> ;
    lv2:optionalFeature lv2:hardRTCapable ;
    lv2:requiredFeature urid:map ,
        bufsz:boundedBlockLength ,
        work:schedule ;
    bufsz:minBlockLength 64 ;
    bufsz:maxBlockLength 8192 ;
    lv2:extensionData work:interface ;

  guiext:ui <http://guitarix.sourceforge.net/plugins/gxamp#gui>;
  
    lv2:port [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 0 ;
        lv2:symbol "fslider0_" ;
        lv2:name "MasterGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 1 ;
        lv2:symbol "fslider1_" ;
        lv2:name "PreGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 2 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Distortion";
        lv2:default 20.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 100.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 3 ;
        lv2:symbol "fslider3_" ;
        lv2:name "Drive";
        lv2:default 0.25 ;
        lv2:minimum 0.01 ;
        lv2:maximum 1.0 ;
    ] ,[
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 4 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Middle";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 5 ;
        lv2:symbol "fslider1_" ;
        lv2:name "Bass";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 6 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Treble";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 7 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Cabinet";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 8 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Presence";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 9 ;
        lv2:symbol "control" ;
        lv2:name "Control"
    ] , [
        a lv2:OutputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 10 ;
        lv2:symbol "notify" ;
        lv2:name "Notify"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 11 ;
        lv2:symbol "out" ;
        lv2:name "Out"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 12 ;
        lv2:symbol "in" ;
        lv2:name "in"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 13 ;
        lv2:symbol "out1" ;
        lv2:name "Out1"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 14 ;
        lv2:symbol "in1" ;
        lv2:name "in1"
    ] .

<http://guitarix.sourceforge.net/plugins/gxamp#6C16_stereo>
    a lv2:Plugin ,
        lv2:AmplifierPlugin ;
    doap:maintainer <http://guitarix.sourceforge.net#me> ;
    doap:name "GxAmplifier-III stereo";
    doap:license <http://opensource.org/licenses/isc> ;
    lv2:project <http://guitarix.sourceforge.net/plugins/gxamp> ;
    lv2:optionalFeature lv2:hardRTCapable ;
    lv2:requiredFeature urid:map ,
        bufsz:boundedBlockLength ,
        work:schedule ;
    bufsz:minBlockLength 64 ;
    bufsz:maxBlockLength 8192 ;
    lv2:extensionData work:interface ;

  guiext:ui <http://guitarix.sourceforge.net/plugins/gxamp#gui>;
  
    lv2:port [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 0 ;
        lv2:symbol "fslider0_" ;
        lv2:name "MasterGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 1 ;
        lv2:symbol "fslider1_" ;
        lv2:name "PreGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 2 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Distortion";
        lv2:default 20.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 100.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 3 ;
        lv2:symbol "fslider3_" ;
        lv2:name "Drive";
        lv2:default 0.25 ;
        lv2:minimum 0.01 ;
        lv2:maximum 1.0 ;
    ] ,[
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 4 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Middle";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 5 ;
        lv2:symbol "fslider1_" ;
        lv2:name "Bass";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 6 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Treble";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 7 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Cabinet";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 8 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Presence";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 9 ;
        lv2:symbol "control" ;
        lv2:name "Control"
    ] , [
        a lv2:OutputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 10 ;
        lv2:symbol "notify" ;
        lv2:name "Notify"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 11 ;
        lv2:symbol "out" ;
        lv2:name "Out"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 12 ;
        lv2:symbol "in" ;
        lv2:name "in"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 13 ;
        lv2:symbol "out1" ;
        lv2:name "Out1"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 14 ;
        lv2:symbol "in1" ;
        lv2:name "in1"
    ] .

<http://guitarix.sourceforge.net/plugins/gxamp#6V6_stereo>
    a lv2:Plugin ,
        lv2:AmplifierPlugin ;
    doap:maintainer <http://guitarix.sourceforge.net#me> ;
    doap:name "GxAmplifier-IV stereo";
    doap:license <http://opensource.org/licenses/isc> ;
    lv2:project <http://guitarix.sourceforge.net/plugins/gxamp> ;
    lv2:optionalFeature lv2:hardRTCapable ;
    lv2:requiredFeature urid:map ,
        bufsz:boundedBlockLength ,
        work:schedule ;
    bufsz:minBlockLength 64 ;
    bufsz:maxBlockLength 8192 ;
    lv2:extensionData work:interface ;

  guiext:ui <http://guitarix.sourceforge.net/plugins/gxamp#gui>;
  
    lv2:port [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 0 ;
        lv2:symbol "fslider0_" ;
        lv2:name "MasterGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 1 ;
        lv2:symbol "fslider1_" ;
        lv2:name "PreGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 2 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Distortion";
        lv2:default 20.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 100.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 3 ;
        lv2:symbol "fslider3_" ;
        lv2:name "Drive";
        lv2:default 0.25 ;
        lv2:minimum 0.01 ;
        lv2:maximum 1.0 ;
    ] ,[
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 4 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Middle";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 5 ;
        lv2:symbol "fslider1_" ;
        lv2:name "Bass";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 6 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Treble";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 7 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Cabinet";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 8 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Presence";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 9 ;
        lv2:symbol "control" ;
        lv2:name "Control"
    ] , [
        a lv2:OutputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 10 ;
        lv2:symbol "notify" ;
        lv2:name "Notify"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 11 ;
        lv2:symbol "out" ;
        lv2:name "Out"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 12 ;
        lv2:symbol "in" ;
        lv2:name "in"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 13 ;
        lv2:symbol "out1" ;
        lv2:name "Out1"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 14 ;
        lv2:symbol "in1" ;
        lv2:name "in1"
    ] .

<http://guitarix.sourceforge.net/plugins/gxamp#6DJ8_stereo>
    a lv2:Plugin ,
        lv2:AmplifierPlugin ;
    doap:maintainer <http://guitarix.sourceforge.net#me> ;
    doap:name "GxAmplifier-V stereo";
    doap:license <http://opensource.org/licenses/isc> ;
    lv2:project <http://guitarix.sourceforge.net/plugins/gxamp> ;
    lv2:optionalFeature lv2:hardRTCapable ;
    lv2:requiredFeature urid:map ,
        bufsz:boundedBlockLength ,
        work:schedule ;
    bufsz:minBlockLength 64 ;
    bufsz:maxBlockLength 8192 ;
    lv2:extensionData work:interface ;

  guiext:ui <http://guitarix.sourceforge.net/plugins/gxamp#gui>;
  
    lv2:port [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 0 ;
        lv2:symbol "fslider0_" ;
        lv2:name "MasterGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 1 ;
        lv2:symbol "fslider1_" ;
        lv2:name "PreGain";
        lv2:default -15.0 ;
        lv2:minimum -20.0 ;
        lv2:maximum 20.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 2 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Distortion";
        lv2:default 20.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 100.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 3 ;
        lv2:symbol "fslider3_" ;
        lv2:name "Drive";
        lv2:default 0.25 ;
        lv2:minimum 0.01 ;
        lv2:maximum 1.0 ;
    ] ,[
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 4 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Middle";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 5 ;
        lv2:symbol "fslider1_" ;
        lv2:name "Bass";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] ,     [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 6 ;
        lv2:symbol "fslider2_" ;
        lv2:name "Treble";
        lv2:default 0.5 ;
        lv2:minimum 0.0 ;
        lv2:maximum 1.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 7 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Cabinet";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            lv2:ControlPort ;
        lv2:index 8 ;
        lv2:symbol "fslider0_" ;
        lv2:name "Presence";
        lv2:default 10.0 ;
        lv2:minimum 1.0 ;
        lv2:maximum 20.0 ;
    ] , [
        a lv2:InputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 9 ;
        lv2:symbol "control" ;
        lv2:name "Control"
    ] , [
        a lv2:OutputPort ,
            atom:AtomPort ;
        atom:bufferType atom:Sequence ;
        atom:supports <http://lv2plug.in/ns/ext/patch#Message> ;
        lv2:index 10 ;
        lv2:symbol "notify" ;
        lv2:name "Notify"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 11 ;
        lv2:symbol "out" ;
        lv2:name "Out"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 12 ;
        lv2:symbol "in" ;
        lv2:name "in"
    ] , [
        a lv2:AudioPort ,
            lv2:OutputPort ;
        lv2:index 13 ;
        lv2:symbol "out1" ;
        lv2:name "Out1"
    ] , [
        a lv2:AudioPort ,
            lv2:InputPort ;
        lv2:index 14 ;
        lv2:symbol "in1" ;
        lv2:name "in1"
    ] .

<http://guitarix.sourceforge.net/plugins/gxamp#gui>
  a guiext:GtkUI;
  guiext:binary <gxamp_gui_stereo.so>;
  guiext:requiredFeature guiext:makeResident;
  lv2:extensionData work:interface ;
  guiext:portNotification [
        guiext:plugin <http://guitarix.sourceforge.net/plugins/gxamp#12ax7>;
        lv2:symbol "notify" ;
        guiext:notifyType atom:Blank
  ] , [
        guiext:plugin <http://guitarix.sourceforge.net/plugins/gxamp#12AT7>;
        lv2:symbol "notify" ;
        guiext:notifyType atom:Blank
  ] , [
        guiext:plugin <http://guitarix.sourceforge.net/plugins/gxamp#6C16>;
        lv2:symbol "notify" ;
        guiext:notifyType atom:Blank
  ] , [
        guiext:plugin <http://guitarix.sourceforge.net/plugins/gxamp#6V6>;
        lv2:symbol "notify" ;
        guiext:notifyType atom:Blank
  ] .
