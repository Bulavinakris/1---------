#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int foot, inch, foont;
	const int n = 12;
	const double k = 2.2;
	
	cout << "Enter the number of feet:" << endl;
	cin >> foot;
	cout << "Enter the number of inches:" << endl;
	cin >> inch;
	cout << "Enter the number of pounds: " << endl;
	cin >> foont;
	inch = foot * n + inch;
	foont = foont / k;
	
	double metr = inch * 0.0254;
	double index = foont / (metr*metr);
	
	cout << index;
	system("pause");

	return 0;
}
