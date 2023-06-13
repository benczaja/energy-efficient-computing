# Hands on Overview

## Sessions
1. [Monitoring tutorial](monitoring/README.md)
2. [DVFS tutorial](DVFS/README.md)
3. [Kernel Tuner tutorial](KT/README.md)
3. [EAR tutorial](EAR/README.md)

## Sources are located in the `src/`
1. Simple saxpy (single precision a*x + b) (`saxpy.c`)
2. Simple matrix multiplication (`mat_mul.cpp`, `mat_mul.py`)

### How to build all of the sources

```
sh install_examples.sh
```

### How to build each of the sources

#### 1. Simple saxpy (saxpy.py)
How to compile compile the program:
```
module purge
module load 2022
module load foss/2022a

gcc -fopenmp src/saxpy.c -o bin/saxpy
```
Note: `-fopenmp` needed here because we use a simple OpenMP parallelization example.

How to use: 
```
saxpy (array size) [-s|-p|-h]
              Invoke simple implementation of Saxpy (Single precision A X plus Y)
        -s    Invoke simple implementation of Saxpy (Single precision A X plus Y)
        -p    Invoke parallel (OpenMP) implementation of Saxpy (Single precision A X plus Y)
        -h    Display help
```
**Naive Serial implementation**
```
./bin/saxpy 200
or
./bin/saxpy -s 200
```

**Naive OpenMP implementation**
```
./bin/saxpy -p 200
```
Suggestion: Play around with the `OMP_NUM_THREADS` for your execution
```
OMP_NUM_THREADS=2 ./bin/saxpy -p 200
```

#### 2. Simple Matrix multiplication (mat_mul.c)
How to compile compile the program:
```
module purge
module load 2022
module load foss/2022a

g++ -fopenmp src/mat_mul.cpp -o bin/mat_mul
```
Note: `-fopenmp` needed here because we use a simple OpenMP parallelization example.

How to use: 
```
mat_mul (matrix size) [-s|-p|-h]
              Invoke simple implementation of matrix multiplication
        -s    Invoke simple implementation of matrix multiplication
        -p    Invoke parallel (OpenMP) implementation of matrix multiplication
        -h    Display help
```
**Naive Serial implementation**
```
./bin/mat_mul 200 200
or
./bin/mat_mul -s 200 200
```

**Naive OpenMP implementation**
```
./bin/mat_mul -p 200 200
```
Suggestion: Play around with the `OMP_NUM_THREADS` for your execution
```
OMP_NUM_THREADS=2 ./bin/mat_mul -p 200 200
```
