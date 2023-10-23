#include <fstream>
#include <iostream>
#include <cmath>
#include "s1091436_BigNUMv4.h"
using namespace std;
template <typename T>
Array< T >::Array()
{
	capacity = 10;
	size = 0;
	sPtr = new int[capacity];
}
template <typename T>
Array< T >::Array(T & vec)
{
	size = vec.size;
	capacity = vec.capacity;
	if (size > capacity)
		reserve(size);
	sPtr = new int[capacity];
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = vec.sPtr[i];
	}
}
template <typename T>
int Array< T >::getSize()const
{
	return size;
}
template<typename T>
int Array<T>::getnum(int x)const
{
	return sPtr[x];
}
template <typename T>
void  Array< T >::resize(int n, char c)
{
	while (n > capacity)
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
template <typename T>
void  Array< T >::reserve(int n)
{
	if (n > size)
	{
		int *a = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			a[i] = sPtr[i];
		}
		sPtr = new int[n];
		for (size_t i = 0; i < size; i++)
		{
			sPtr[i] = a[i];
		}
		delete[]a;
		capacity = n;
	}
}
template <typename T>
void  Array< T >::shrink_to_fit()
{
	capacity = size;
}
template <typename T>
int  Array< T >::getCapacity()const
{
	return capacity;
}
template <typename T>
void  Array< T >::clear()
{
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = '\0';
	}
	size = 0;
}
template <typename T>
void Array< T >::push_back(int c)
{
	if (size + 1 > capacity)
		reserve(capacity*2);
	sPtr[size] = c;
	size++;
}
template <typename T>
void Array< T >::pop_back()
{
	sPtr[size - 1] = '\0';
	if (size != 0)
		size--;
}
template <typename T>
bool  Array< T >::operator==(const Array< T > &str) const
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
template <typename T>
bool Array< T >::operator!=(const Array< T > &str) const
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
template <typename T>
ostream & operator<<(ostream & output, const Array<T> & vec)
{
	for (size_t i = 0; i < vec.size; i++)
	{
		output << vec.sPtr[i];
	}
	return output;
}
ostream & operator<<(ostream & output, const BigNUM & vec)
{
	for (int i = vec.getSize()-1; i >=0; i--)
	{
		if (vec.getnum(i) < 100&&i!=vec.getSize() - 1)
		{
			output << "0";
		}
		if (vec.getnum(i) < 10 && i != vec.getSize() - 1)
		{
			output << "0";
		}
		output << vec.getnum(i);
		output << " ";
	}
	return output;
}
istream & operator>>(istream & intput,  BigNUM & vec)
{
	string x;
	int num=0,size=0;
	getline(intput, x);
	for (int i = x.size(); i >=0; i--)
	{
		if (x[i] >= '0'&&x[i] <= '9')
		if (x[i] >= '0'&&x[i] <= '9')
		{
			num += (x[i]-48) * pow(10, size);
			size++;
			if (size % 3 == 0)
			{
				vec.push_back(num);
				size = 0;
				num = 0;
			}
		}
		
	}
	if (size != 0)
	{
		vec.push_back(num);
	}
	return intput;
}
BigNUM::BigNUM(string x)
{
	char a;
	int b=0,c=0,d=0,sum,s=0;
	char y[100] = { 0 };
	fstream file;
	file.open(x,ios::in);
	if (!file)
	{
		for (int i = x.size() - 1; i >= 0; i -= 3)
		{
			b = x[i]-48;
			c = 0;
			d = 0;
			if (i - 1 >= 0)
			{
				c = (x[i - 1]-48) * 10;
			}
			if (i - 2 >= 0)
			{
				d = (x[i - 2]-48)*100 ;
			}
			sum = b + c + d;
			push_back(sum);
		}
	}
	else
	{
 		while (file.get(a))
		{
			y[s] = a;
			s++;
		}
		file.close();
		for (int i = s-1 ; i >= 0; i-=3)
		{
			sum = 0;
			b = y[i] - 48;
			c = 0;
			d = 0;
			if (i - 1 >= 0)
			{
				c = (y[i - 1] - 48)*10 ;
			}
			if (i - 2 >= 0)
			{
				d = (y[i - 2] - 48) * 100;
			}
			sum = b + c + d;
			push_back(sum);
		}
	}
}
BigNUM& BigNUM::operator=( BigNUM &str)
{
	this->clear();
	for (int i = 0; i < str.getSize(); i++)
	{
		push_back(str.getnum(i));
	}
	return *this;
}
BigNUM BigNUM::operator-(BigNUM &str)
{
	BigNUM x;
	x.clear();
	int check = 0;
	int sum[100] = { 0 }, len = 0;
	if (getSize() >= str.getSize())
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (i >= str.getSize())
			{
				if (check == 1)
				{
					sum[len] = getnum(i) - 1;
					check = 0;
				}
				else
					sum[len] = getnum(i);
			}
			else
			{
				if (getnum(i) >= str.getnum(i))
				{
					if (check == 1)
						sum[len] = getnum(i) - str.getnum(i) - 1;
					else
					{
						sum[len] = getnum(i) - str.getnum(i);
					}
					check = 0;
				}
				else
				{
					if (check == 1)
						sum[len] = 1000 + getnum(i) - str.getnum(i) - 1;
					else
					{
						sum[len] = 1000 + getnum(i) - str.getnum(i);
					}
					check = 1;
				}
			}
			len++;
		}
		while (sum[len - 1]==0)
		{
			len--;
		}
		for (int i = 0; i < len; i++)
		{
			x.push_back(sum[i]);
		}
	}
	else
	{
		for (int i = 0; i < str.getSize(); i++)
		{
			if (i >= getSize())
			{
				if (check == 1)
				{
					sum[len] = str.getnum(i) - 1;
					check = 0;
				}
				else
					sum[len] = str.getnum(i);
			}
			else
			{
				if (str.getnum(i) >= getnum(i))
				{
					if (check == 1)
						sum[len] = str.getnum(i) -getnum(i) - 1;
					else
					{
						sum[len] = str.getnum(i) - getnum(i);
					}
					check = 0;
				}
				else
				{
					if (check == 1)
						sum[len] =1000+ str.getnum(i) - getnum(i) - 1;
					else
					{
						sum[len] =1000+ str.getnum(i) - getnum(i);
					}
					check = 1;
				}
			}
			if(i==str.getSize()-1)
				x.push_back(-sum[len]);
			else
				x.push_back(sum[len]);
			len++;
		}
	}
	return x;
}
BigNUM & BigNUM::operator-=(BigNUM &str)
{
	BigNUM a(*this-str);
	int x=1;
	while (a.getnum(getSize() - x) == 0)
	{
		x++;
	}
	BigNUM b;
	for (int i = 0; i <= a.getSize() - x; i++)
	{
		b.push_back(a.getnum(i));
	}
	if (x == 1)
		*this = a;
	else
		*this = b;
	return *this;
}
BigNUM BigNUM::operator+( BigNUM& str)
{
	BigNUM x;
	x.clear();
	int check = 0;
	if (getSize() >= str.getSize())
	{
		int sum[100] = { 0 },len=0;
		for (int i = 0; i < getSize(); i++)
		{
			if (i >= str.getSize())
			{
				sum[len] = getnum(i);
				if (check == 1)
				{
					sum[len] += 1;
					check = 0;
				}
			}
			else
			{
				sum[len] = getnum(i) + str.getnum(i);
				if (check == 1)
				{
					sum[len] += 1;
					check = 0;
				}
			}
			if (sum[len] > 1000)
			{
				sum[len] -= 1000;
				check = 1;
			}
			x.push_back(sum[len]);
			len++;
		}
	}
	else
	{
		int sum[100] = { 0 }, len = 0;
		for (int i = 0; i < str.getSize(); i++)
		{
			if (i >= getSize())
			{
				sum[len] = str.getnum(i);
				if (check == 1)
				{
					sum[len] += 1;
					check = 0;
				}
			}
			else
			{
				sum[len] = getnum(i) + str.getnum(i);
				if (check == 1)
				{
					sum[len] += 1;
					check = 0;
				}
			}
			if (sum[len] > 1000)
			{
				sum[len] -= 1000;
				check = 1;
			}
			x.push_back(sum[len]);
			len++;
		}
	}
	return x;
}
bool BigNUM::operator>=(BigNUM & str)const
{
	if ((getSize() > str.getSize())) 
	{
		return true;
	}
	else if ((getSize() < str.getSize()))
	{
		return false;
	}
	else
	{
		for (int i = getSize() - 1; i >= 0; i--)
		{
			if (getnum(i) > str.getnum(i))
			{
				return true;
			}
			else if (getnum(i) < str.getnum(i))
			{
				return false;
			}
		}
	}
	return true;
}
bool BigNUM::operator==(BigNUM &str)const
{
	for (int i = getSize() - 1; i >= 0; i--)
	{
		if (getnum(i) != str.getnum(i))
		{
			return false;
		}
	}
	return true;
}

bool BigNUM::operator<=(BigNUM &str)const
{
	if (getSize() > str.getSize())
	{
		return false;
	}
	else if (getSize() < str.getSize())
	{
		return true;
	}
	else
	{
		for (int i = getSize() - 1; i >= 0; i--)
		{
			if (getnum(i) > str.getnum(i))
			{
				return false;
			}
			else if (getnum(i) < str.getnum(i))
			{
				return true;
			}
		}
	}
	return true;
}

void BigNUM::Swap(BigNUM &str1, BigNUM &str2)
{
	BigNUM temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
	
}
bool BigNUM::operator>(BigNUM & str)const
{
	if ((getSize() > str.getSize())&&(getnum(getSize()-1)!=0))
	{
		return true;
	}
	else if ((getSize() < str.getSize()) && (getnum(getSize() - 1)) < 0 || getnum(getSize() - 1) == 0)
	{
		return false;
	}
	else
	{
		for (int i = getSize() - 1; i >= 0; i--)
		{
			if (getnum(i) > str.getnum(i))
			{
				return true;
			}
			else if (getnum(i) < str.getnum(i))
			{
				return false;
			}
		}
	}
	return false;
}
BigNUM BigNUM::operator/(BigNUM& str)
{
	string zero = "0";
	string ten = "10";
	BigNUM x(zero);
	BigNUM y(ten);
	BigNUM a;
	a = *this;
	BigNUM ans;
	BigNUM b ;
	b = str;
	int num = 0, len = 0, num1[100] = { 0 }, len1 = 0, time = 0, num2[100] = { 0 }, len2 = 0;
	if (getSize() < str.getSize())
	{
		return x;
	}
	else if(getSize() == str.getSize())
	{
		for (int i = getSize() - 1; i >= 0; i--)
		{
			if (getnum(i) < str.getnum(i))
			{
				return x;
			}
			if (getnum(i) > str.getnum(i))
			{
				break;
			}
		}
		while (a >= str )
		{
			a -= str;
			num++;
		}
		ans.push_back(num);
		return ans;
	}
	else
	{
		while (b*y < a)
		{
			b *= y;
			time++;
		}
		for (int i = time; i >= 0; i--)
		{
			b = str;
			for (int j = 0; j < i; j++)
			{
				b *= y;
			}
			while (a>=b)
			{
				a -= b;
				num1[len]++;
			}
			len++;
		}
		for (int i = len - 1; i >= 0; i-=3)
		{
			if (i >= 2)
			{
				num2[len2] += num1[i] + num1[i - 1] * 10 + num1[i - 2]*100;
			}
			if (i == 1)
			{
				num2[len2] += num1[i] + num1[i - 1] * 10 ;
			}
			if (i == 0)
			{
				num2[len2] += num1[i] ;
			}
			len2++;
		}
		for (int i = 0; i < len2; i++)
		{
			ans.push_back(num2[i]);
		}
		return ans;
	}
}
BigNUM BigNUM::operator*(BigNUM&str)
{
	BigNUM x;
	x.clear();
	int size = 0;
	int tmp[100] = { 0 };
	if (getSize() >= str.getSize())
	{
		for (int i = 0; i < getSize(); i++)
		{
			for (int j = 0; j < str.getSize(); j++)
			{
				tmp[i + j] += getnum(i)*str.getnum(j);
			}
		}
		for (int i = 0; i < getSize() + str.getSize(); i++)
		{
			if (tmp[i] >= 1000)
			{
				tmp[i + 1] += tmp[i] / 1000;
				tmp[i] %= 1000;
			}
			if (i == getSize() + str.getSize() - 1 && tmp[i] == 0)
			{

			}
			else
				x.push_back(tmp[i]);
		}
	}
	else
	{
		for (int i = 0; i < str.getSize(); i++)
		{
			for (int j = 0; j < getSize(); j++)
			{
				tmp[i + j] += str.getnum(i)*getnum(j);
			}
		}
		for (int i = 0; i < getSize() + str.getSize(); i++)
		{
			if (tmp[i] >= 1000)
			{
				tmp[i + 1] += tmp[i] / 1000;
				tmp[i] %= 1000;
			}
			if (i == getSize() + str.getSize() - 1 && tmp[i] == 0)
			{

			}
			else
				x.push_back(tmp[i]);
		}
	}
	return x;
}
BigNUM & BigNUM::operator*=(BigNUM str)
{
	int size = 0,size1=getSize();
	int tmp[100] = { 0 };
	if (getSize() >= str.getSize())
	{
		for (int i = 0; i < getSize(); i++)
		{
			for (int j = 0; j < str.getSize(); j++)
			{
				tmp[i + j] += getnum(i)*str.getnum(j);
			}
		}
	}
	else
	{
		for (int i = 0; i < str.getSize(); i++)
		{
			for (int j = 0; j < getSize(); j++)
			{
				tmp[i + j] += str.getnum(i)*getnum(j);
			}
		}
	}
	for (int i = 0; i < getSize() + str.getSize(); i++)
	{
		if (tmp[i] >= 1000)
		{
			tmp[i + 1] += tmp[i] / 1000;
			tmp[i] %= 1000;
		}
	}
	clear();
	for (int i = 0; i < size1 + str.getSize(); i++)
	{
		if (i ==size1 + str.getSize() - 1 && tmp[i] == 0)
		{

		}
		else
			push_back(tmp[i]);
	}
	return *this;
}
bool BigNUM::operator<(BigNUM & str)const
{
	if (getSize() < str.getSize())
	{
		return true;
	}
	else if (getSize() > str.getSize())
	{
		return false;
	}
	else
	{
		for (int i = getSize() - 1; i >= 0; i--)
		{
			if (getnum(i) < str.getnum(i))
			{
				return true;
			}
			else if (getnum(i) > str.getnum(i))
			{
				return false;
			}
		}
	}
	return true;
}
BigNUM BigNUM::operator%(BigNUM&str)
{
	BigNUM a;
	a = *this;
	BigNUM b(a/str);
	BigNUM c(b*str);
	BigNUM d(a - c);
	return d;
}
BigNUM BigNUM::GCD(BigNUM str1, BigNUM str2)
{
	BigNUM zero("0");
	BigNUM a;
	a = str1;
	BigNUM b;
	b = str2;
	while (a != zero && b != zero)
	{
		if (a >= b)
		{
			a %= b;
		}
		else if (b > a)
		{
			b %= a;
		}
	}

	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}

}
BigNUM& BigNUM::operator%=(BigNUM str)
{
	BigNUM a;
	a = *this;
	BigNUM b;
	b = str;
	BigNUM c(a%b);
	*this = c;
	return *this;
}
BigNUM BigNUM::LCM(BigNUM str1, BigNUM str2)
{
	BigNUM a;
	a = str1;
	BigNUM b;
	b = str2;
	BigNUM c;
	BigNUM d(a*b);
	BigNUM e = c.GCD(a, b);
	BigNUM f(d / e);
	return f;
}