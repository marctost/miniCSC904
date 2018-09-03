#!/bin/bash
  
root -l -q 'plot_cluster_charge.C("chamber4","cluster_no_norm", "no")'
root -l -q 'plot_cluster_charge.C("chamber4","cluster_with_norm", "ref")'
root -l -q 'plot_cluster_charge.C("chamber4","cluster_with_norm", "irr")'
