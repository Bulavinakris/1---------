// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "введите длину массива: ";
	int n:
	cin >> n;
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "введите " << i + 1 << "элемент: ";
		cin >> arr[i];
	}
	double max_abs = 0;
	for (int i = 0; i < n; i++) {
		if (abs(arr[i]) > abs(max_abs))
			max_abs = arr[i];
	}
	cout << "элемент массима максимальный по модулю: "
		<< max_abs << endl << endl;
	double sum = 0;
	bool state = 0;
	for (int i=0; i )
}

