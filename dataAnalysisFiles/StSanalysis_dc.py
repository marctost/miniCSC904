# -*- coding: utf-8 -*-
"""
Created on Fri Feb 10 09:07:37 2017

@author: Jameson
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

filename = 'dc-20180117-run11/Dark_current_20180117_Ref_4000V.txt'
#filename = 'Run0/Dark_current_13092017_RefL_3750V_Source'
#filename = 'Run0/Sts_10092017_X4_300V'
chamber = False #almost always true O: true for Sts, false for dark current
points = 1000000

dt = np.dtype([('time','S19'), ('current', float)])
def expfit(x,a,b,c,d,e):
    return a * np.exp(-b * x) + c * np.exp(-d * x) + e

def constline(x,a,b,c,d,e):
    return e+0*x

readin = np.loadtxt(filename,dtype=dt,delimiter='\t')
length = np.size(readin)
time = np.zeros(length,dtype='S19')
amps = np.zeros(length)
for index in range(0,np.size(readin)):
    time[index] = readin[index][0]
    amps[index] = readin[index][1]

if chamber:
    
    filtamps = amps[amps > 0]
    flength = np.size(filtamps)
    filtamps = filtamps[np.argmax(amps[0:int(length/10)]):min(flength,points)-1]
    filtamps = filtamps[filtamps <= filtamps[0]]
    flength = np.size(filtamps)
    
    favg = np.average(filtamps[int(flength * 0.5):])
    frms = np.sqrt(np.average((filtamps[int(flength * 0.5):] - favg) ** 2))
    
    x = np.linspace(0,flength-1,flength)
    popt, pcov = curve_fit(expfit,x,filtamps,p0=np.array([1.52e-10,3.33e-02,1.0e-10,3.0e-03,3.00e-11]))
#,sigma=frms,absolute_sigma=True) 
#,bounds=(0,np.inf)
    #popt, pcov = curve_fit(expfit,x,filtamps,p0=np.array([6.52e-11,1.33e-02,2.59e-10,1.97e-01,3.00e-9]))
#,sigma=frms,absolute_sigma=True) 
#,bounds=(0,np.inf) #original
    perr = np.sqrt(np.diag(pcov))

    no_cap = filtamps - expfit(x, *popt) + popt[4]
    avg = np.average(no_cap[int(flength * 0.5):])
    rms = np.sqrt(np.average((no_cap[int(flength * 0.5):] - avg) ** 2))

else:

    avg = np.average(amps)
    rms = np.sqrt(np.average((amps - avg) ** 2))
    
    included = np.abs(amps - avg) < (3 * rms)
    filteravg = np.average(amps[included])
    filterrms = np.sqrt(np.average((amps[included] - avg) ** 2))
    accept_rate = np.size(amps[included]) / np.size(amps)
    
    uplim = np.ones(length) * (avg + 3 * rms)
    lolim = np.ones(length) * (avg - 3 * rms)
    
if chamber:
   # plt.axis([0,int(flength * 2),0,1e-10])
    xl = np.linspace(0,flength*2-1,flength*2)
    plt.plot(filtamps)
    plt.plot(expfit(xl, *popt))
    plt.plot(no_cap)
    plt.plot(constline(xl, *popt))
    plt.xlim([0,int(flength)])
    plt.show()
else:
    plt.plot(amps)
    plt.plot(uplim,'r-')
    plt.plot(lolim,'r-')
    plt.show()

plt.xlabel('Point Number')
plt.ylabel('Current (A)')
print(filename)
if chamber:
    print('Parameters: ' + str(popt[0])+ '  ' + str(popt[1])+ '  ' + str(popt[2])+ '  ' + str(popt[3])+ '  ' + str(popt[4]))
    print('Points: ' + str(min(points,flength)))
    print('Average: ' + str(avg))
    print('Amps average: ' + str(np.average(filtamps[int(flength * 0.5):])))
    print('Constant: ' + str(popt[4]) + ' +/- ' + str(perr[4]))
    print('RMS: ' + str(rms))
    print('Start time: ' + str(time[0]))
    print('End time: ' + str(time[np.size(filtamps)]))
if not chamber:
    print('Average: ' + str(avg))
    print('RMS: ' + str(rms))
    print('Filtered (within 3 sigma) average: ' + str(filteravg))
    print('Filtered RMS: ' + str(filterrms))
    print('Accept rate: ' + str(accept_rate))
    print('Start time: ' + str(time[0]))
    print('End time: ' + str(time[np.size(amps)-1]))
