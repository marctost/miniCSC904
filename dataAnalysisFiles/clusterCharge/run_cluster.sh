#!/bin/bash
# This code contains the SSH password, so be careful when sharing.
# Make sure there is a newline character at the end of every line in "cluster_files.txt"

# To keep thing clean in a dangerous way
# rm *.png
# rm *.root

# define a few path and names
path_dir="localuser@emume42.cern.ch:/data/cscme42/current/Tests_results/Test_27_Cosmics"
# Chamber 5
# holes=("tNS" "t22" "t32" "t21" "t31" "b22" "b31")
# Chamber GIF
holes=("tNS" "t11" "t12" "t21" "t22" "t31" "t32" "b11" "b12" "b21" "b22" "b31" "b32")

# read cluster charge file names
file_clusters="cluster_files.txt"
file_times=()
while IFS= read -r line; do
   file_raw=($(echo $line | cut -d '/' -f 5))
   file_unraw=($(echo $file_raw | cut -d '.' -f 1))
   file_times+=($file_unraw)
done<"$file_clusters"

# --------------------------------------------------

# Decide whether or not to include No Source ----
#following line detects the number of ROOT files
len_files=${#file_times[@]}

# Chamber 5:
# switch_layer=$((len_files-2))
# [ $switch_layer -eq 4 ] && holes=(${holes[@]:1})
# Chamber GIF:
# If 12 root files copied, code will assume there is no No_Source file;
# if 13 root files, code will assume the first file is the No_Source one
switch_layer=$((len_files-6))
[ $switch_layer -eq 6 ] && holes=(${holes[@]:1})

# --------------------------------------------------

# Write results to text file ----
[ -f results_fit.txt ] && rm results_fit.txt
for (( i=0; i<$len_files; i++ )); do
   # May not work without sleep
   sleep .5
   sshpass -p "\$LocaluseR\$" scp ${path_dir}/${file_times[i]}.root .

   # Switch layer (works only for Chamber 5 or GIF)
   [ $i -lt $switch_layer ] && layer=6 || layer=5
   root -l -q "FitClusterC.c(\"${file_times[i]}.root\", $layer)"

   mv ${file_times[i]}.png plot_${holes[i]}.png
done
