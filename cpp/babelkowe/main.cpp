#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& vec){
    int i, j;
    bool swapped;

    for(i = 0; i < vec.size() - 1; i++)
    {
	    swapped = false;
	    for(j = 0; j < vec.size() - i - 1; j++)
	    {
		if(vec[j] > vec[j + 1])
		{
		    swap(vec[j], vec[j + 1]);
		    swapped = true;
		}
	    }

	    if(swapped == false)
	    {
		break;
	    }

    }
}

void PrintVector(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
	cout<<" "<<vec[i];
    }
}

int main()
{
    vector<int> vec;
    int n;

    cout << "Podaj ilosc elementow: ";
    cin >> n;
    
    //values for loop
    int elem;

    for(int i = 0; i < n; i++)
   {
	cout << "Podaj element:";
	cin >> elem; 
	vec.push_back(elem);
   } 
    BubbleSort(vec);

    cout << "Posortowany wektor: ";
    PrintVector(vec);
    
    return 0;
 
}
