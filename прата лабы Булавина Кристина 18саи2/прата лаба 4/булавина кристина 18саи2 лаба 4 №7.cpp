#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Pizza {
	string companyName;
	int diameter;
	int weight;
};

int main(int argc, const char * argv[]) {

	Pizza pizza;

	cout << "company name? ";
	getline(cin, pizza.companyName);

	cout << "pizza diameter? ";
	cin >> pizza.diameter;

	cout << "pizza weight? ";
	cin >> pizza.weight;

	cout << "\ncompany name: " << pizza.companyName << "\n";
	cout << "pizza diameter: " << pizza.diameter << "\n";
	cout << "pizza weight: " << pizza.weight << "\n";

	return 0;
}

