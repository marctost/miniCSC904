#!/bin/bash

root -q -l 'rate_plot.C("ALCT_top", "no", "irr", "ALCT",6)'
root -q -l 'rate_plot.C("ALCT_bottom", "no", "ref", "ALCT",6)'
root -q -l 'rate_plot.C("ALCT_top_irr", "no", "irr_irr", "ALCT",6)'

root -q -l 'rate_plot.C("CLCT_top", "no", "irr", "CLCT",6)'
root -q -l 'rate_plot.C("CLCT_bottom", "no", "ref", "CLCT",6)'
root -q -l 'rate_plot.C("CLCT_top_irr", "no", "irr_irr", "CLCT",6)'

root -q -l 'rate_plot.C("LCT_top", "no", "irr", "LCT",6)'
root -q -l 'rate_plot.C("LCT_bottom", "no", "ref", "LCT",6)'
root -q -l 'rate_plot.C("LCT_top_irr", "no", "irr_irr", "LCT",6)'


root -q -l 'rate_plot.C("ALCT_dark", "subtract", "dark", "ALCT",6)'
root -q -l 'rate_plot.C("ALCT_top", "subtract", "irr", "ALCT",6)'
root -q -l 'rate_plot.C("ALCT_bottom", "subtract", "ref", "ALCT",6)'
root -q -l 'rate_plot.C("ALCT_top_irr", "subtract", "irr_irr", "ALCT",6)'

root -q -l 'rate_plot.C("CLCT_dark", "subtract", "dark", "CLCT",6)'
root -q -l 'rate_plot.C("CLCT_top", "subtract", "irr", "CLCT",6)'
root -q -l 'rate_plot.C("CLCT_bottom", "subtract", "ref", "CLCT",6)'
root -q -l 'rate_plot.C("CLCT_top_irr", "subtract", "irr_irr", "CLCT",6)'

root -q -l 'rate_plot.C("LCT_dark", "subtract", "dark", "LCT",6)'
root -q -l 'rate_plot.C("LCT_top", "subtract", "irr", "LCT",6)'
root -q -l 'rate_plot.C("LCT_bottom", "subtract", "ref", "LCT",6)'
root -q -l 'rate_plot.C("LCT_top_irr", "subtract", "irr_irr", "LCT",6)'
