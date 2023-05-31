# Simple Matrix multiplication 
import numpy as np
from random import random
import time

def explicit_matmul(A,B):
    C = [[0 for x in range(len(A))] for y in range(len(B[0]))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]
    return C

# Simple Matrix multiplication algorithm
def numpy_matmul(A,B):
    npA = np.array(A)
    npB = np.array(B)
    C = np.matmul(A,B)
    return C

#Set matrix dimension
AX=AY=BX=BY=800

#Define Matrix A
A = [[random() for x in range(AX)] for y in range(AY)]

#Define Matrix B
B = [[random() for x in range(BX)] for y in range(BY)]

#And now time the two runs and compare the results
print("Explicit:")
start = time.perf_counter_ns()
explicit_matmul(A,B)
end = time.perf_counter_ns()
print("Time of Explicit is " +str(round(end-start)/1e9) + " s")


start = time.perf_counter_ns()
numpy_matmul(A,B)
end = time.perf_counter_ns()
print("Time of NumPy is " +str(round(end-start)/1e9) + " s")



