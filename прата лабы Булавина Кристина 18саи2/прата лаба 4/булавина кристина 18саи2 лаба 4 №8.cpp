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

	Pizza* pizza = new Pizza();

	cout << "pizza diameter? ";
	cin >> pizza->diameter;

	cout << "company name? ";
	cin >> pizza->companyName;

	cout << "pizza weight? ";
	cin >> pizza->weight;

	cout << "\ncompany name: " << pizza->companyName << "\n";
	cout << "pizza diameter: " << pizza->diameter << "\n";
	cout << "pizza weight: " << pizza->weight << "\n";

	return 0;
}
