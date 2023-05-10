#!/bin/bash


FILE=results.txt
if [ -f "$FILE" ]; then
    echo "$FILE exists."
    echo "Removing $FILE"
    rm $FILE
fi


for i in {0..2000..50}
do
    echo "Running $i $i"
    ../test $i $i > templog.txt

    #just some dumb commands to "log the results"
    Size=$(sed -n '/Matrix Size:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    Time=$(sed -n '/PMT Seconds:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    Watt=$(sed -n '/PMT Watts:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    Joule=$(sed -n '/PMT Joules:/p' templog.txt | grep -Eo '[+-]?[0-9]+([.][0-9]+)?')
    
    echo $Size $Time $Joule $Watt >> results.txt

done