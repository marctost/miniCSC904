#!/bin/bash

root -q -l 'rate_plot.C("ALCT_no")'
root -q -l 'rate_plot.C("ALCT_top")'
root -q -l 'rate_plot.C("ALCT_bottom")'

root -q -l 'rate_plot.C("CLCT_no")'
root -q -l 'rate_plot.C("CLCT_top")'
root -q -l 'rate_plot.C("CLCT_bottom")'

root -q -l 'rate_plot.C("LCT_no")'
root -q -l 'rate_plot.C("LCT_top")'
root -q -l 'rate_plot.C("LCT_bottom")'
