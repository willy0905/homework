#pragma once
class Date
{
public:
	Date();
	void setDate(int, int, int);
	int getYear();
	int getMonth();
	int getDay();
	void x();
	bool earlier(const Date &); 
	int distance(const Date &); 
	void print();               
private:
	int year;
	int month;
	int day;
};