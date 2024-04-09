#pragma once

#include <iostream>
#include <vector>


struct String
{
	std::vector<char> data;

	String();
    String(const char* str);

	void Print();
	char* ToChar();
	String operator + (String other);
	String operator + (char* other);
	void operator += (String other);
	void operator += (char* other);
	int operator < (String other);
	int operator > (String other);
	void operator * (unsigned int qnty);
};

