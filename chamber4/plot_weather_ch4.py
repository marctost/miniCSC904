#! /usr/bin/env python3
import os
import sys
import datetime
import numpy as np
import matplotlib.pyplot as plt

doses = [0, 17, 26, 68, 123, 157, 188]
doses_CC = [0, 26, 68, 123, 157, 188] #ommitted run1 due to lack of full data

#############################################
## Cluster Charge Pressure

pIrr1 = [963.1, 950.7, 954.9, 955, 958.5, 961.7] #irr(1,1)
pIrr2 = [963.1, 950.7, 954.9, 955, 958.4, 961.5] #irr(1,2)
pIrr3 = [963, 950.7, 954.9, 955, 958.4, 961.5] #irr(2,1)
pIrr4 = [962.9, 950.7, 954.9, 955, 958.4, 961.5] #irr(2,2)
pIrr5 = [963.5, 950.7, 955, 954.9, 958.4, 961.5] #irr(3,1)
pIrr6 = [963.9, 950.7, 955, 954.9, 958.4, 961.5] #irr(3,2)

pRef1 = [963.8, 950.3, 955.5, 954.9, 957.9, 961.6] #ref(1,1)
pRef2 = [963.6, 950.3, 955.5, 954.9, 957.9, 961.6] #ref(1,2)
pRef3 = [963.4, 950.2, 955.5, 954.9, 957.9, 961.6] #ref(2,1)
pRef4 = [963.1, 950.2, 955.5, 954.9, 957.9, 961.6] #ref(2,2)
pRef5 = [963, 950.6, 955.5, 954.9, 957.5, 961.7] #ref(3,1)
pRef6 = [963, 950.6, 955.3, 954.9, 957.5, 961.7] #ref(3,2)

fig, ax1 = plt.subplots()
ax1.set_title(r'Pressure in b904')

ax1.plot(doses_CC, pIrr1, color='#ca3332', linestyle='solid', marker='o', markersize=5., label='Irr (1,1)')
ax1.plot(doses_CC, pIrr2, color='#983403', linestyle='solid', marker='o', markersize=5., label='Irr (1,2)')
ax1.plot(doses_CC, pIrr3, color='#fd0000', linestyle='solid', marker='o', markersize=5., label='Irr (2,1)')
ax1.plot(doses_CC, pIrr4, color='#630000', linestyle='solid', marker='o', markersize=5., label='Irr (2,2)')
ax1.plot(doses_CC, pIrr5, color='#cb6666', linestyle='solid', marker='o', markersize=5., label='Irr (3,1)')
ax1.plot(doses_CC, pIrr6, color='#fc9a05', linestyle='solid', marker='o', markersize=5., label='Irr (3,2)')

ax1.plot(doses_CC, pRef1, color='#026698', linestyle='solid', marker='o', markersize=5., label='Ref (1,1)')
ax1.plot(doses_CC, pRef2, color='#2a99ff', linestyle='solid', marker='o', markersize=5., label='Ref (1,2)')
ax1.plot(doses_CC, pRef3, color='#cbccfe', linestyle='solid', marker='o', markersize=5., label='Ref (2,1)')
ax1.plot(doses_CC, pRef4, color='#cbccff', linestyle='solid', marker='o', markersize=5., label='Ref (2,2)')
ax1.plot(doses_CC, pRef5, color='#6567ff', linestyle='solid', marker='o', markersize=5., label='Ref (3,1)')
ax1.plot(doses_CC, pRef6, color='#0000ff', linestyle='solid', marker='o', markersize=5., label='Ref (3,2)')

ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Pressure', color='black')
ax1.tick_params('y', colors='black')
ax1.set_ylim(940, 965)

ax1.legend(loc='lower right', labelspacing=0.1)

fig.tight_layout()
#plt.show()
fig.savefig("Plots/weather_CC_ch4.pdf")
del fig, ax1, pIrr1, pIrr2, pIrr3, pIrr4, pIrr5, pIrr6, pRef1, pRef2, pRef3, pRef4, pRef5, pRef6

#############################################
## StS Humidity
#Pick an average value of the humidity for all of the strips
hum1 = [29.5, 24.3, 20.6, 29.25, 34.1, 46, 33]

#fig, ax1 = plt.subplots()
fig = plt.figure(figsize=(7,2.5))
ax1 = plt.subplot(1,1,1)

ax1.set_title(r'Humidity in b904')
ax1.plot(doses, hum1, color='blue', linestyle='solid', marker='o', markersize=5.)
ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Humidity', color='black')
ax1.tick_params('y', colors='black')
ax1.set_ylim(10, 50)

#ax1.legend(loc='lower right')

fig.tight_layout()
#plt.show()
fig.savefig("Plots/weather_StS_ch4.pdf")
del fig, ax1, hum1

#############################################
### Dark Current, Irr Layer
#hum1 = []
#p1 = []
#
##fig, ax1 = plt.subplots()
#fig = plt.figure(figsize=(7,2.5))
#ax1 = plt.subplot(1,1,1)
##ax1.set_title(r'Dark Current Irr. Layer')
#
#ax1.plot(doses, hum1, color='blue', linestyle='solid', marker='o', markersize=5.)
#ax1.set_xlabel('Dose [mC/cm]')
#ax1.set_ylabel('Humidity', color='b')
#ax1.tick_params('y', colors='b')
#ax1.set_ylim(25, 45)
#
#ax2 = ax1.twinx()
#ax2.plot(doses, p1, color='#e68a00', linestyle='solid', marker='o', markersize=5.)
#ax2.set_ylabel('Pressure', color='#e68a00')
#ax2.tick_params('y', colors='#e68a00')
#ax2.set_ylim(945, 965)
#
#fig.tight_layout()
##plt.show()
#fig.savefig("Plots/weather_DC_Irr_ch4.pdf")
#del fig, ax1, ax2, hum1, p1
#
##############################################
### Dark Current, Ref Layer
#hum1 = []
#p1 = []
#
##fig, ax1 = plt.subplots()
#fig = plt.figure(figsize=(7,2.5))
#ax1 = plt.subplot(1,1,1)
##ax1.set_title(r'Dark Current Ref. Layer')
#
#ax1.plot(doses, hum1, color='blue', linestyle='solid', marker='o', markersize=5.)
#ax1.set_xlabel('Dose [mC/cm]')
#ax1.set_ylabel('Humidity', color='b')
#ax1.tick_params('y', colors='b')
#ax1.set_ylim(25, 45)
#
#ax2 = ax1.twinx()
#ax2.plot(doses, p1, color='#e68a00', linestyle='solid', marker='o', markersize=5.)
#ax2.set_ylabel('Pressure', color='#e68a00')
#ax2.tick_params('y', colors='#e68a00')
#ax2.set_ylim(945, 965)
#
#fig.tight_layout()
##plt.show()
#fig.savefig("Plots/weather_DC_Ref_ch4.pdf")
#del fig, ax1, ax2, hum1, p1
#
##############################################
## Dark Current, Humidity
humRef = []
humIrr = []

#fig, ax1 = plt.subplots()
fig = plt.figure(figsize=(7,2.5))
ax1 = plt.subplot(1,1,1)
#ax1.set_title(r'Dark Current Ref. Layer')

ax1.plot(doses, humRef, color='blue', linestyle='solid', marker='o', markersize=5.)
ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Humidity (Ref. Layer)', color='b')
ax1.tick_params('y', colors='b')
ax1.set_ylim(25, 45)

ax2 = ax1.twinx()
ax2.plot(doses, humIrr, color='#e68a00', linestyle='solid', marker='o', markersize=5.)
ax2.set_ylabel('Humidity (Irr. Layer)', color='#e68a00')
ax2.tick_params('y', colors='#e68a00')
ax2.set_ylim(25, 45)

fig.tight_layout()
#plt.show()
fig.savefig("Plots/weather_DC_Hum_ch4.pdf")
del fig, ax1, ax2, humRef, humIrr

##############################################
### Dark Current, Pressure
#pRef = []
#pIrr = []
#
##fig, ax1 = plt.subplots()
#fig = plt.figure(figsize=(7,2.5))
#ax1 = plt.subplot(1,1,1)
##ax1.set_title(r'Dark Current Ref. Layer')
#
#ax1.plot(doses, pRef, color='blue', linestyle='solid', marker='o', markersize=5.)
#ax1.set_xlabel('Dose [mC/cm]')
#ax1.set_ylabel('Pressure (Ref. Layer)', color='b')
#ax1.tick_params('y', colors='b')
#ax1.set_ylim(945, 965)
#
#ax2 = ax1.twinx()
#ax2.plot(doses, pIrr, color='#e68a00', linestyle='solid', marker='o', markersize=5.)
#ax2.set_ylabel('Pressure (Irr. Layer)', color='#e68a00')
#ax2.tick_params('y', colors='#e68a00')
#ax2.set_ylim(945, 965)
#
#fig.tight_layout()
##plt.show()
#fig.savefig("Plots/weather_DC_Pressure_ch4.pdf")
#del fig, ax1, ax2, pRef, pIrr

