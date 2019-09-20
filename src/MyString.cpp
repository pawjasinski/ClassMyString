/*
 * MyString.cpp
 *
 *  Created on: 19 wrz 2019
 *      Author: pjasinsk
 */

#include "MyString.h"
#include <cstring>
#include <iomanip>

size_t MyString::CINLIMIT = 100;

MyString::MyString() {
	len = 0;
	str = new char[1];
	*(str) = '\0';
}

MyString::MyString(const char* _str): len(0) {
	len = strlen(_str);
	str = new char[len + 1];
	strncpy(str, _str, len + 1);
}

MyString::~MyString() {
	delete [] str;
	len = 0;
}

MyString::MyString(const MyString &_str) {
	len = _str.len;
	str = new char[len + 1];
	strncpy(str, _str.str, len + 1);
}

//MyString::MyString(MyString &&_str) {
	// TODO Auto-generated constructor stub

//}

MyString& MyString::operator=(const MyString &_str) {
	if(this == &_str) return *this;
	delete [] str;
	len = _str.len;
	strncpy(str, _str.str, len + 1);
	return *this;
}

//MyString& MyString::operator=(MyString &&_str) {
	// TODO Auto-generated method stub

//}

MyString& MyString::operator=(const char* _str) {
	len = strlen(_str);
	str = new char[len + 1];
	strncpy(str, _str, len + 1);
	return *this;
}

const char& MyString::operator[](int i) const {
	return str[i];
	}

char& MyString::operator[](int i) {
	return str[i];
	}

int MyString::size() const {
	return len;
}

bool operator<(const MyString& st1, const MyString& st2) {
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const MyString& st1, const MyString& st2) {
	return st2 < st1;
}

bool operator==(const MyString& st1, const MyString& st2) {
	return (strcmp(st1.str, st2.str) == 0);
}

istream& operator>>(istream& is, MyString& _str) {
	char x[MyString::CINLIMIT];
	is >> std::setw(MyString::CINLIMIT);
	if(is) _str = x;
	return is;
}

ostream& operator<<(ostream& os, const MyString& _str) {
	os << _str.str;
	return os;
}
