#include "pch.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
	int nameSize = 80;
	int ageSize = 2;
	char firstName[nameSize];
	char lastName[nameSize];
	char grade;
	char age[ageSize];

	cout << "What is your first name? ";
	cin.getline(firstName, nameSize);

	cout << "What is your last name? ";
	cin.getline(lastName, nameSize);

	cout << "What letter grade do you deserve? ";
	cin >> grade;

	cout << "What is your age? ";
	cin >> age;

	if (grade == 'A') {
		grade = 'B';
	}
	else if (grade == 'B') {
		grade = 'C';
	}
	else {
		grade = 'D';
	}

	cout << "\n";

	cout << "Name: " << lastName << ", " << firstName << "\n";
	cout << "Grade: " << grade << "\n";
	cout << "Age: " << age << "\n";

	return 0;
}
