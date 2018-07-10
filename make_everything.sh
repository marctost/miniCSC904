#!/bin/bash


bash make_rate_plots.sh
bash make_dark_plots.sh
bash make_gas_plots.sh
bash make_cluster_plots.sh
root -l -q strip_plot.C
