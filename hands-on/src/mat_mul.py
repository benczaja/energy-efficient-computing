# Simple Matrix multiplication 
import sys
import numpy as np
import time
import argparse
from random import random


def simple_matrix_multiply(A,B):
    """
    Very Naive implementation of Matrix Multiplication.

    :Matrix A: list of lists A 
    :Matrix B: list of lists B 
    :return: Matrix C
    """ 

    C = [[0 for x in range(len(A))] for y in range(len(B[0]))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]
    return C

def numpy_matrix_multiply(A,B):
    """
    Simple NumPy implementation of Matrix Multiplication.

    :Matrix A: list of lists A 
    :Matrix B: list of lists B 
    :return: Matrix C
    """ 

    npA = np.array(A)
    npB = np.array(B)
    C = np.matmul(A,B)
    return C

if __name__ == "__main__":

    # Parse the arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("ROWS", help="N rows",type=int)
    parser.add_argument("COLUMNS", help="N Columns",type=int)
    parser.add_argument("-s", "--simple", help="Use Simple Matmul (Default if no option given)",action="store_true",default=True)
    parser.add_argument("-n", "--numpy", help="Use NumPy Matmul ",action="store_true")
    args = parser.parse_args()
    
    #Set matrix dimensions
    ROWS = args.ROWS
    COLUMNS = args.COLUMNS

    #Define Matrix A
    A = [[random() for x in range(ROWS)] for y in range(COLUMNS)]
    #Define Matrix B
    B = [[random() for x in range(ROWS)] for y in range(COLUMNS)]

    # choose simple mat mul
    if args.simple and not args.numpy: #Dumb logic here
        #And now time the two runs and compare the results
        print("(Simple) Matrix Multiplication of 2D matricies of equal sizes ("+str(ROWS)+", "+str(COLUMNS)+")")
        start = time.perf_counter_ns()
        simple_matrix_multiply(A,B)
        end = time.perf_counter_ns()
        print("Time of Serial is " +str(round(end-start)/1e9) + " s")

    # choose NumPy mat mul
    if args.numpy:
        #And now time the two runs and compare the results
        print("(NumPy) Matrix Multiplication of 2D matricies of equal sizes ("+str(ROWS)+", "+str(COLUMNS)+")")
        start = time.perf_counter_ns()
        numpy_matrix_multiply(A,B)
        end = time.perf_counter_ns()
        print("Time of Numpy is " +str(round(end-start)/1e9) + " s")

