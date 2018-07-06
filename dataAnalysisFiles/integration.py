# -*- coding: utf-8 -*-
"""
Created on Thu May  4 20:06:03 2017

@author: Jameson, Ota - fix to the calculation
"""

import numpy as np
import datetime as dt

filename = 'run12/20180122'
cross_section = 13.4

readin = np.genfromtxt(filename, delimiter = '\t')

VSet = readin[:,1]
VMon = readin[:,2]
IMon = readin[:,3] * 0.000001

#start_time = input("Time of dose beginning in format YYYY-MM-DD HH:MM:SS: ")
#end_time = input("Time of dose ending in format YYYY-MM-DD HH:MM:SS: ")

start = dt.datetime(2018, 01, 22, 14, 02, 18)
#stop = dt.datetime(int(end_time[0:4]), int(end_time[5:7]), int(end_time[8:10]), int(end_time[11:13]), int(end_time[14:16]), int(end_time[17:19]))
#stop = dt.datetime((end_time[0:4]), (end_time[4:6]), (end_time[6:8]), (end_time[8:10]), (end_time[10:12]), (end_time[12:14]))
stop = dt.datetime(2018, 02, 04, 11, 25, 28)

total_time = (stop - start).total_seconds()

#print total_time

tint = total_time / (len(readin)-1)

dose = 0

for ind in range(0,len(readin)-1):
    if abs(VSet[ind] - VMon[ind]) <= 5.0 and abs(VSet[ind + 1] - VMon[ind + 1]) <= 5.0 and min(IMon[ind], IMon[ind + 1]) > 0:

        dose += (0.6666) * tint * (IMon[ind] + IMon[ind + 1]) / 2

dose /= cross_section

print(dose)

