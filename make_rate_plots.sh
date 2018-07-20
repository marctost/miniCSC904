#!/bin/bash

root -q -l 'rate_plot.C("ALCT_top", "no", "irr", "ALCT")'
root -q -l 'rate_plot.C("ALCT_bottom", "no", "ref", "ALCT")'
root -q -l 'rate_plot.C("ALCT_top_irr", "no", "irr_irr", "ALCT")'

root -q -l 'rate_plot.C("CLCT_top", "no", "irr", "CLCT")'
root -q -l 'rate_plot.C("CLCT_bottom", "no", "ref", "CLCT")'
root -q -l 'rate_plot.C("CLCT_top_irr", "no", "irr_irr", "CLCT")'

root -q -l 'rate_plot.C("LCT_top", "no", "irr", "LCT")'
root -q -l 'rate_plot.C("LCT_bottom", "no", "ref", "LCT")'
root -q -l 'rate_plot.C("LCT_top_irr", "no", "irr_irr", "LCT")'


root -q -l 'rate_plot.C("ALCT_dark", "subtract", "dark", "ALCT")'
root -q -l 'rate_plot.C("ALCT_top", "subtract", "irr", "ALCT")'
root -q -l 'rate_plot.C("ALCT_bottom", "subtract", "ref", "ALCT")'
root -q -l 'rate_plot.C("ALCT_top_irr", "subtract", "irr_irr", "ALCT")'

root -q -l 'rate_plot.C("CLCT_dark", "subtract", "dark", "CLCT")'
root -q -l 'rate_plot.C("CLCT_top", "subtract", "irr", "CLCT")'
root -q -l 'rate_plot.C("CLCT_bottom", "subtract", "ref", "CLCT")'
root -q -l 'rate_plot.C("CLCT_top_irr", "subtract", "irr_irr", "CLCT")'

root -q -l 'rate_plot.C("LCT_dark", "subtract", "dark", "LCT")'
root -q -l 'rate_plot.C("LCT_top", "subtract", "irr", "LCT")'
root -q -l 'rate_plot.C("LCT_bottom", "subtract", "ref", "LCT")'
root -q -l 'rate_plot.C("LCT_top_irr", "subtract", "irr_irr", "LCT")'
