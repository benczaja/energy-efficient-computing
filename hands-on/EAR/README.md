# Work in Progress

Full documentation https://servicedesk.surf.nl/wiki/pages/viewpage.action?pageId=62226671

### Load the EAR module
```
module load 2022
module load ear
```

### Example usage in a batch script

```
#SBATCH --ear=on
#SBATCH --ear-policy=monitoring
```

FULL example:
```
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
```


```
squeue
             JOBID PARTITION     NAME     USER ST       TIME  NODES NODELIST(REASON)
           2884239      thin ear_sbat benjamic  R       2:19      1 tcn352
```

```
eacct -j JOB_ID
```
Example:
```
[benjamic@int4 EAR]$ eacct -j 2884239
    JOB-STEP USER       APPLICATION      POLICY NODES AVG/DEF/IMC(GHz) TIME(s)    POWER(W) GBS     CPI   ENERGY(J)    GFLOPS/W IO(MBs) MPI%  G-POW (T/U)   G-FREQ  G-UTIL(G/MEM)
2884239-sb   benjamic   ear_sbatch_GROMA MO     1     2.57/2.60/---    386.00     596.51   ---     ---   230253       ---      ---     ---   ---           ---     ---          
2884239-0    benjamic   ear_sbatch_GROMA MO     1     2.57/2.60/1.47   348.64     617.18   8.33    0.33  215175       0.2930   0.3     77.6  0.00/---      ---     --- 
```

helpfull comands
```
eacct -j 2884239 -l | less -S
```