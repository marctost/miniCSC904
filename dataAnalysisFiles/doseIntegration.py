# -*- coding: utf-8 -*-
"""
Created on Thu May  4 20:06:03 2017

@author: Jameson, Ota - fix to the calculation
"""

import numpy as np
import datetime as dt

filename = 'dosefile.txt' #input text file
cross_section = 13.4 #precalculated value (related to cross section)

readin = np.genfromtxt(filename, delimiter = '\t')

VSet = readin[:,1] #the voltage set on the CAEN (through LabWindows)
VMon = readin[:,2] #the current read out from CAEN
IMon = readin[:,3] * 0.000001 #converts current from muAmp to Amps

#start_time = input("Time of dose beginning in format YYYY-MM-DD HH:MM:SS: ")
#end_time = input("Time of dose ending in format YYYY-MM-DD HH:MM:SS: ")

#Put in the time values by hand (for now)
start = dt.datetime(2018, 01, 22, 14, 02, 18)
#stop = dt.datetime(int(end_time[0:4]), int(end_time[5:7]), int(end_time[8:10]), int(end_time[11:13]), int(end_time[14:16]), int(end_time[17:19]))
#stop = dt.datetime((end_time[0:4]), (end_time[4:6]), (end_time[6:8]), (end_time[8:10]), (end_time[10:12]), (end_time[12:14]))
stop = dt.datetime(2018, 02, 04, 11, 25, 28)

total_time = (stop - start).total_seconds()

print "Total time is "+str(total_time)+" seconds"

tint = total_time / (len(readin)-1) #amount of time between each current reading

dose = 0

for ind in range(0,len(readin)-1):
    if abs(VSet[ind] - VMon[ind]) <= 5.0 and abs(VSet[ind + 1] - VMon[ind + 1]) <= 5.0 and min(IMon[ind], IMon[ind + 1]) > 0:

        ### charge accumulated in each time bin is the average current multiplied by the delta-T between current readings.
        ### the 0.6666 factor is from assuming the current irradiates the chamber hole within a Gaussian profile,
        ### and integrating from mu-sigma to mu+sigma (for a Gaussian normalized to 1, this is about 2/3rds).
        dose += (0.6666) * tint * (IMon[ind] + IMon[ind + 1]) / 2

dose /= cross_section

print "Accumulated charge (dose): "+str(dose)

