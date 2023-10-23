#include <iostream>
#include "s1091436_Container.h"
using namespace std;
istream &operator>>(istream &a, Container &b)
{
	int x;
	for (int i = 0; i < b.len; i++)
	{
		a >> x;
		if (x == -1)
			break;
		else
		{
			b.size[i] = x;
		}
	}
	return a;
}
ostream &operator<<(ostream &a, Container b) {
	for (int i = 0; i < b.len; i++)
	{
		a << b.size[i] << " ";
	}
	a << "\n";
	return a;
}
Container::Container(int x)
{
	size = new int[x];
	len = x;
	for (int i = 0; i < len; i++)
	{
		size[i] = 0;
	}
}
void Container::push(int num)
{
	if (size[len-1] != 0)
		determine = 1;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (size[i] == 0)
			{
				size[i] = num;
				determine = 0;
				break;
			}

		}
	}
}
int Container::pop()
{
	int x=0;
	if (size[0] == 0)
	{
		determine = 2;
	}
	else
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (size[i] != 0)
			{
				x = size[i];
				size[i] = 0;
				determine = 0;
				break;
			}
		}
	}
	return x;
}
void Container::resize(int x)
{
	int *y = new int[x];
	for (int i = 0; i < x; i++)
	{
		y[i] = size[i];
	}
	delete[]size;
	size = new int[x];
	for (int i = 0; i < x; i++)
	{
		if (i >= len)
		{
			size[i] = 0;
		}
		else
		{
			size[i] = y[i];
		}
	}
	delete[]y;
	len = x;
}
Container Container::operator+(int x)
{
	push(x);
	return *this;
}
Container Container::operator+(const Container&b)
{
	Container x(len + b.len);
	for (int i = 0; i < len; i++)
	{
		x.push(size[i]);
	}
	for (int i = 0; i < b.len; i++)
	{
		x.push(b.size[i]);
	}
	return x;
}
Container Container::cat( Container &a,const Container &b)
{
	a.resize(a.len + b.len);
	for (int i = 0; i < b.len; i++)
	{
		a.push(b.size[i]);
	}
	return a;
}
void Container::printALL()
{
	for (int i = 0; i < len; i++)
	{
		cout << size[i] << " ";
	}
	if (determine == 1)
	{
		cout << "(Push Fail!)\n";
	}
	else if (determine == 2)
	{
		cout << "(Pop Fail!)\n";
	}
	else
	{
		cout << "\n";
	}
	determine = 0;
}