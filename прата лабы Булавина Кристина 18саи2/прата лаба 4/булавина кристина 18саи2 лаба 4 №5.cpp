#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
	string name;
	double weight;
	int calories;
};

int main(int argc, const char * argv[]) {

	CandyBar snack;
	snack.name = "Mocha Munich";
	snack.weight = 2.3;
	snack.calories = 350;

	cout << "candy name: " << snack.name << "\n";
	cout << "candy weight: " << snack.weight << "\n";
	cout << "candy calories: " << snack.calories << "\n";

	return 0;
}

