#!/bin/bash
  

root -l -q 'gas_gain_plot.C("irr", "no")'
root -l -q 'gas_gain_plot.C("irr", "source")'
root -l -q 'gas_gain_plot.C("ref", "no")'
root -l -q 'gas_gain_plot.C("ref", "source")'
