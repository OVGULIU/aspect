#!/bin/bash

a=2
for ((i=0; i<=12; i++)); do      
    for j in 16 32 64 128 256 512 1024; do
        awk "NR>=$[i+a] && NR<=$[i+a]" ${j}proc_mf >> ${i}ref_mf
    done
done
