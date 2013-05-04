#!/bin/bash
clear
make
clear
echo "Validando listas de email 1-10..."
./verificar-emails arquivo-emails1.txt >> validos.txt
./verificar-emails arquivo-emails2.txt >> validos.txt
./verificar-emails arquivo-emails3.txt >> validos.txt
./verificar-emails arquivo-emails4.txt >> validos.txt
./verificar-emails arquivo-emails5.txt >> validos.txt
./verificar-emails arquivo-emails6.txt >> validos.txt
./verificar-emails arquivo-emails7.txt >> validos.txt
./verificar-emails arquivo-emails8.txt >> validos.txt
./verificar-emails arquivo-emails9.txt >> validos.txt
./verificar-emails arquivo-emails10.txt >> validos.txt
clear
make clean
clear
echo "Fim."
