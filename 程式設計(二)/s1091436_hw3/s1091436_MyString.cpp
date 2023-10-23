#include <iostream>
#include "s1091436_MyString.h"
using namespace std;
ostream & operator<<(ostream & output, const MyString & str)
{
	for(size_t i=0;i<str.getSize();i++)
		output << str[i];
	return output;
}
MyString::MyString()
{

}
MyString::MyString(const MyString &str)
{
	size_t i = str.getSize();
	if (i > getCapacity())
		reserve(i);
	for (size_t x = 0; x < i; x++)
	{
		push_back(str[x]);
	}
}
MyString::MyString(const char *s)
{
	reserve(strlen(s));
	for (size_t i = 0; i <=strlen(s) ; i++)
	{
		if (s[i] != '\0')
			push_back(s[i]);
		else
			break;
	}
}
MyString::MyString(const MyString &str, size_t pos, size_t len )
{
	for (size_t i = pos; i < pos+len; i++ )
	{
		push_back(str[i]);
	}
}
MyString::~MyString()
{

}
MyString & MyString::append(const MyString & str)
{
	while(getCapacity()<getSize()+str.getSize())
		reserve(getCapacity()* 2);
	for (size_t i = 0; i < str.getSize(); i++)
	{
		push_back(str[i]);
	}
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const
{
	MyString a(*this);
	MyString x;
	x.reserve(a.getSize());
	for (size_t i = pos; i < pos + len ; i++)
	{
		x.push_back(a[i]);
	}
	return x;
}
MyString&MyString::insert(size_t pos, const MyString &str)
{
	reserve(getCapacity() + str.getCapacity());
	MyString x = substr(pos, getSize() - pos -1);
	resize(pos);
	append(str);
	append(x);
	return *this;
}
MyString&MyString::erase(size_t subpos, size_t sublen)
{
	reserve(getCapacity()+sublen);
	MyString x= substr(subpos+sublen,getSize()-(subpos + sublen)+1);
	resize(subpos);
	append(x);
	return *this;
}
MyString&MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen)
{
	reserve(getCapacity() + str.getCapacity());
	MyString x = substr(pos, getSize() - pos );
	resize(pos);
	MyString y = str.substr(subpos, sublen);
	append(y);
	append(x);
	return *this;
}
size_t MyString::find(const MyString & str, size_t pos) const
{
	MyString a(*this);
	int open = 0;
	for (size_t i = pos; i < getSize(); i++)
	{
		if (a[i] == str[0])
		{
			for (size_t j = 0; j < str.getSize(); j++)
			{
				if (a[i+j] == str[j])
				{
					open = 1;
				}
				else
				{
					open = 0;
					break;
				}
			}
			if (open == 1)
			{
				return i;
			}
		}
	}
	return 999;
}
size_t MyString::find_first_of(const MyString & str, size_t pos) const
{
	MyString a(*this);
	int open = 0;
	for (size_t i = pos; i < getSize(); i++)
	{
		for (size_t j = 0; j < str.getSize(); j++)
		{
			if (a[i] == str[j])
				return i;
		}
	}
	return 999;
}
MyString operator+(const char * lhs, const MyString & rhs)
{
	MyString x;
	x.reserve(sizeof(lhs) + rhs.getCapacity());
	for (size_t i = 0; i < strlen(lhs); i++)
	{
		x.push_back(lhs[i]);
	}
	x.append(rhs);
	x.shrink_to_fit();
	return x;
}
MyString MyString::operator+(const MyString & rhs) const
{
	MyString x;
	x.reserve(getCapacity() + rhs.getCapacity());
	x.append(*this).append(rhs);
	x.shrink_to_fit();
	return x;
}
MyString & MyString::operator= (const char* s)
{
	this->clear();
	this->append(s);
	return *this;
}
MyString & MyString::operator= (const MyString& str)
{
	this->clear();
	this->append(str);
	return *this;
}
MyString MyString:: operator+ (const char* rhs) const
{
	MyString x(*this);
	for (size_t i = 0; i < strlen(rhs); i++)
	{
		x.push_back(rhs[i]);
	}
	return x;
}