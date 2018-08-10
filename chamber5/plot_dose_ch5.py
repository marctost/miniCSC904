#! /usr/bin/env python3
import os
import sys
import datetime
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.dates import DateFormatter

formatter = DateFormatter('%d/%m')
date0 = datetime.date(2018, 4, 9)
date1 = datetime.date(2018, 5, 24)
date2 = datetime.date(2018, 6, 6)
date3 = datetime.date(2018, 6, 13)
date4 = datetime.date(2018, 6, 20)
date5 = datetime.date(2018, 7, 27)
#date6 = datetime.date(2018, , )
#date7 = datetime.date(2018, , )

dates = [date0, date1, date2, date3, date4, date5]
doses = [0, 53, 95, 121, 149, 180]
runnum = [0, 1, 2, 3, 4, 5]


fig, ax = plt.subplots()
plt.plot_date(dates, doses, color='black', linewidth=1., linestyle='solid', marker = 'o', markersize=5.)
ax.xaxis.set_major_formatter(formatter)
#ax.xaxis.set_tick_params(rotation=30, labelsize=10)
ax.set_xlabel('Date')
ax.set_ylabel('Dose [mC/cm]')
ax.set_title(r'Accumulated Charge: 0% CF$_4$ Run')
## Try annotating the individual points
#for i,txt in enumerate(runnum):
#    ax.annotate(txt,(dates[i], doses[i]), horizontalalignment='left')

#plt.show()
fig.savefig("Plots/dose_ch5.pdf")

