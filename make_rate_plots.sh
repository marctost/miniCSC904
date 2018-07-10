#!/bin/bash

root -q -l 'rate_plot.C("ALCT_top", "no", "ref", "ALCT")'
root -q -l 'rate_plot.C("ALCT_bottom", "no", "irr", "ALCT")'

root -q -l 'rate_plot.C("CLCT_top", "no", "ref", "CLCT")'
root -q -l 'rate_plot.C("CLCT_bottom", "no", "irr", "CLCT")'

root -q -l 'rate_plot.C("LCT_top", "no", "ref", "LCT")'
root -q -l 'rate_plot.C("LCT_bottom", "no", "irr", "LCT")'


root -q -l 'rate_plot.C("ALCT_dark", "subtract", "dark", "ALCT")'
root -q -l 'rate_plot.C("ALCT_top", "subtract", "ref", "ALCT")'
root -q -l 'rate_plot.C("ALCT_bottom", "subtract", "irr", "ALCT")'

root -q -l 'rate_plot.C("CLCT_dark", "subtract", "dark", "CLCT")'
root -q -l 'rate_plot.C("CLCT_top", "subtract", "ref", "CLCT")'
root -q -l 'rate_plot.C("CLCT_bottom", "subtract", "irr", "CLCT")'

root -q -l 'rate_plot.C("LCT_dark", "subtract", "dark", "LCT")'
root -q -l 'rate_plot.C("LCT_top", "subtract", "ref", "LCT")'
root -q -l 'rate_plot.C("LCT_bottom", "subtract", "irr", "LCT")'
