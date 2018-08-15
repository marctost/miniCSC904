#! /usr/bin/env python3
import os
import sys
import datetime
import numpy as np
import matplotlib.pyplot as plt

doses = [0, 53, 95, 121, 149, 180]

#############################################
## Cluster Charge Pressure
p1 = [948.1, 957.5, 956.1, 953.8, 960, 960] #irr(2,1)
p2 = [947.9, 957.5, 956, 954, 960, 960] #irr(2,2) (irr)
p3 = [947.6, 957.5, 956, 954, 960, 960] #irr(3,1)
p4 = [947.6, 957.5, 956, 954, 959.9, 960] #irr(3,2)
p5 = [942.4, 957.5, 955.8, 954.3, 959.5, 960] #ref(2,2)
p6 = [942.3, 957.5, 955.8, 954.3, 959.5, 960] #ref(3,1)

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
hum1 = [19, 44, 36, 48, 32, 28]

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
hum1 = [29, 31, 42.5, 35, 33, 38.5]
p1 = [948.3, 959.5, 959, 957.5, 959.4, 960.8]

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
hum1 = [29, 42.5, 36.5, 35.5, 35, 44.5]
p1 = [947.7, 960.5, 957.1, 957.9, 954.4, 960.1]

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
humRef = [29, 42.5, 36.5, 35.5, 35, 44.5]
humIrr = [29, 31, 42.5, 35, 33, 38.5]

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
pRef = [947.7, 960.5, 957.1, 957.9, 954.4, 960.1]
pIrr = [948.3, 959.5, 959, 957.5, 959.4, 960.8]

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
fig.savefig("Plots/weather_DC_Pressure_ch5.pdf")
del fig, ax1, ax2, pRef, pIrr
