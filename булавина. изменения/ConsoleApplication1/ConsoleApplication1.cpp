// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

class Library;
Library lib;

//абстрактный класс
class Printable {
public:
	virtual void printShortInfo() = 0;
	virtual void printFullInfo() = 0;
};

class Reader { //читатетель
public:
	friend void giveBookToReader(int, int);
	static int id_libCard;
	enum Status { active, freeze, writtenOut, indef }; // статус читателя в библиотеке
	// по умолчанию
	Reader() 
	{
		m_name = "noname";
		m_phoneNumber = 0;
		m_numLibraryCard = ++id_libCard;
		m_status = indef;
	};
	// с параметрами
	Reader(const char* name, int phoneNumber, Status status ) 
	{
		m_name = name;
		m_phoneNumber = phoneNumber;
		m_numLibraryCard = ++id_libCard;
		m_status = status;
	};
	// копирования
	Reader(const Reader &other) 
	{ 
		this->m_name = other.m_name;
		this->m_phoneNumber = other.m_phoneNumber;
		this->m_status = other.m_status;
		m_numLibraryCard = ++id_libCard;
		
	}
	
	int id() { return m_numLibraryCard; };
	Status getStatus() { return m_status; };
	void setStatus(Status status) { m_status = status; };
	bool isActive() { return m_status == active;};
	const char* getName() { return m_name; };
	void setName(const char* name) { m_name = name; };
	int getPhoneNumber() { return m_phoneNumber; };
	void setPhoneNumber(int phoneNumber) { m_phoneNumber = phoneNumber; };
	
	// перегрузка оператора выдать книгу читателю
	void operator <<(int NumlibStorUnit) {
		listBooks.insert(NumlibStorUnit);
		LibStorUnit* lsu=lib.getStorUnit(NumlibStorUnit);
		lsu->byUser;
		lsu->m_numLibraryCard = this->m_numLibraryCard;
	}
	// перегрузка операторов сдать книгу в библиотеку
	void operator >>(int NumlibStorUnit) {
		listBooks.erase(NumlibStorUnit);
		LibStorUnit* lsu = lib.getStorUnit(NumlibStorUnit);
		lsu->inStore;
	}
	
	~Reader() {};

private:
	const char* m_name;
	int m_phoneNumber;
	int m_numLibraryCard;  // номер читательского билета
	Status m_status;
	set<int> listBooks;   // контейнер, хранящий список идентификаторов книг, выданных читателю
};
class LibStorUnit // абстрактный класс, лит.произведение, хранящаяся в библиотеке
{
public:
	friend class Reader;
	friend void giveBookToReader(int, int); 
	enum StatusLoc { inStore, byUser, lost }; // статус книги
	static int NumlibStorUnit;
	int id() { return m_NumlibStorUnit; };
	LibStorUnit(int NumlibStorUnit) : m_status(inStore), m_numLibraryCard(NULL) {
		m_NumlibStorUnit = ++NumlibStorUnit;
	}
	void returnToStore(int numListCard) { m_status = inStore; };

private:
	int m_NumlibStorUnit; // уникальный номер лит. произведения
	StatusLoc m_status;
	int m_numLibraryCard; // if (m_reader == NULL) книга на складе в библиотеке
};

// дружественная функция
void giveBookToReader(int numLibraryCard, int NumlibStorUnit)
{
	Reader* rdr = lib.getReader(numLibraryCard);
	LibStorUnit* lsu = lib.getStorUnit(NumlibStorUnit);
	switch (lsu->m_status)
	{
	case LibStorUnit::StatusLoc::inStore:
		lsu->m_status = lsu->byUser;
		lsu->m_numLibraryCard = numLibraryCard;
		rdr->listBooks.insert(numLibraryCard);
			break;
	case LibStorUnit::StatusLoc::byUser:
		cout << "книга выдана другому читателю" << endl;
		break;
	case LibStorUnit::StatusLoc::lost:
		cout << "книга утеряна" << endl;
	}
}

// множественное наследование
class Book :public LibStorUnit, public Printable {
public:
	Book(int NumlibStorUnit, const char* name, const char* writers, const char* ISBN) : LibStorUnit(NumlibStorUnit), m_name(name), m_writers(writers), m_ISBN(ISBN) {};
	virtual void printShortInfo()
	{
		cout << "Название" << m_name << endl;
	}
	virtual void printFullInfo()
	{
		cout << "Название: " << m_name << endl;
		cout << "Автор: " << m_writers << endl;
		cout << "ISBN: " << m_ISBN << endl;
	}
private:
	const char* m_name;
	const char* m_writers;
	const char* m_ISBN;
};
class Magazine :public LibStorUnit, public Printable {
public:
	Magazine(int NumlibStorUnit, const char* name, const int num, const int year) : LibStorUnit(NumlibStorUnit), m_name(name), m_num(num), m_year(year) {};
	virtual void printShortInfo()
	{
		cout << "Название" << m_name << endl;
	}
	virtual void printFullInfo()
	{
		cout << "Название: " << m_name << endl;
		cout << "Номер: " << m_num << endl;
		cout << "Год: " << m_year << endl;
	}
private:
	const char* m_name;
	const int m_num;
	const int m_year;
};

class Library {
public:
	// встроенные класс
	// список читателей
	class ListReaders {
	public:
		void signUpLibrary(Reader* r)
		{
			if (searchReader(r->id()) == NULL)
			{
				readers.push_back(r);
				r->setStatus(Reader::active);
			}
			else
			{
				cout << "такой пользователь уже есть" << endl;
			}
		}
		Reader* searchReader(int num_lib_card)
		{
			for (Reader* i : readers)
				if (i->id() == num_lib_card) return i;
				else { return NULL; }
		}
		Reader* operator [](int numLibraryCard) {
			searchReader(numLibraryCard);
		}
		void writeOutLibrary(int num_lib_card)
		{
			Reader* r = searchReader(num_lib_card);
			if (r == NULL)
			{
				cout << "такого пользователя нет" << endl;
			}
			else
			{
				r->setStatus(Reader::writtenOut);
			}
		}
	private:
		vector<Reader*> readers;
	};
	// список лит.произведений
	class ListStorUnit {
	public:
		void add(LibStorUnit* lsu)
		{
			m_libStorUnit.push_back(lsu);
		}
		LibStorUnit* searchLibStorUnit(int NumlibStorUnit)
		{
			for (LibStorUnit* i : m_libStorUnit)
				if (i->id() == NumlibStorUnit) return i;
				else { return NULL; }
		}
	private:
		vector<LibStorUnit*> m_libStorUnit;
	};

	Reader* getReader(int numLibraryCard) { m_ListReaders[numLibraryCard]; } // использовали перегрузку []
	LibStorUnit* getStorUnit(int NumlibStorUnit) { m_ListStorUnit.searchLibStorUnit(NumlibStorUnit); }

private:
	string name;
	ListReaders m_ListReaders;
	ListStorUnit m_ListStorUnit;
};


int main()
{
	// локальный класс =)
	class  address {
	private:
		address(const char* city, const char* street, const int index): m_city(city), m_street(street), m_index(index) {}
	public:
	const char* m_city;
	const char* m_street;
	const int m_index;
	};
	setlocale(LC_ALL, "rus");
	Reader one("Игнат", 295317, Reader::Status::active);
	Reader two("Мария", 295321, Reader::Status::active);
	Book bfirst(1,"Анекдоты", "Иван", "000000333");
	Book bsecond(2, "Уроки танцев", "Петр", "000000012");
	Book bthird(3, "Сказки", "Сергей", "000001212");
	Magazine mFirst(4, "Сантехник",1,2001);
	Magazine mSecond(5, "Домохозяйки", 2, 2011);
	giveBookToReader(one.id(), bfirst.id());
	one >> bfirst.id();
	two << bsecond.id();
	two >> bsecond.id();

}