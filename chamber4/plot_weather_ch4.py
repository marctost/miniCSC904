#! /usr/bin/env python3
import os
import sys
import datetime
import numpy as np
import matplotlib.pyplot as plt

doses = [0, 17, 26, 68, 123, 157]

#############################################
## Cluster Charge Pressure
p1 = [] #irr(2,1)
p2 = [] #irr(2,2) (irr)
p3 = [] #irr(3,1)
p4 = [] #irr(3,2)
p5 = [] #ref(2,2)
p6 = [] #ref(3,1)

fig, ax1 = plt.subplots()
ax1.set_title(r'Pressure in b904')

ax1.plot(doses, p1, color='#346BD1', linestyle='solid', marker='o', markersize=5., label='Irr (2,1)')
ax1.plot(doses, p2, color='#DD3D14', linestyle='solid', marker='o', markersize=5., label='Irr (2,2) (Irr)')
ax1.plot(doses, p3, color='#F6981C', linestyle='solid', marker='o', markersize=5., label='Irr (3,1)')
ax1.plot(doses, p4, color='#259124', linestyle='solid', marker='o', markersize=5., label='Irr (3,2)')
ax1.plot(doses, p5, color='#92198F', linestyle='solid', marker='o', markersize=5., label='Ref (2,2)')
ax1.plot(doses, p6, color='#2691CC', linestyle='solid', marker='o', markersize=5., label='Ref (3,1)')

ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Pressure', color='black')
ax1.tick_params('y', colors='black')
ax1.set_ylim(940, 965)

ax1.legend(loc='lower right')

fig.tight_layout()
#plt.show()
fig.savefig("Plots/weather_CC_ch5.pdf")
del fig, ax1, p1, p2, p3, p4, p5, p6

#############################################
## StS Humidity
hum1 = []

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
fig.savefig("Plots/weather_StS_ch5.pdf")
del fig, ax1, hum1

#############################################
## Dark Current, Irr Layer
hum1 = []
p1 = []

#fig, ax1 = plt.subplots()
fig = plt.figure(figsize=(7,2.5))
ax1 = plt.subplot(1,1,1)
#ax1.set_title(r'Dark Current Irr. Layer')

ax1.plot(doses, hum1, color='blue', linestyle='solid', marker='o', markersize=5.)
ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Humidity', color='b')
ax1.tick_params('y', colors='b')
ax1.set_ylim(25, 45)

ax2 = ax1.twinx()
ax2.plot(doses, p1, color='#e68a00', linestyle='solid', marker='o', markersize=5.)
ax2.set_ylabel('Pressure', color='#e68a00')
ax2.tick_params('y', colors='#e68a00')
ax2.set_ylim(945, 965)

fig.tight_layout()
#plt.show()
fig.savefig("Plots/weather_DC_Irr_ch5.pdf")
del fig, ax1, ax2, hum1, p1

#############################################
## Dark Current, Ref Layer
hum1 = []
p1 = []

#fig, ax1 = plt.subplots()
fig = plt.figure(figsize=(7,2.5))
ax1 = plt.subplot(1,1,1)
#ax1.set_title(r'Dark Current Ref. Layer')

ax1.plot(doses, hum1, color='blue', linestyle='solid', marker='o', markersize=5.)
ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Humidity', color='b')
ax1.tick_params('y', colors='b')
ax1.set_ylim(25, 45)

ax2 = ax1.twinx()
ax2.plot(doses, p1, color='#e68a00', linestyle='solid', marker='o', markersize=5.)
ax2.set_ylabel('Pressure', color='#e68a00')
ax2.tick_params('y', colors='#e68a00')
ax2.set_ylim(945, 965)

fig.tight_layout()
#plt.show()
fig.savefig("Plots/weather_DC_Ref_ch5.pdf")
del fig, ax1, ax2, hum1, p1

#############################################
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
fig.savefig("Plots/weather_DC_Hum_ch5.pdf")
del fig, ax1, ax2, humRef, humIrr

#############################################
## Dark Current, Pressure
pRef = []
pIrr = []

#fig, ax1 = plt.subplots()
fig = plt.figure(figsize=(7,2.5))
ax1 = plt.subplot(1,1,1)
#ax1.set_title(r'Dark Current Ref. Layer')

ax1.plot(doses, pRef, color='blue', linestyle='solid', marker='o', markersize=5.)
ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Pressure (Ref. Layer)', color='b')
ax1.tick_params('y', colors='b')
ax1.set_ylim(945, 965)

ax2 = ax1.twinx()
ax2.plot(doses, pIrr, color='#e68a00', linestyle='solid', marker='o', markersize=5.)
ax2.set_ylabel('Pressure (Irr. Layer)', color='#e68a00')
ax2.tick_params('y', colors='#e68a00')
ax2.set_ylim(945, 965)

fig.tight_layout()
#plt.show()
fig.savefig("Plots/weather_DC_Pressure_ch4.pdf")
del fig, ax1, ax2, pRef, pIrr
