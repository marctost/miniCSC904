#! /usr/bin/env python3
import os
import sys
import datetime
import numpy as np
import matplotlib.pyplot as plt

doses = [0, 53, 95, 121, 149, 180]

#############################################
## Dark Current for Both Layers, 3.6 kV
currentRef = [75.3, 156.4, 384.4, 200.9, 210, 83.5]
currentIrr = [62.48, 520.8, 809.2, 863.3, 488, 467.2]

fig, ax1 = plt.subplots()
#fig = plt.figure(figsize=(7,2.5))
#ax1 = plt.subplot(1,1,1)
ax1.set_title(r'Dark Current at 3.6 kV')

ax1.plot(doses, currentRef, color='blue', linestyle='solid', marker='o', markersize=5., label='Reference Layer')
ax1.plot(doses, currentIrr, color='#e68a00', linestyle='solid', marker='o', markersize=5., label='Irradiated Layer')
ax1.set_xlabel('Dose [mC/cm]')
ax1.set_ylabel('Current [pA]')
ax1.tick_params('y')
ax1.set_ylim(0, 1000)

ax1.legend(loc='upper right')

fig.tight_layout()
#plt.show()
fig.savefig("Plots/DC_WPV_ch5.pdf")
del fig, ax1, currentRef, currentIrr


