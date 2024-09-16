#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream plik;
	plik.open("dane.txt", ios::out);
	double a;
	cout << "podaj liczbe:" << endl;
	cin >> a;
	while(a>0.49){
		a = a - 0.5;
	cout << a << endl;
	plik << a << endl;
	}
	plik.close();
	return 0;
}
