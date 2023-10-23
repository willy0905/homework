#include <iostream>
#include <stdlib.h> //srand(), rand()
#include <time.h>   //time()
#include "s1091436_Date.h"
using namespace std;
inline Date::Date()
{
	setDate(year, month, day);
}
inline void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
inline int Date::getYear()
{
	year = rand() % 22 + 1999;
	return  year;//1999-2021
}
inline int Date::getMonth()
{
	if(year==2021)
		month = rand() % 3 + 1;
	else
		month = rand() % 12 + 1;
	return month; //1-12
}
inline int Date::getDay()
{
	int m, y;
	m = month;
	y = year;
	if (y == 2021 && m == 3)
		return rand() % 11 + 1;
	else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return rand() % 31 + 1; //1-31
	else if (m != 2)
		return rand() % 30 + 1; //1-30
	else if (y % 4 == 0)
		return rand() % 29 + 1; //1-29
	else
		return rand() % 28 + 1; //1-28
}
inline bool Date::earlier(const Date&date2)
{
	if (year > date2.year || (year == date2.year&&month > date2.month) || (year == date2.year&&month == date2.month&&day > date2.day))
	{
		return 1;
	}
	else
		return 0;
}
inline int Date::distance(const Date&date2)
{
	int x[3], y[3];
	int m[11] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
	int a, d1 = 0, d2 = 0, sum = 0, b = 1;
	x[0] = year;
	x[1] = month;
	x[2] = day;
	y[0] = date2.year;
	y[1] = date2.month;
	y[2] = date2.day;
	for (int i = 0; i < 3; i++)
	{
		if (x[i] < y[i])
		{
			for (int j = 0; j < 3; j++)
			{
				a = x[j];
				x[j] = y[j];
				y[j] = a;
			}
			break;
		}
		if (x[i] > y[i])
			break;
	}
	for (int i = 0; i < x[1] - 1; i++)
	{
		d1 += m[i];
	}
	d1 += x[2];
	if (x[1] > 2)
	{
		if (x[0] % 4 == 0 && (x[0] % 100 != 0 || x[0] % 400 == 0))
			d1++;
	}
	if (y[1] > 2)
	{
		if (y[0] % 4 == 0 && (y[0] % 100 != 0 || y[0] % 400 == 0))
			d2++;
	}
	for (int i = 0; i < y[1] - 1; i++)
	{
		d2 += m[i];
	}
	d2 += y[2];
	for (int i = y[0]; i < x[0]; i++)
	{
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
		{
			if (i == y[0])
			{
				sum += 366 - d2;
			}
			else
				sum += 366;
		}
		else
		{
			if (i == y[0])
			{
				sum += 365 - d2;
			}
			else
				sum += 365;
		}
	}
	if (x[0] == y[0])
	{
		sum = d1 - d2;
	}
	else
		sum += d1;
	return sum;
}
inline void Date::x()
{
	int sum = 0, m[11] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
	for (int i = 1999; i < year; i++)
	{
		if (i % 4 == 0)
			sum += 366;
		else
			sum += 365;
	}
	for (int i = 0; i < month-1; i++)
	{
		sum += m[i];
	}
	if (year % 4 == 0 && month >2)
		sum++;
	sum += day;
	sum--;
	if (sum % 7 == 0)
		cout << "Fri.";
	if (sum % 7 == 1)
		cout << "Sat.";
	if (sum % 7 == 2)
		cout << "Sun.";
	if (sum % 7 == 3)
		cout << "Mon.";
	if (sum % 7 == 4)
		cout << "Tue.";
	if (sum % 7 == 5)
		cout << "Wed.";
	if (sum % 7 == 6)
		cout << "Thu.";
}
inline void Date::print()
{
	cout << year << '/' << month << '/' << day;
}