#include <iostream>
#include <pch.h>

using namespace std;

int main() {
	int rows, numberOfNotNullStb = 0, p;
	cout << "rows:";
	cin >> rows;
	int cols;
	cout << "cols:";
	cin >> cols;
	int **arr = new int*[rows];

	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			cout << "[" << i + 1 << "][" << j + 1 << "]:";
			cin >> arr[i][j];
		}

	///////////////////////////////////	
	for (int j = 0; j < cols; j++) {
		p = 1;
		for (int i = 0; i < rows; i++)
			p *= arr[i][j];
		if (p)numberOfNotNullStb++;
	}
	cout << "numberOfNotNullStb:"
		<< numberOfNotNullStb << endl;
	//////////////////////////////////
	int *sum = new int[rows];
	int *sums = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		sum[i] = 0; sums[i] = 0;
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (arr[i][j] >= 0 && arr[i][j] % 2 == 0)
				sum[i] += arr[i][j];
	///////////////////////////////////////
	for (int i = 0; i < rows; i++)
		sums[i] = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (arr[i][j] >= 0 && arr[i][j] % 2 == 0)
				sums[i] += arr[i][j];
	///////////////////////////////////
	int temp = 0;
	for (int i = 0; i < rows - 1; ++i)
		for (int j = 0; j < rows - 1; ++j)
			if (sum[j] > sum[j + 1])
			{
				temp = sum[j];
				sum[j] = sum[j + 1];
				sum[j + 1] = temp;
			}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j)
			if (sum[i] == sums[j]) {
				for (int f = 0; f < cols; ++f)
					cout << arr[j][f];
				j = rows - 1;
			}
		cout << endl;
	}
	//////////////////////////////////

	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
}
