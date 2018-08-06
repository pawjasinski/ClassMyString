#ifndef MyString_h_
#define MString_h_

#include <iostream>
using std::ostream;
using std::istream;

class MyString
{
private:
	static int HowMany;
	static const int INPUT_LIMIT = 80;
	char* str;
	int len;
public:
	MyString();
	MyString(const char *s);
	MyString(const MyString & st);
	~MyString();
	MyString & operator=(const char * s);
	MyString & operator=(const MyString & st);
	char & operator[](int i);
	char & operator[](int i) const;
	friend bool operator<(const MyString str1, const MyString str2);
	friend bool operator>(const MyString str1, const MyString str2);
	friend bool operator==(const MyString str1, const MyString str2);
	friend ostream& operator<<(ostream & os, MyString & st);
	friend istream& operator>>(istream & is, MyString & st);
};

#endif
