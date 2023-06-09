#!/bin/bash

#SBATCH -p thin
#SBATCH -n 128
#SBATCH -t 00:59:00
#SBATCH --exclusive 
#SBATCH --constraint=hwperf
#SBATCH --output=job_dvfs_uProfscaling_job.out
#SBATCH --error=job_dvfs_uProfscaling_job.out

#SBATCH --ear=on

module load 2022
module load foss/2022a
module load AMD-uProf/4.0.341

matrix_size=10000

for i in {1500000..2600000..100000}
do
    echo "Launching power profiling @ Freq=$i"
    srun --ntasks=1 --ear-cpufreq=$i --ear-policy=monitoring --ear-verbose=1 AMDuProfCLI timechart --event socket,power -o AMDuProf_output_power_freq_$i --interval 500 ../bin/mat_mul $matrix_size $matrix_size -p
done
