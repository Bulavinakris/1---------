#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "enter your height in inches:";
	const int k = 12;
	int n;
	cin >> n;
	int l = n / k;
	int m = n - l * k;
	cout << l << " " << "foot." << endl;
	cout << m << " " << "inches." << endl;
	system("pause");
	return 0;
}