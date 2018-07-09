#!/bin/bash

root -q -l 'rate_plot.C("ALCT_top", "no")'
root -q -l 'rate_plot.C("ALCT_bottom", "no")'

root -q -l 'rate_plot.C("CLCT_top", "no")'
root -q -l 'rate_plot.C("CLCT_bottom", "no")'

root -q -l 'rate_plot.C("LCT_top", "no")'
root -q -l 'rate_plot.C("LCT_bottom", "no")'


root -q -l 'rate_plot.C("ALCT_no", "subtract")'
root -q -l 'rate_plot.C("ALCT_top", "subtract")'
root -q -l 'rate_plot.C("ALCT_bottom", "subtract")'

root -q -l 'rate_plot.C("CLCT_no", "subtract")'
root -q -l 'rate_plot.C("CLCT_top", "subtract")'
root -q -l 'rate_plot.C("CLCT_bottom", "subtract")'

root -q -l 'rate_plot.C("LCT_no", "subtract")'
root -q -l 'rate_plot.C("LCT_top", "subtract")'
root -q -l 'rate_plot.C("LCT_bottom", "subtract")'
