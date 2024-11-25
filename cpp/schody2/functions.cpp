#include <string>
//#TODO: tu umieść swoją funkcję

using namespace std;

string FizzBuzz(int liczba){
	string result = "";
	if(liczba % 3 == 0)
	{
		result += "Fizz";
	}

	if(liczba % 5 == 0)
	{
		result += "Buzz";
	}
	return result;
}
