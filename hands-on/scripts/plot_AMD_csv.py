import numpy as np
import subprocess
import sys
import pandas as pd
from matplotlib import pyplot as plt

if not sys.argv[1]:
    print("You need to pass this script a AMD reportfile (.csv) file")
    exit (1)
if ".csv" not in sys.argv[1]:
    print("Need to pass this script a .csv file")
    exit (1)

infile = sys.argv[1]
outfile = infile.replace("timechart","timechart_clean")

plot_outdir = "/home/benjamic/energy-efficient-computing/hands-on/monitoring"
##UGLY cleaning of the AMD csv file
f = open(outfile, "w")
subprocess.call(["sed", '1,/PROFILE RECORDS/d', infile], stdout=f)

data = pd.read_csv(outfile,on_bad_lines="warn")
data = data.dropna() # Drop NaN rows due to bad AMDuProf

fig, ax = plt.subplots()
total_energy = []
for item in data.keys():
    if (item == "Timestamp") or (item == "RecordId"):
        continue
    else:
        ax.plot(data['Timestamp'],data[item],label=item)

        if "power" in item:
            total_energy.append(np.sum(data[item]))  #Power per core

comblist = '\t'.join(list(data.keys()))
if "power" in comblist:
    time_start = data.head(1)["Timestamp"].str.split(':')
    time_end = data.tail(1)["Timestamp"].str.split(':')
    delta_t =  float(time_end.values[0][0])*3600. -  float(time_start.values[0][0])*3600.   #hours in secs
    delta_t += float(time_end.values[0][1])*60. -    float(time_start.values[0][1])*60.     #mins in secs
    delta_t += float(time_end.values[0][2])    -     float(time_start.values[0][2])         #secs
    delta_t += float(time_end.values[0][3])/1000 -   float(time_start.values[0][3])/1000.   #miliseconds in secs
    total_energy = sum(total_energy)*delta_t/3600 # Energy usage in Wh
    ax.set_title("ENERGY USAGE %0.2f Wh" % total_energy)

# Add a legend
pos = ax.get_position()
ax.set_position([pos.x0, pos.y0, pos.width * 0.9, pos.height])
ax.legend(loc='center right', bbox_to_anchor=(1.17, 0.95), prop={'size': 5})

#ax.xaxis.set_tick_params(rotation=45,size=6)
plt.xticks(fontsize=4, rotation=90)

plt.savefig(outfile.replace("timechart_clean.csv","timechart_plot.png"),dpi=150)