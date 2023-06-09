#!/bin/bash

#SBATCH -p thin
#SBATCH -n 128
#SBATCH -t 00:20:00
#SBATCH --exclusive 
#SBATCH --output=GROMACS_run.out
#SBATCH --error=GROMACS_run.err

#SBATCH --ear=on
#SBATCH --ear-policy=monitoring

module load 2022
module load foss/2022a
module load GROMACS/2021.6-foss-2022a

srun --ntasks=128 --cpus-per-task=1 gmx_mpi mdrun -s benchmark.tpr 