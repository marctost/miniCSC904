#!/bin/bash

#Last argument is the number of runs
#Dark rates actually need "subtract" argument, b/c if "no", then the code
#adds the dark rates back to what you're plotting

## dark rates
root -q -l 'plot_rate.C("chamber4", "ALCT_dark", "subtract", "dark", "ALCT",7)'
root -q -l 'plot_rate.C("chamber4", "CLCT_dark", "subtract", "dark", "CLCT",7)'
root -q -l 'plot_rate.C("chamber4", "LCT_dark", "subtract", "dark", "LCT",7)'

## unsubtracted rates
root -q -l 'plot_rate.C("chamber4", "ALCT_irr_1", "no", "irr_1", "ALCT",7)'
root -q -l 'plot_rate.C("chamber4", "ALCT_irr_2", "no", "irr_2", "ALCT",7)'
root -q -l 'plot_rate.C("chamber4", "ALCT_ref_1", "no", "ref_1", "ALCT",7)'
#root -q -l 'plot_rate.C("chamber4", "ALCT_ref_2", "no", "ref_2", "ALCT",7)'

root -q -l 'plot_rate.C("chamber4", "CLCT_irr_1", "no", "irr_1", "CLCT",7)'
root -q -l 'plot_rate.C("chamber4", "CLCT_irr_2", "no", "irr_2", "CLCT",7)'
root -q -l 'plot_rate.C("chamber4", "CLCT_ref_1", "no", "ref_1", "CLCT",7)'
#root -q -l 'plot_rate.C("chamber4", "CLCT_ref_2", "no", "ref_2", "CLCT",7)'

root -q -l 'plot_rate.C("chamber4", "LCT_irr_1", "no", "irr_1", "LCT",7)'
root -q -l 'plot_rate.C("chamber4", "LCT_irr_2", "no", "irr_2", "LCT",7)'
root -q -l 'plot_rate.C("chamber4", "LCT_ref_1", "no", "ref_1", "LCT",7)'
#root -q -l 'plot_rate.C("chamber4", "LCT_ref_2", "no", "ref_2", "LCT",7)'

## BG subtracted rates
root -q -l 'plot_rate.C("chamber4", "ALCT_irr_1", "subtract", "irr_1", "ALCT",7)'
root -q -l 'plot_rate.C("chamber4", "ALCT_irr_2", "subtract", "irr_2", "ALCT",7)'
root -q -l 'plot_rate.C("chamber4", "ALCT_ref_1", "subtract", "ref_1", "ALCT",7)'
#root -q -l 'plot_rate.C("chamber4", "ALCT_ref_2", "subtract", "ref_2", "ALCT",7)'

root -q -l 'plot_rate.C("chamber4", "CLCT_irr_1", "subtract", "irr_1", "CLCT",7)'
root -q -l 'plot_rate.C("chamber4", "CLCT_irr_2", "subtract", "irr_2", "CLCT",7)'
root -q -l 'plot_rate.C("chamber4", "CLCT_ref_1", "subtract", "ref_1", "CLCT",7)'
#root -q -l 'plot_rate.C("chamber4", "CLCT_ref_2", "subtract", "ref_2", "CLCT",7)'

root -q -l 'plot_rate.C("chamber4", "LCT_irr_1", "subtract", "irr_1", "LCT",7)'
root -q -l 'plot_rate.C("chamber4", "LCT_irr_2", "subtract", "irr_2", "LCT",7)'
root -q -l 'plot_rate.C("chamber4", "LCT_ref_1", "subtract", "ref_1", "LCT",7)'
#root -q -l 'plot_rate.C("chamber4", "LCT_ref_2", "subtract", "ref_2", "LCT",7)'

