#include <iostream>

using namespace std;

int main(){
	double a;
	cout << "podaj liczbe:" << endl;
	cin >> a;
	while(a>0.49){
		a = a - 0.5;
	cout << a << endl;
	}
	return 0;
}
