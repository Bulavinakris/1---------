#include "pch.h"
#include <iostream>

using namespace std;

int main()
{

	cout << "Enter the number of miles traveled (kilometers):";
	
	double S;
	
	cin >> S;
	
	cout << "Enter the amount of spent halons (liters):";
	
	int oil;
	
	cin >> oil;
	double a = S / oil;
	double b = oil / S;
	
	cout << "For one gallon you went" << " " << a << " " << "miles" << endl;
	cout << "One kilometer you spent" << " " << b << " " << "liters" << endl;
	
	system("pause");
	return 0;
}
