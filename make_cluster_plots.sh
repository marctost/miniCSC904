#!/bin/bash
  

root -l -q 'cluster_charge_plot.C("cluster_with_norm", "ref")'
root -l -q 'cluster_charge_plot.C("cluster_no_norm", "no")'

