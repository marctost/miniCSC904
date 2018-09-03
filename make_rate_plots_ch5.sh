#!/bin/bash

#Last argument is the number of runs
#Dark rates actually need "subtract" argument, b/c if "no", then the code
#adds the dark rates back to what you're plotting

# for chamber 5, 0% CF4 run
# irr 1: top (2,2) -- irradiated hole
# irr 2: top (3,1)
# ref 1: bottom (2,2)

### dark rates
root -q -l 'plot_rate.C("chamber5", "ALCT_dark", "subtract", "dark", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_dark", "subtract", "dark", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_dark", "subtract", "dark", "LCT",6)'

### unsubtracted rates
root -q -l 'plot_rate.C("chamber5", "ALCT_irr_1", "no", "irr_1", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_irr_2", "no", "irr_2", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_ref_1", "no", "ref_1", "ALCT",6)'

root -q -l 'plot_rate.C("chamber5", "CLCT_irr_1", "no", "irr_1", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_irr_2", "no", "irr_2", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_ref_1", "no", "ref_1", "CLCT",6)'

root -q -l 'plot_rate.C("chamber5", "LCT_irr_1", "no", "irr_1", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_irr_2", "no", "irr_2", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_ref_1", "no", "ref_1", "LCT",6)'

### BG subtracted rates
root -q -l 'plot_rate.C("chamber5", "ALCT_irr_1", "subtract", "irr_1", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_irr_2", "subtract", "irr_2", "ALCT",6)'
root -q -l 'plot_rate.C("chamber5", "ALCT_ref_1", "subtract", "ref_1", "ALCT",6)'

root -q -l 'plot_rate.C("chamber5", "CLCT_irr_1", "subtract", "irr_1", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_irr_2", "subtract", "irr_2", "CLCT",6)'
root -q -l 'plot_rate.C("chamber5", "CLCT_ref_1", "subtract", "ref_1", "CLCT",6)'

root -q -l 'plot_rate.C("chamber5", "LCT_irr_1", "subtract", "irr_1", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_irr_2", "subtract", "irr_2", "LCT",6)'
root -q -l 'plot_rate.C("chamber5", "LCT_ref_1", "subtract", "ref_1", "LCT",6)'
