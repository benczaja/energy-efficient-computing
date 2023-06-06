#!/bin/bash

# specify the results to append
RESULTS_FILE=results_omp64.txt


if [ -f "$RESULTS_FILE" ]; then
    echo "$RESULTS_FILE exists."
    echo "Removing $RESULTS_FILE"
    rm $RESULTS_FILE
fi


for i in {2500..3500..100}
do
    echo "Running bin/mat_mul_pmt $i $i"
    OMP_NUM_THREADS=64 OMP_PROC_BIND=CLOSE ../bin/mat_mul_pmt -p $i $i > templog.txt
    #../bin/mat_mul_pmt -s $i $i > templog.txt

    #just some dumb commands to "log the results"
    Size=$(sed -n '/Matrix Size:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    Time=$(sed -n '/PMT Seconds:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    Watt=$(sed -n '/PMT Watts:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    Joule=$(sed -n '/PMT Joules:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    
    echo $Size $Time $Joule $Watt >> $RESULTS_FILE
done

echo "Results saved to: $RESULTS_FILE"