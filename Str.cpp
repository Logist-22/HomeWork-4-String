#include "Str.h"
#include<iostream>

using namespace std;


Str::Str(const char* Str, int len) : str(Str != nullptr ? new char[strlen(Str) + 1] : nullptr), len(len)
{
	if (str != nullptr)
	{
		strncpy_s(str, strlen(Str) + 1, Str, len);		// ����������� � ������������ �� ������������� ���������� �������� "len", ��� ���������� ������� "����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
		// �� ���� ������� ������ ����� 80 �������� - ������� ������ ������ 80 ������� �������, � ������� ������������� 0.
	}
	count++;
};
Str::Str() :Str(nullptr, 80) {};
Str::Str(const char* Str) : Str(Str, strlen(Str)) {};


Str::~Str()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}


void Str::setStr(const char* Str)
{
	str = new char[len];
	strncpy_s(str, strlen(Str) + 1, Str, len);
}


void Str::print()
{
	cout << "��������� ������: " << str << endl;
}


void Str::printCount()
{
	cout << "����� ������� �������� �����: " << count << endl;
}



//�������� � ��� ������������ ����� String ����������� ��������.
// �������� ���������� ���������� << �����, �������� = ������������



Str::Str(const Str& other)
{
	this->str = new char[strlen(other.str) + 1];
	strcpy_s(this->str, strlen(other.str) + 1, other.str);
	//cout << "����������� ����������� " << this << endl;
}


Str:: Str(Str&& other) : str(other.str)
{
	other.str = nullptr;
	//cout << "����������� ����������� " << this << endl;
}


Str& Str:: operator=(Str& other)
{
	if (this != &other)
	{
		delete[] this->str;
		this->str = new char[strlen(other.str) + 1];
		strcpy_s (this->str,  strlen(other.str)+1, other.str);		
	}
	return *this;
}


Str& Str:: operator=(Str&& other) 
{
	if (this != &other)
	{
		delete[] this->str;
		str=other.str;
		other.str=nullptr;
		//cout << "�������� = ������������ " << this<<endl;
	}
	return *this;
}


ostream& operator<< (ostream& out, Str& str)
{
	out << str.str;
	return out;
}


