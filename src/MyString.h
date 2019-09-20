/*
 * MyString.h
 *
 *  Created on: 19 wrz 2019
 *      Author: pjasinsk
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <iostream>
using std::istream;
using std::ostream;

class MyString {
private:
	char* str;
	int len;
	static size_t CINLIMIT;
public:
	MyString();
	MyString(const char* _str);

	virtual ~MyString();

	MyString(const MyString &_str);
	//MyString(MyString &&_str);
	MyString& operator=(const MyString &_str);
	//MyString& operator=(MyString &&_str);
	MyString& operator=(const char* _str);
	const char& operator[](int i) const;
	char& operator[](int i);

	int size() const;

	friend bool operator<(const MyString& st1, const MyString& st2);
	friend bool operator>(const MyString& st1, const MyString& st2);
	friend bool operator==(const MyString& st1, const MyString& st2);
	friend istream& operator>>(istream& is, MyString& _str);
	friend ostream& operator<<(ostream& os, const MyString& _str);
};

#endif /* MYSTRING_H_ */
