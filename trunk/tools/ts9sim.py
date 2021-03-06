# -*- coding: utf-8 -*-
from pylab import *
from scipy.optimize import brentq
import sys

class PlotManager(object):
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.i = 1

    def __call__(self):
        subplot(self.r,self.c,self.i)
        self.i += 1

def f(D, x, d):
    Is = 10 * 1e-12
    mUt = 30 * 1e-3
    R2 = 51000 + 500000 * d
    return (x+D)/R2 + Is * (exp(D/mUt) - exp(-D/mUt))

def F(x, d):
    ret = brentq(f, -0.6, 0.6, args=(x, d))
    return ret

def xf(v):
    return v / (3.0 + v)

def fx(v):
    return 3.0 * v / (1.0 - v)
    
def show_diff(pm):
    from ts9func import ts9func
    d = 1.0
    pm()
    x = linspace(0, 100, 2000)
    y = vectorize(lambda v: F(v, d))(x)
    y1 = vectorize(lambda v: ts9func(v))(x)
    plot(x, y-y1, "-")
    pm()
    x = linspace(0, 2.5, 200)
    y = vectorize(lambda v: F(v, d))(x)
    y1 = vectorize(ts9func)(x)
    plot(x, y-y1, "-")

def format(v):
    # python2 str(float) compatible formatting function
    # produces same output for the table as the old python2 version
    s = "%.12g" % v
    if "." not in s:
        s += ".0";
    return s

def write_ftube_table(Vi, Vp):
    """write C source"""
    sys.stdout.write('\t%g,%g,%g,%d, {' % (Vi[0], Vi[-1], (len(Vi)-1)/(Vi[-1]-Vi[0]), len(Vi)))
    s = ""
    for i, v in enumerate(Vi):
        if i % 5 == 0:
            sys.stdout.write(s+"\n\t")
            s = ""
        sys.stdout.write(s+format(Vp[i]))
        s = ","
    sys.stdout.write("\n\t}")

def make_table():
    Vi = linspace(xf(0.0),xf(100.0),100)
    sys.stdout.write("// file generated by tools/ts9sim.py -- do not modify manually\n")
    sys.stdout.write("\n")
    sys.stdout.write("static table1d_imp<%d> ts9table __rt_data = {\n" % len(Vi))
    Vp = vectorize(lambda v: F(fx(v), 1.0))(Vi)
    write_ftube_table(Vi, Vp)
    sys.stdout.write("\n};\n")

if len(sys.argv) == 2:
    make_table()
else:
    pm = PlotManager(2,1)
    show_diff(pm)
    show()
