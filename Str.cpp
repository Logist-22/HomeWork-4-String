#include "Str.h"
#include<iostream>

using namespace std;


Str::Str(const char* Str, int len) : str(Str != nullptr ? new char[strlen(Str) + 1] : nullptr), len(len)
{
	if (str != nullptr)
	{
		strncpy_s(str, strlen(Str) + 1, Str, len);		// копирование с ограничением по максимальному получеству символом "len", дл€ выполнени€ задани€ " онструктор по умолчанию, позвол€ющий создать строку длиной 80 символов;
		// не даст создать строку более 80 символов - запишет только первые 80 включа€ пробелы, и добавит терминирующий 0.
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
	cout << "«аписанн€ строка: " << str << endl;
}


void Str::printCount()
{
	cout << "¬сего создано объектов строк: " << count << endl;
}



//ƒобавить в уже существующий класс String конструктор переноса.
// ƒобавить перегрузку операторов << вывод, оператор = перемещением



Str::Str(const Str& other)
{
	this->str = new char[strlen(other.str) + 1];
	strcpy_s(this->str, strlen(other.str) + 1, other.str);
	//cout << " онструктор копировани€ " << this << endl;
}


Str:: Str(Str&& other) : str(other.str)
{
	other.str = nullptr;
	//cout << " онструктор перемещени€ " << this << endl;
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
		//cout << "ќператор = перемещением " << this<<endl;
	}
	return *this;
}


ostream& operator<< (ostream& out, Str& str)
{
	out << str.str;
	return out;
}


