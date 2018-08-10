#!/bin/bash


bash make_rate_plots_ch5.sh
bash make_dark_plots_ch5.sh
bash make_cluster_plots_ch5.sh
root -l -q 'plot_strip.C("chamber5")'
root -l -q 'plot_gas_gain.C("chamber5")'
