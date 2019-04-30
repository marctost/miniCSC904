#!/bin/bash

#Last argument is the number of runs
#Dark rates actually need "subtract" argument, b/c if "no", then the code
#adds the dark rates back to what you're plotting

# for chamber 5, 0% CF4 run
# irr 1: top (2,2) -- irradiated hole
# irr 2: top (3,1)
# ref 1: bottom (2,2)

root -q -l 'plot_rate.C("chamber5", "LCT_irr_1", "subtract", "irr_1", "LCT",9)'
root -q -l 'plot_rate.C("chamber5", "LCT_irr_2", "subtract", "irr_2", "LCT",9)'
root -q -l 'plot_rate.C("chamber5", "LCT_ref_1", "subtract", "ref_1", "LCT",9)'
