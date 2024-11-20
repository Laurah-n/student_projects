#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double wysokosc, glebokosc;

//dlugosc i wysokosc klatki schodowej
    cout << "Podaj wysokość schodów (w cm): ";
    cin >> wysokosc;
    cout << "Podaj głębokość schodów (w cm): ";
    cin >> glebokosc;
 
//min i max wartosci schodow   
    double minWysokosc = 15.0;
    double maxWysokosc = 17.0;
    double minGlebokosc = 28.0;
    double maxGlebokosc = 30.0;
    
    int iloscStopniWysokosc = floor(wysokosc / minWysokosc);
    int iloscStopniGlebokosc = floor(glebokosc / minGlebokosc);
    
    int iloscStopni = min(iloscStopniWysokosc, iloscStopniGlebokosc);
    
    double glebokoscStopnia = glebokosc / iloscStopni;
    double wysokoscStopnia = wysokosc / iloscStopni;
    
    cout<<"Ilość stopni: "<<iloscStopni<<endl;
    cout<<"Głębokość pojedynczego stopnia: "<<glebokoscStopnia<<endl;
    cout<<"Wysokość pojedynczego stopnia: "<<wysokoscStopnia<<endl;
    
    return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Wprowadzenie danych od użytkownika
    double wysokoscKlatki, dlugoscKlatki;
    cout << "Podaj wysokosc klatki schodowej (w cm): ";
    cin >> wysokoscKlatki;
    cout << "Podaj dlugosc klatki schodowej (w cm): ";
    cin >> dlugoscKlatki;

    // Zakresy dla długości i wysokości schodka
    const double minDlugoscSchodka = 29.0, maxDlugoscSchodka = 32.0;
    const double minWysokoscSchodka = 15.0, maxWysokoscSchodka = 17.0;

    bool znalezionoRozwiazanie = false;

    // Pętla dla długości schodka
    for (double dlugoscSchodka = minDlugoscSchodka; dlugoscSchodka <= maxDlugoscSchodka; dlugoscSchodka += 0.1) {
        // Obliczanie liczby schodów na podstawie długości klatki schodowej
        int liczbaSchodowDlugosc = static_cast<int>(dlugoscKlatki / dlugoscSchodka);
        if (dlugoscSchodka * liczbaSchodowDlugosc == dlugoscKlatki) { // Sprawdzenie, czy wynik jest liczba całkowitą
            for (double wysokoscSchodka = minWysokoscSchodka; wysokoscSchodka <= maxWysokoscSchodka; wysokoscSchodka += 0.1) {
                // Obliczanie liczby schodów na podstawie wysokości klatki schodowej
                int liczbaSchodowWysokosc = static_cast<int>(wysokoscKlatki / wysokoscSchodka);
                if (wysokoscSchodka * liczbaSchodowWysokosc == wysokoscKlatki) { // Sprawdzenie, czy wynik jest liczba całkowitą
                    // Jeśli obie liczby schodów są takie same, wypisz wynik
                    if (liczbaSchodowDlugosc == liczbaSchodowWysokosc) {
                        cout << "Liczba schodow: " << liczbaSchodowDlugosc << endl;
                        cout << "Dlugosc schodka: " << dlugoscSchodka << " cm" << endl;
                        cout << "Wysokosc schodka: " << wysokoscSchodka << " cm" << endl;
                        znalezionoRozwiazanie = true;
                        break;
                    }
                }
            }
        }
    }

    if (!znalezionoRozwiazanie) {
        cout << "Nie znaleziono odpowiedniego rozwiazania dla podanych danych." << endl;
    }

    return 0;
}


