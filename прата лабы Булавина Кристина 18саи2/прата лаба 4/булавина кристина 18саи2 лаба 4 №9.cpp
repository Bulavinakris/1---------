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

	CandyBar* candryArray[3];

	CandyBar *snack1 = new CandyBar;
	snack1->name = "Mocha Munich";
	snack1->weight = 2.3;
	snack1->calories = 350;

	candryArray[0] = snack1;

	CandyBar *snack2 = new CandyBar;
	snack2->name = "Mars";
	snack2->weight = 0.3;
	snack2->calories = 1450;

	candryArray[1] = snack2;

	CandyBar *snack3 = new CandyBar;
	snack3->name = "Iriska";
	snack3->weight = 0.4;
	snack3->calories = 3450;

	candryArray[2] = snack3;

	for (int i = 0; i < (sizeof(candryArray) / sizeof(CandyBar*)); i++) {
		cout << "candy name: " << candryArray[i]->name << "\n";
		cout << "candy weight: " << candryArray[i]->weight << "\n";
		cout << "candy calories: " << candryArray[i]->calories << "\n";
		cout << "\n";
	}

	return 0;
}

