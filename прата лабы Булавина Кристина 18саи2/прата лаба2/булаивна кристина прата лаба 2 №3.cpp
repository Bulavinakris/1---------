#include "pch.h"
#include <iostream>

int first();
int second();

int main()
{
	using namespace std;

	cout << first() << endl;
	cout << first() << endl;
	cout << second() << endl;
	cout << second() << endl;

	cin.get();
	cin.get();
	return 0;

}

int first()
{
	using namespace std;
	cout << "Three blind mice\n";

	return 0;
}

int second()
{
	using namespace std;
	cout << "See how they run\n";
	return 0;
}