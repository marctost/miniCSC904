#! /usr/bin/env python3
import os
import sys
import datetime
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.dates import DateFormatter

os.system("mkdir -p Plots/")

formatter = DateFormatter('%d/%m')
dates = []
doses = []

dates.append( datetime.date(2017, 9, 21) ) #run0
dates.append( datetime.date(2017, 10, 25) ) #start of first irr
dates.append( datetime.date(2017, 11, 1) ) #stop
dates.append( datetime.date(2017, 11, 15) ) #start of more irr
dates.append( datetime.date(2017, 12, 11) ) #stop irr
#dates.append( datetime.date(2017, 12, 14) ) #run1
dates.append( datetime.date(2018, 1, 20) ) #start of irr
dates.append( datetime.date(2018, 3, 2) ) #stop irr
#dates.append( datetime.date(2018, 3, 9) ) #run2 (through 29.3)
dates.append( datetime.date(2018, 4, 4) ) #start again
dates.append( datetime.date(2018, 4, 27) ) #stop
#dates.append( datetime.date(2018, 5, 4) ) #run3 (through 10.5)
dates.append( datetime.date(2018, 5, 25) ) #start?
dates.append( datetime.date(2018, 6, 15) ) #stop?
#dates.append( datetime.date(2018, 7, 1) ) #run4 (no noise) (another run4 before this)
dates.append( datetime.date(2018, 7, 15) ) #start?
dates.append( datetime.date(2018, 8, 1) ) #stop?
#dates.append( datetime.date(2018, 8, 7) ) #run5
dates.append( datetime.date(2018, 9, 15) ) #start?
dates.append( datetime.date(2018, 10, 2) ) #stop
#dates.append( datetime.date(2018, 10, 9) ) #run6
dates.append( datetime.date(2018, 11, 21) ) #start

doses.append(0)
doses.append(0)
doses.append(10)
doses.append(10)
doses.append(17)
#doses.append(17) #run1
doses.append(17)
doses.append(26)
#doses.append(26) #run2
doses.append(26)
doses.append(68)
#doses.append(68) #run3
doses.append(68)
doses.append(123)
#doses.append(123) #run4
doses.append(123)
doses.append(157)
#doses.append(157) #run5
doses.append(157)
doses.append(188)
#doses.append(188) #run6
doses.append(188)

fig, ax = plt.subplots()
plt.plot_date(dates, doses, color='black', linewidth=2., linestyle='solid', marker = 's', markersize=0.)
ax.xaxis.set_major_formatter(formatter)
#ax.xaxis.set_tick_params(rotation=30, labelsize=10)
ax.set_xlabel('Date')
ax.set_ylabel('Dose [mC/cm]')
ax.set_title(r'Accumulated Charge for CF$_4$(2%) GIF++ Study')
ax.set_xlim([datetime.date(2017, 9, 1), datetime.date(2018, 12, 31)])
ax.set_ylim(-5., 350.)
ax.axhline(y=240, linewidth=1, linestyle='--', color='k')
ax.text(0.05, 0.7, '3x expected HL-LHC dose = 240 mC/cm', transform=ax.transAxes, style='italic', color='black', fontsize=10)

numpoints = len(doses)
ax.annotate(str(doses[numpoints-1])+" mC/cm",(dates[numpoints-1], doses[numpoints-1]), xytext=(-30, 10), textcoords='offset points')
plt.plot_date(dates[numpoints-1], doses[numpoints-1], color='#FFD700', linewidth=0., linestyle='solid', marker = '*', markersize=10.)

#plt.show()
fig.savefig("Plots/dose_ch4.pdf")

