#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

	string firstName;
	string lastName;

	cout << "What is your first name? ";
	getline(cin, firstName);

	cout << "What is your last name? ";
	getline(cin, lastName);

	string sumName = firstName + ", " + lastName;

	cout << "Here's the information in a single string: " << sumName << "\n";

	return 0;
}
