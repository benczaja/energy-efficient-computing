#!/bin/bash

#SBATCH -p thin
#SBATCH -t 00:10:00
#SBATCH --exclusive 
#SBATCH --constraint=hwperf

#SBATCH --ear=on
#SBATCH --ear-policy=monitoring
#SBATCH --ear-cpufreq=21000000

module load 2022
module load foss/2022a
module load AMD-uProf/4.0.341

echo "Sleeping for $SLURM_ARRAY_TASK_ID sec in order to make sure output is co-herent"
sleep $SLURM_ARRAY_TASK_ID

AMDuProfCLI timechart --event core=0-3,frequency -o AMDuProf_output_freq --interval 500 --affinity 1 ../bin/mat_mul 2000 -s
AMDuProfCLI timechart --event core=0-3,power -o AMDuProf_output_power --interval 500 --affinity 1 ../bin/mat_mul 2000 -s
