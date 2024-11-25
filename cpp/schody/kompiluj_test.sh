#!/bin/sh
rm main_tests
clear
echo "----Kompilacja programu testujacego----"

# Kompilacja kodu źródłowego dla programu głównego
g++ main.cpp -o main

# Kompilacja kodu testów
g++ main_tests.cpp -o main_tests -lgtest -lgtest_main -pthread

echo "---Kompilacja testow ukonczona----"
echo "---Uruchamianie programu testujacego---"
chmod +x main_tests
./main_tests
echo "---Zakonczono program testujacy---"
