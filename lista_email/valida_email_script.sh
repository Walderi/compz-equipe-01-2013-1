#!/bin/bash
clear
make
clear
echo "Validando listas de email 1-10..."
./verificar-emails arquivo-emails1.txt > validos1.txt
./verificar-emails arquivo-emails2.txt > validos2.txt
./verificar-emails arquivo-emails3.txt > validos3.txt
./verificar-emails arquivo-emails4.txt > validos4.txt
./verificar-emails arquivo-emails5.txt > validos5.txt
./verificar-emails arquivo-emails6.txt > validos6.txt
./verificar-emails arquivo-emails7.txt > validos7.txt
./verificar-emails arquivo-emails8.txt > validos8.txt
./verificar-emails arquivo-emails9.txt > validos9.txt
./verificar-emails arquivo-emails10.txt > validos10.txt
clear
make clean
clear
echo "Fim."
