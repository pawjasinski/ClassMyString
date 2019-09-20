/*
 * MyString.cpp
 *
 *  Created on: 19 wrz 2019
 *      Author: pjasinsk
 */

#include "MyString.h"
#include <cstring>

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

MyString::MyString(MyString &&_str) {
	// TODO Auto-generated constructor stub

}

MyString& MyString::operator=(const MyString &_str) {
	if(this == &_str) return *this;
	delete [] str;
	len = _str.len;
	strncpy(str, _str.str, len + 1);
	return *this;
}

MyString& MyString::operator=(MyString &&_str) {
	// TODO Auto-generated method stub

}

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

friend bool operator<() {

}

friend bool operator>() {

}

friend bool operator==(){

}

friend bool operator>>(istream& is, const MyString& _str){

}

friend ostream& operator<<(ostream& os, const MyString& _str){

}
