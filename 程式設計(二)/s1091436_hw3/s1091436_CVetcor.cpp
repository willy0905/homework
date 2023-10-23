#include <iostream>
#include "s1091436_CVector.h"
using namespace std;
ostream &operator<<(ostream& output, const CVector& vec)
{
	for (size_t i = 0; i < vec.size; i++)
	{
		output << vec.sPtr[i];
	}
	return output;
}
CVector::CVector()
{
	capacity = 10;
	size = 0;
	sPtr = new char[capacity];
}
CVector::CVector(const CVector &vec)
{
	size = sizeof(vec) / sizeof(vec[0]);
	capacity = vec.capacity;
	if (size > capacity)
		reserve(size);
	sPtr = new char[capacity];
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = vec.sPtr[i];
	}
}
CVector::~CVector()
{
	
}
size_t CVector::getSize()const
{
	return size;
}
void CVector::resize(size_t n, char c )
{
	while(n>capacity)
	{
		reserve(2 * capacity);
		for (size_t i = size; i < capacity; i++)
		{
			sPtr[i] = c;
		}
		size = capacity;
	}
	if (n < capacity)
	{
		reserve(n);
	}
	size = n;
}
void CVector::reserve(size_t n )
{
	if (n > size)
	{
		
		char *a = new char[size];
		for (size_t i = 0; i < size; i++)
		{
			a[i] = sPtr[i];
		}
		sPtr = new char[n];
		for (size_t i = 0; i < size; i++)
		{
			sPtr[i] = a[i];
		}
		delete[]a;
		capacity = n;
	}
}
void CVector::shrink_to_fit()
{
	capacity = size;
}
size_t CVector::getCapacity()const
{
	return capacity;
}
void CVector::clear()
{
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = '\0';
	}
	size = 0;
}
bool CVector::empty()const
{
	if (size == 0)
		return 0;
	else
		return 1;
}
char& CVector::front()
{
	return sPtr[0];
}
char& CVector::back()
{
	while (sPtr[size] <48)
	{
		size--;
	}
	return sPtr[size];
}
void CVector::push_back(char c)
{
	sPtr[size] = c;
	size++;
}
void CVector::pop_back()
{
	sPtr[size-1] = '\0';
	if(size!=0)
		size--;
}
char& CVector::operator[] (size_t pos)
{
	return sPtr[pos];
}
char CVector::operator[] (size_t pos) const
{
	return sPtr[pos];
}
bool CVector::operator==(const CVector &str) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (sPtr[i] != str.sPtr[i])
		{
			return false;
		}
	}
	return true;
}
bool CVector::operator!=(const CVector &str) const
{
	int x = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (sPtr[i] != str.sPtr[i])
		{
			x = 1;
		}
	}
	return x;
}