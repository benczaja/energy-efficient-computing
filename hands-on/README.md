# Hands on Overview

## Sessions
1. [Monitoring tutorial](monitoring/README.md)
2. [DVFS tutorial](DVFS/README.md)
3. [Kernel Tuner tutorial](https://github.com/KernelTuner/kernel_tuner)
3. [EAR tutorial](EAR/README.md)

## Sources are located in the `src/`
1. Simple matrix multiplication (`mat_mul.cpp`)
2. Simple saxpy (single precision a*x + b) (`saxpy.cpp`)
3. **To Be Added Sparse matrix–vector multiplication (SpMV)**
4. **Simple Python implementation as well???**

## Hands on Examples
1. Simple matrix multiplication 
2. Simple saxpy (single precision a*x + b)
3. **To Be Added Sparse matrix–vector multiplication (SpMV)**
4. **Simple Python implementation as well???**

### 1. Simple Matrix multiplication
How to compile compile the program:
```
module purge
module load 2022
module load foss/2022a

g++ -fopenmp mat_mul.cpp -o mat_mul
```
Note: `-fopenmp` needed here because we use a simple OpenMP parallelization example.

How to run:
```
./mat_mul
```
Suggestion: Play around with the `OMP_NUM_THREADS` for your execution
```
OMP_NUM_THREADS=2 ./mat_mul
```
