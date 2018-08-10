#!/bin/bash

root -q -l 'plot_rate.C("chamber5", "ALCT_top", "no", "irr", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_bottom", "no", "ref", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_top_irr", "no", "irr_irr", "ALCT",6)'

root -q -l 'plot_rate.C("chamber5", "CLCT_top", "no", "irr", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_bottom", "no", "ref", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_top_irr", "no", "irr_irr", "CLCT",6)'

root -q -l 'plot_rate.C("chamber5", "LCT_top", "no", "irr", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_bottom", "no", "ref", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_top_irr", "no", "irr_irr", "LCT",6)'


root -q -l 'plot_rate.C("chamber5", "ALCT_dark", "subtract", "dark", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_top", "subtract", "irr", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_bottom", "subtract", "ref", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_top_irr", "subtract", "irr_irr", "ALCT",6)'

root -q -l 'plot_rate.C("chamber5", "CLCT_dark", "subtract", "dark", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_top", "subtract", "irr", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_bottom", "subtract", "ref", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_top_irr", "subtract", "irr_irr", "CLCT",6)'

root -q -l 'plot_rate.C("chamber5", "LCT_dark", "subtract", "dark", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_top", "subtract", "irr", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_bottom", "subtract", "ref", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_top_irr", "subtract", "irr_irr", "LCT",6)'
