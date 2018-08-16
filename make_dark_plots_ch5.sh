#!/bin/bash


root -l -q 'plot_DC_HVscan.C("chamber5","irr")'
root -l -q 'plot_DC_HVscan.C("chamber5","ref")'
root -l -q 'plot_DC_WPV.C("chamber5")'
