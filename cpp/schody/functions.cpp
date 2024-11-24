#include <iostream>
#include <cmath>
#include <algorithm>
#include "functions.h"

void wprowadzenieWymiarow(double& wysokosc, double& dlugosc) {
    std::cout << "Podaj wysokość schodów (w cm): ";
    std::cin >> wysokosc;
    std::cout << "Podaj długość schodów (w cm): ";
    std::cin >> dlugosc;
}

int obliczIloscStopni(double wysokosc, double dlugosc) {
    const double minWysokosc = 15.0;
    const double maxWysokosc = 17.0;
    const double minDlugosc = 28.0;
    const double maxDlugosc = 30.0;

    int iloscStopniWysokosc = std::floor(wysokosc / minWysokosc);
    int iloscStopniDlugosc = std::floor(dlugosc / minDlugosc);

    if (iloscStopniWysokosc <= 0 || iloscStopniDlugosc <= 0) {
        return -1;  // Nie można wygenerować schodów
    }

    int iloscStopni = std::min(iloscStopniWysokosc, iloscStopniDlugosc);

    // Sprawdzenie, czy długość stopnia nie przekracza maksymalnej wartości
    double dlugoscStopnia = dlugosc / iloscStopni;
    if (dlugoscStopnia > maxDlugosc) {
        return -1;  // Nie można wygenerować schodów
    }

    return iloscStopni;
}

void obliczWymiaryStopnia(double dlugosc, double wysokosc, int iloscStopni, double& dlugoscStopnia, double& wysokoscStopnia) {
    dlugoscStopnia = dlugosc / iloscStopni;
    wysokoscStopnia = wysokosc / iloscStopni;
}
