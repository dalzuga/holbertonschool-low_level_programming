#!/bin/bash

for i in `seq 0 7`
do
    "./a.out < sample$i.txt"
done
