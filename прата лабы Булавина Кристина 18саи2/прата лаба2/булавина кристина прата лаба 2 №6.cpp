#include "pch.h"
#include <iostream>
using namespace std;

void time()
{
	int hours, min;
	cout << "Enter the number of hours: ";
	cin >> hours;
	cout << "Enter the number of minutes: ";
	cin >> min;
	cout << "Time: " << hours << ":" << min << endl;
	system("pause");
}

int main()
{
	time();
	return 0;
}