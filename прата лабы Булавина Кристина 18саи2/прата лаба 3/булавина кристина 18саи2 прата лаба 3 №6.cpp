#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter European-style gas mileage:";
	
	double e;
	
	cin >> e;
	
	e = e * 0.26;
	e = e / 64.12;
	e = 1 / e;
	
	cout << "American style gas mileage:" << e << endl;
	
	system("pause");
	return 0;
}