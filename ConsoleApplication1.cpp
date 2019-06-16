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

//����������� �����
class Printable {
public:
	virtual void printShortInfo() = 0;
	virtual void printFullInfo() = 0;
};

class Reader { //����������
public:
	friend void giveBookToReader(int, int);
	static int id_libCard;
	enum Status { active, freeze, writtenOut, indef }; // ������ �������� � ����������
	// �� ���������
	Reader() 
	{
		m_name = "noname";
		m_phoneNumber = 0;
		m_numLibraryCard = ++id_libCard;
		m_status = indef;
	};
	// � �����������
	Reader(const char* name, int phoneNumber, Status status ) 
	{
		m_name = name;
		m_phoneNumber = phoneNumber;
		m_numLibraryCard = ++id_libCard;
		m_status = status;
	};
	// �����������
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
	
	// ���������� ��������� ������ ����� ��������
	void operator <<(int NumlibStorUnit) {
		listBooks.insert(NumlibStorUnit);
		LibStorUnit* lsu=lib.getStorUnit(NumlibStorUnit);
		lsu->byUser;
		lsu->m_numLibraryCard = this->m_numLibraryCard;
	}
	// ���������� ���������� ����� ����� � ����������
	void operator >>(int NumlibStorUnit) {
		listBooks.erase(NumlibStorUnit);
		LibStorUnit* lsu = lib.getStorUnit(NumlibStorUnit);
		lsu->inStore;
	}
	
	~Reader() {};

private:
	const char* m_name;
	int m_phoneNumber;
	int m_numLibraryCard;  // ����� ������������� ������
	Status m_status;
	set<int> listBooks;   // ���������, �������� ������ ��������������� ����, �������� ��������
};
class LibStorUnit // ����������� �����, ���.������������, ���������� � ����������
{
public:
	friend class Reader;
	friend void giveBookToReader(int, int); 
	enum StatusLoc { inStore, byUser, lost }; // ������ �����
	static int NumlibStorUnit;
	int id() { return m_NumlibStorUnit; };
	LibStorUnit(int NumlibStorUnit) : m_status(inStore), m_numLibraryCard(NULL) {
		m_NumlibStorUnit = ++NumlibStorUnit;
	}
	void returnToStore(int numListCard) { m_status = inStore; };

private:
	int m_NumlibStorUnit; // ���������� ����� ���. ������������
	StatusLoc m_status;
	int m_numLibraryCard; // if (m_reader == NULL) ����� �� ������ � ����������
};

// ������������� �������
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
		cout << "����� ������ ������� ��������" << endl;
		break;
	case LibStorUnit::StatusLoc::lost:
		cout << "����� �������" << endl;
	}
}

// ������������� ������������
class Book :public LibStorUnit, public Printable {
public:
	Book(const char* name, const char* writers, const char* ISBN) : LibStorUnit(NumlibStorUnit), m_name(name), m_writers(writers), m_ISBN(ISBN) {};
	virtual void printShortInfo()
	{
		cout << "��������" << m_name << endl;
	}
	virtual void printFullInfo()
	{
		cout << "��������: " << m_name << endl;
		cout << "�����: " << m_writers << endl;
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
		cout << "��������" << m_name << endl;
	}
	virtual void printFullInfo()
	{
		cout << "��������: " << m_name << endl;
		cout << "�����: " << m_num << endl;
		cout << "���: " << m_year << endl;
	}
private:
	const char* m_name;
	const int m_num;
	const int m_year;
};

class Library {
public:
	// ���������� �����
	// ������ ���������
	class ListReaders {
	public:
		void signUpLibrary(Reader* r)
		{
			if (searchReader == NULL)
			{
				readers.push_back(r);
				r->setStatus(Reader::active);
			}
			else
			{
				cout << "����� ������������ ��� ����" << endl;
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
				cout << "������ ������������ ���" << endl;
			}
			else
			{
				r->setStatus(Reader::writtenOut);
			}
		}
	private:
		vector<Reader*> readers;
	};
	// ������ ���.������������
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

	Reader* getReader(int numLibraryCard) { m_ListReaders.searchReader(numLibraryCard); }
	LibStorUnit* getStorUnit(int NumlibStorUnit) { m_ListStorUnit.searchLibStorUnit(NumlibStorUnit); }

private:
	string name;
	ListReaders m_ListReaders;
	ListStorUnit m_ListStorUnit;
};


int main()
{
	// ��������� ����� =)
	class  address {
	private:
		address(const char* city, const char* street, const int index): m_city(city), m_street(street), m_index(index) {}
	public:
	const char* m_city;
	const char* m_street;
	const int m_index;
	};
	

}