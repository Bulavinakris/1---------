#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;

double convert(double l)
{
	return l * 63240;
}

int main()
{
	double a, l;
	cout << "Enter the number of light years: ";
	cin >> l;
	a = convert(l);
	cout << l << " " << "light years = " << " " << a << " " << "astonomical units" << endl;
	system("pause");
	return 0;
}
