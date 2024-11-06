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
