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


-------------------------

Dark Current plotting-----
* Open the spreadsheet called "analysis_page_darkCurrent.xlsx"
* Copy and paste the appropriate values below row 3 for all runs, make sure to include timing.
* Export to the spreadsheet into a .csv file, with the same name.
* Run the command: "bash make_dark_plots.sh"


------------------------

Gas gain plotting ------
* Open spreadsheet called "analysis_page_gasGain.xlsx"
* Copy the appropriate values into/below row 4
* Convert to .csv file with same name.
* Run the command: "bash make_gas_plots.sh"


---------------------

strip-to-strip Plotting ------
* Open spreadsheet called "analysis_page_strip.xlsx"
* Copy the appropriate values into/below row 4, include timing.
* Convert to .csv file with same name.
* Run the command: "bash make_strip_plots.sh"


------------------

Cluster charge plotting --------
* Open spreadsheet called "analysis_page_cluster_charge.xlsx"
* Copy the appropriate values into/below row 3. Make sure to follow timing instructions (i.e. add two hours). 
    * Also note here that you cannot just copy and paste entire columns, it is important that each value lines up with its corresponding hole. 
    * Also, the program doesn't like things formated like: (2,1). So avoid that.
* Convert to .csv file with same name.
* Run "bash make_cluster_plots.sh"


