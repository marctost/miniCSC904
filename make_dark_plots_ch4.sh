#!/bin/bash


root -l -q 'plot_DC_HVscan.C("chamber4","irr")'
root -l -q 'plot_DC_HVscan.C("chamber4","ref")'
root -l -q 'plot_DC_WPV.C("chamber4")'
python plot_DC_2D.py chamber4
