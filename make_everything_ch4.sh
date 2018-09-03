#!/bin/bash


bash make_rate_plots_ch4.sh
bash make_dark_plots_ch4.sh
bash make_cluster_plots_ch4.sh
root -l -q 'plot_strip.C("chamber4")'
root -l -q 'plot_gas_gain.C("chamber4")'
