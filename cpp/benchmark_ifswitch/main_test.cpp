#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

using namespace std;

int day = 1;

void test_if(int day) {
    if (day == 1) {
        cout << "Monday";
    } else if (day == 2) {
        cout << "Tuesday";
    } else if (day == 3) {
        cout << "Wednesday";
    } else if (day == 4) {
        cout << "Thursday";
    } else if (day == 5) {
        cout << "Friday";
    } else if (day == 6) {
        cout << "Saturday";
    } else if (day == 7) {
        cout << "Sunday";
    }
}

void test_case(int day){
    switch (day) {
      case 1:
        cout << "Monday";
        break;
      case 2:
        cout << "Tuesday";
        break;
      case 3:
        cout << "Wednesday";
        break;
      case 4:
        cout << "Thursday";
        break;
      case 5:
        cout << "Friday";
        break;
      case 6:
        cout << "Saturday";
        break;
      case 7:
        cout << "Sunday";
        break;
    }
}

TEST(BenchmarkTest, IfBenchmark)
{
	auto start = chrono::high_resolution_clock::now();

    test_if(day);

	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;

	cout << "Czas dla instrukcji if: " << elapsed_seconds.count() << "s" << endl;
}

TEST(BenchmarkTest, CaseBenchmark)
{
	auto start = chrono::high_resolution_clock::now();

    test_case(day);

	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;

    cout << "Czas dla instrukcji case: " << elapsed_seconds.count() << "s" << endl;
}

int main(int argc, char **argv)
{
	cout << "Podaj liczbe (1-7): ";
	cin >> day;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
