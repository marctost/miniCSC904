###README.md

Clone repository -----

git clone git@github.com:marctost/miniCSC904.git

-------------------------------------------------------

Analysis:
==========

Dose Integration -----
* dataAnalysisFiles/doseIntegration.py
* Change ‘filename’ to the input textfile to read in the current values
* Change ‘start’ and ‘stop’ to read in the start and stop times
* Accumulated charge value will print to STDOUT

-------------------------

Cluster Charge -----
* in dataAnalysisFiles/clusterCharge folder
* Copy the column of 27s RAW files to cluster_files.txt (make sure there is a newline character at the end of every line)
* Modify run_cluster.sh depending on the chamber (whether chamber 4 (GIF chamber) or chamber 5)
* ./run_cluster.sh, and it will create a file called "results_fit", you can use command+A command+C, then paste it to the spreadsheet using command+V

-------------------------

Strip-to-Strip Resistance -----
* dataAnalysisFiles/STSandDC.py
* Set chamber to True

-------------------------


Dark Current -----
* dataAnalysisFiles/STSandDC.py
* Set chamber to False

-------------------------------------------------------

Plotting:
==========

Trigger Rates -----
To create the excel spreadsheets:
* Open the spreadsheet called 'analysis_page_rate.xlsx'.
* Copy and paste the appropriate values underneath row 3.
* Excel will automatically generate everything below row 30.
* Copy 33-122, A-P, and paste it into 1A of the spreadsheet called 'final_numbers_rate'. (Note that you have to use 'paste special' and paste the values, otherwise it will throw up weird errors.)
* Convert the final_numbers spreadsheet into a .csv file.

To make the rate plots:
* Change the location of where you want the plots to go (line 132).
* Run the command: bash make_rate_plots.sh

-------------------------

Dark Current -----
* Open the spreadsheet called "analysis_page_darkCurrent.xlsx"
* Copy and paste the appropriate values below row 3 for all runs, make sure to include timing.
* Export to the spreadsheet into a .csv file, with the same name.
* Run the command: "bash make_dark_plots.sh"

------------------------

(Absolute) Gas Gain -----
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


