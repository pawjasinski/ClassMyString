#include"MyString.h"
#include <cstring>

MyString::MyString()
{
	HowMany++;
	len = 0;
	str = new char[1];
	str[0] = '\n';
}
MyString::MyString(const char *s)
{
	len=strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	HowMany++;
}
MyString::MyString(const MyString & st)
{
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
}
MyString::~MyString()
{
	HowMany--;
	delete [] str;
}
MyString & MyString::operator=(const char * s)
{
	delete [] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
MyString & MyString::operator=(const MyString & st)
{
	if(this==&st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}
char & MyString::operator[](int i)
{
	return str[i];
}
char & MyString::operator[](int i) const
{
	return str[i];
}
bool operator<(const MyString str1, const MyString str2)
{
	return (strcmp(str1.str, str2.str) < 0);
}
bool operator>(const MyString str1, const MyString str2)
{
	return (strcmp(str1.str, str2.str) > 0);
}
bool operator==(const MyString str1, const MyString str2)
{
	return (strcmp(str1.str, str2.str) == 0);
}
ostream & operator<<(ostream & os, MyString & st)
{
	std::cout<<st.str;
	return os;
}
istream & operator>>(istream & is, MyString & st)
{
	char TEMP[MyString::INPUT_LIMIT];
	is.get(TEMP, MyString::INPUT_LIMIT);
	if(is)
		strcpy(st.str, TEMP);
	while( is && is.get() != '\n')
		continue;
	return is;
}
