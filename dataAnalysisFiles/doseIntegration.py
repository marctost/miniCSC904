#! /usr/bin/env python3
import os
import sys
import numpy as np
import datetime as dt
import matplotlib.pyplot as plt

##########################################################
filename = 'dose_new/20181127.txt' #input text file
#Put in the time values by hand (for now)
start = dt.datetime(2018, 11, 21, 0, 6, 29)
stop = dt.datetime(2018, 11, 21, 15, 47, 20)
##########################################################

cross_section = 13.4 #length of wire underneath source

readin = np.genfromtxt(filename, delimiter = '\t')
VSet = readin[:,1] #the voltage set on the CAEN (through LabWindows)
VMon = readin[:,2] #the voltage read out from the CAEN
IMon = readin[:,3] * 0.000001 #converts current from muAmp to Amps
print ("\nSuccessfully read in data")

#############################
## Doesn't work yet
#dataType = np.dtype([('time','S19'), ('vset', float), ('vmon',float), ('current', float)])
#readin = np.loadtxt(filename, dtype=dataType, delimiter = '\t')
#
#length = np.size(readin)
#Time = np.zeros(length,dtype='S19')
#VSet = np.zeros(length)
#VMon = np.zeros(length)
#IMon = np.zeros(length)
#
#for i in range(int(999*length/1000), length):
#    Time[i] = readin[i][0]
#    VSet[i] = readin[i][1]
#    VMon[i] = readin[i][2]
#    IMon[i] = readin[i][3] * 0.000001 #converts current from muAmp to Amps
#print ("\nSuccessfully read in data")
#############################

#start_time = input("Time of dose beginning in format YYYY-MM-DD HH:MM:SS: ")
#end_time = input("Time of dose ending in format YYYY-MM-DD HH:MM:SS: ")


#stop = dt.datetime(int(end_time[0:4]), int(end_time[5:7]), int(end_time[8:10]), int(end_time[11:13]), int(end_time[14:16]), int(end_time[17:19]))
#stop = dt.datetime((end_time[0:4]), (end_time[4:6]), (end_time[6:8]), (end_time[8:10]), (end_time[10:12]), (end_time[12:14]))


total_time = (stop - start).total_seconds()

print ("\n----- Total time is "+str(int(total_time))+"s")

tint = total_time / (len(readin)-1) #amount of time between each current reading

dose = 0
IAccept = []

for ind in range(0,len(readin)-1):
    if abs(VSet[ind] - VMon[ind]) <= 5.0 and abs(VSet[ind + 1] - VMon[ind + 1]) <= 5.0 and min(IMon[ind], IMon[ind + 1]) > 0:

        IAccept.append(IMon[ind])

        ### charge accumulated in each time bin is the average current multiplied by the delta-T between current readings.
        ### the 0.6666 factor is from assuming the current irradiates the chamber hole within a Gaussian profile,
        ### and integrating from mu-sigma to mu+sigma (for a Gaussian normalized to 1, this is about 2/3rds).
        dose += (0.6666) * tint * (IMon[ind] + IMon[ind + 1]) / 2

dose /= cross_section

IAcceptAvg = np.average(IAccept)
IAcceptDev = []
for i in range(len(IAccept)):
    IAcceptDev.append( (IAccept[i]-IAcceptAvg)*(IAccept[i]-IAcceptAvg) )
IAcceptSTDEV = np.sqrt(sum(IAcceptDev)/len(IAcceptDev))

print ("Average value (rounded) of accepted current values [A]: "+str( round(IAcceptAvg, 10) ))
print ("STDEV of accepted current values [A]: "+str( round(IAcceptSTDEV, 11) ))
print ("Accumulated charge [mC/cm]: "+str(dose*1000.))

#fig, ax1 = plt.subplots()
#ax1.set_xlabel('Time')
#ax1.set_ylabel('Current [A]')
#ax1.set_title(r'Irradiation Current')
##ax1.plot(IAcceptAvg,'r-')
#ax1.plot(Time, IMon)
#
#
#plt.show()

