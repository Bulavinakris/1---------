#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {

	int nameSize = 80;
	char firstName[nameSize];
	char lastName[nameSize];

	cout << "What is your first name? ";
	cin.getline(firstName, nameSize);

	cout << "What is your last name? ";
	cin.getline(lastName, nameSize);

	char sumName[170];

	strcat(sumName, firstName);
	strcat(sumName, ", ");
	strcat(sumName, lastName);

	cout << "Here's the information in a single string: " << sumName << "\n";

	return 0;
}

