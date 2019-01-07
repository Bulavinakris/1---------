// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	ifstream file;
	file.open("london.DAT");
	if (!file.is_open()) {
		cout << "не удалось открыть файл \"london.DAT\" " << endl;
		exit(EXIT_FAILURE);
	}
	char ch;
	while (file.read(&ch, 1)) cout << ch;
	cout << endl << endl;
	file.clear();	
	file.seekg(0);

	int cnt = 0;
	_getch();
	int lastch = 0;
	while (file.read(&ch, 1)) 
		if (ch != ' ' && ch != ',' && ch != '.' && ch != '!' && ch != '?' && ch !='\n') {
			cout << ch;
			lastch = 1;
		}
		else {
			if (lastch) {
				cnt++;
				cout << endl;
				lastch = 0;
				_getch();
			}
		}
		
		cout << "Количество слов в тексте: " << cnt << endl;



	return 0;
}