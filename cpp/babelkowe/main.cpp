#include <iostream>
#include <vector>

using namespace std;

void sortowanie_babelkowe(vector<int> tab)
{
	int n = tab.size();
	for(int i=0; i<n; i++)
		for(int j=1; j<n-i; j++)
		if(tab[j-1]>tab[j])
			swap(tab[j-1], tab[j]);
}

int main()
{
	vector<int> tab;

	tab.push_back(45);
	tab.push_back(123);
	tab.push_back(9);
	tab.push_back(83);

	for(int i=0;i<tab.size();i++)
		cin>>tab[i];

	sortowanie_babelkowe(tab);

	for(int i=0; i<tab.size(); i++)
		cout<<tab[i]<<" ";

	return 0;
}
