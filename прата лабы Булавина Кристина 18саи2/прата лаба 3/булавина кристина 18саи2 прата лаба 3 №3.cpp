#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	double s, min, deg;
	const int n = 60; const int k = 3600;
	
	cout << "Enter a latitude in degress,minutes, and seconds:" << endl << "First,enter the degrees:";
	cin >> deg;
	cout << "Next, enter the minutes of arc:";
	cin >> min;
	cout << "Finally, enter the seconds of arc:";
	cin >> s;
	
	double deg2 = deg + min / n + s / k;
	
	cout << deg2;
	system("pause");
	return 0;
}