#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
	setlocale(LC_ALL, "Russian");
	string name;
	string dessert;
	cout << "Введите ваше имя: \n";
	getline(cin, name);
	cout << "Введите ваш любимый десерт \n";
	getline(cin, dessert);
	cout << "У меня есть вкусный " << dessert;
	cout << " для вас, " << name << ".\n";

	return 0;
}
