#! /usr/bin/env python3

import os
import sys
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

### Note: useful for trials with very small currents whose "stable values" may fluctuate a lot
### i.e. pedestal values for trials with Sr-90 source, as these are very sensitive measurements
### Analysis strategy is to cut off the exponential tail at the beginning
### and understand how the average value fluctuates from stable section to stable section

## Tweak ndivisions such that the division of sections makes sense
## The last current section should be a well-defined single section

#########################################################
filename = 'run6dc_GIFchamber/Dark_current_Ref_NoS_4000V.txt' #input text file
ndivisions = 1 #This value is meant to be tweaked to make how we divide the current into sections make sense
plotLine = True
#########################################################

points = 1000000
dt = np.dtype([('time','S19'), ('current', float)])

#Read in the input text file
#First value is time, second is current
readin = np.loadtxt(filename,dtype=dt,delimiter='\t')
length = np.size(readin)
time = np.zeros(length,dtype='S19')
amps = np.zeros(length)
for i in range(0,length):
    time[i] = readin[i][0]
    amps[i] = readin[i][1]

# --------------------------------------------------

#Note: This section calculates the avg and stdev for all of the current values, so we can use it for a statistical error
# Everything outside of 3sigma is reasonable to filter out
#First take the average of all values and find the spread in this (Gaussian) distribution
avg = np.average(amps)
stdev = np.sqrt(np.average((amps - avg) ** 2))

#Take all "amps" values such that the deviation from the average is within 3 sigma
included = np.abs(amps - avg) < (3 * stdev)
filteravg = np.average(amps[included])
filterstdev = np.sqrt(np.average((amps[included] - avg) ** 2))

#Acceptance efficiency
accept_rate = np.size(amps[included]) / np.size(amps)

#Draw lines for the upper and lower limits of the current values within the filtered range
#Keeping everything within +- 3 sigma gives about 99% of all of the distributed current values
uplim = np.ones(length) * (avg + 3 * stdev)
lolim = np.ones(length) * (avg - 3 * stdev)

# --------------------------------------------------

#Do all the statistics within the filtered values
ampsIncluded = amps[included]
lengthIncluded = length = np.size(ampsIncluded)

#Now divide the current readout into sections and find the average in each section
lengthSmall = int(lengthIncluded/ndivisions)

ampSegList = []
xSegList = []
avgList = []
avgLines = []

for i in range(0,ndivisions):
    ampSeg = np.zeros(lengthSmall)
    xSeg = np.zeros(lengthSmall)
    for j in range(0, lengthSmall):
        ampSeg[j] = ampsIncluded[j+(i*lengthSmall)]
        xSeg[j] = j+(i*lengthSmall)
    ampSegList.append(ampSeg)
    xSegList.append(xSeg)
    avgList.append(np.average(ampSeg))
    avgLines.append(np.ones(lengthSmall) * np.average(ampSeg))

deviationsList = []
#Find the deviation of the average in each section from the average overall
for i in range(0,ndivisions):
    #Find the deviation of the average in each section from the average overall
#    deviationsList.append(np.fabs(avgList[i]-filteravg))
    # -- OR --
    #Find the deviation of the average in each section from the last stable section
    #(the one that we decided was good enough to stop the measurement)
    deviationsList.append(np.fabs(avgList[i]-avgList[ndivisions-1]))

maxDeviation = max(deviationsList)

## Total error is stat. and syst. added in quadrature
## Take max deviation of a section average from the last section average as the error in biasing the result when stopping the measurement
totalError = np.sqrt((maxDeviation*maxDeviation)+(filterstdev*filterstdev))

# --------------------------------------------------

colorList = ['#800000', '#ff0000', '#ff9900', '#ffff00', '#66ff33', '#00ffff', '#0000ff', '#9900cc', '#ff00ff', '#ffccff']

fig, ax1 = plt.subplots()
ax1.set_xlabel('Point Number')
ax1.set_ylabel('Current (A)', color='black')
ax1.set_title(r'Dark Current')
#ax1.plot(amps)
ax1.plot(uplim,'r-')
ax1.plot(lolim,'r-')

### Plot currents in segments
for i in range(0,ndivisions):
    ax1.plot(xSegList[i],ampSegList[i], color = colorList[i])
### Plot average values for each section
if (plotLine):
    for i in range(0,ndivisions):
        ax1.plot(xSegList[i], avgLines[i], color = 'black')

### Or plot everything
#ax1.plot(amps)

plt.show()


# --------------------------------------------------
print("\n--------> "+filename)
print('Start time: ' + str(time[0]))
print('End time: ' + str(time[np.size(amps)-1]))
print('Accept rate: ' + str(accept_rate))
print('\nAverage: ' + str(avg))
print('STDEV: ' + str(stdev))

print('\nFiltered total average: ' + str(filteravg)) #Total average
print ('Average of last current "section": ' + str(avgList[ndivisions-1]))

print('\nFiltered total stdev (stat. error): ' + str(filterstdev)) #Statistical error
print('Error in bias (syst. error): ' + str(maxDeviation)) #Error in stopping measurement at a decided point

print('\nFinal value: ' + str(avgList[ndivisions-1]) + ' +- ' + str(totalError))
