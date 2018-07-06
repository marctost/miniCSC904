###README.md

Set up clone -----

git clone git@github.com:marctost/miniCSC904.git

Make Rate Plots -----

To create the excel spreadsheets:
* Open the spreadsheet called 'analysis_page_rate.xlsx'.
* Copy and paste the appropriate values underneath row 3.
* Excel will automatically generate everything below row 30.
* Copy 33-122, A-P, and paste it into 1A of the spreadsheet called 'final_numbers_rate'. (Note that you have to use 'paste special' and paste the values, otherwise it will throw up weird errors.)
* Convert the final_numbers spreadsheet into a .csv file.

To make the rate plots:
* Change the location of where you want the plots to go (line 132).
* Run the command: bash make_rate_plots.sh

-----------------------------------------------

Cluster Charge Analysis -----
 * Copy the column of 27s files to cluster_files.txt
 * Modify run_cluster.sh depending on the chamber (the current setup is for GIF chamber)
 * ./run_cluster.sh, and it will create a file called "results_fit", you can use command+A command+C, then paste it to the spreadsheet using command+V
