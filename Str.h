#pragma once
#include<iostream>
using namespace std;



class Str
{
private:
	char* str;
	int len;

public:
	Str();
	Str(const char* Str);
	Str(const char* Str, const int len);

	~Str();

	static int count;

	void setStr(const char* Str);

	char* getStr()
	{
		return str;
	}

	int GetLen()
	{
		return len;
	}

	static int getCount()
	{
		return count;
	}

	void print();
	void printCount();



	Str(const Str& other);
	Str(Str&& other);

	Str& operator=(Str&& other);
	Str& operator=(Str& other);

	friend ostream& operator<< (ostream& out, Str& str);
};

