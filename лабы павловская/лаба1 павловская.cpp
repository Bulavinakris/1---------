// лаба1 павловская.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#pragma hdrstop
#pragma argsused 

using namespace std; 

int main(int argc, char* argv[])
{
	int ac, bc, cc,i = 0;
	double a, b, c, x, xn, xk, dx, F;
	cout << "enter a: ";
	cin>>a;
	cout << "enter b: ";
	cin>>b;
	cout << "enter c: ";
	cin>>c;
	cout << "enter x: ";
	cin>>x;
	cout << "enter xn: ";
	cin>>xn;
	cout << "enter xk: ";
	cin >> xk;
	cout << "enter dx: ";
	cin >> dx;
	ac = a; bc = b; cc = c;
	cout << "\n\nn X" << '|' << "F" << endl << endl;
	for (x = xn; x <= xk; x += dx)
	{
		if ((x + 5 < 0) && (c == 0)) F = 1. / a * x - b;
		if ((x + 5 > 0) && (c != 0)) F = (x - a) / x;
		else F = 10 * x / (c - 4);
		if (((ac&bc) | (bc&cc)) != 0) {
			cout << ++i << "|" << x << "|" << F << endl;
		}
		else cout << ++i << "|" << x << "|" << int(F) << endl;
	}
	return 0;
}
