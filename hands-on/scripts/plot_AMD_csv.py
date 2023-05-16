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

data = pd.read_csv(outfile)

fig, ax = plt.subplots()
for item in data.keys():
    if (item == "Timestamp") or (item == "RecordId"):
        continue
    else:
        ax.plot(data['Timestamp'],data[item],label=item)

# Add a legend
pos = ax.get_position()
ax.set_position([pos.x0, pos.y0, pos.width * 0.9, pos.height])
ax.legend(loc='center right', bbox_to_anchor=(1.25, 0.9), prop={'size': 5})

ax.xaxis.set_tick_params(rotation=90, size=5)

plt.savefig(outfile.replace("timechart_clean.csv","timechart_plot.png"),dpi=150)