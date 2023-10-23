#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
template<typename T>
class Array
{
	friend ostream &operator<<(ostream& output, const Array<T>& vec);
public:
	Array();
	Array(T &);
	~Array() {};
	int getSize() const;
	int getnum(int )const;
	void resize(int n, char c = '\0');
	int getCapacity() const;
	void reserve(int n = 0);
	void shrink_to_fit();
	void clear();
	void push_back(int  c);
	void pop_back();
	bool operator==(const Array<T> &str) const;
	bool operator!=(const Array<T> &str) const;
private:
	int size;
	int capacity;
	int* sPtr;
};
class BigNUM :public Array<int>
{
	friend ostream &operator<<(ostream& output, const BigNUM& vec);
	friend istream &operator>>(istream& intput,  BigNUM & vec);
public:
	BigNUM():Array() {};
	BigNUM(string);
	BigNUM(const BigNUM& a) :Array(a) {};
	
	~BigNUM() {};
	BigNUM& operator= ( BigNUM&);
	BigNUM operator+ (BigNUM&);
	BigNUM operator- (BigNUM&);
	BigNUM& operator-= (BigNUM&);
	BigNUM operator* (BigNUM&);
	BigNUM& operator*= (BigNUM);
	BigNUM operator/ (BigNUM&);
	BigNUM operator% (BigNUM&);
	BigNUM& operator%= (BigNUM);
	static BigNUM GCD(BigNUM, BigNUM);
	static BigNUM LCM(BigNUM, BigNUM);
	bool operator>= (BigNUM&)const;
	bool operator> (BigNUM&)const;
	bool operator== (BigNUM&)const;
	bool operator<= (BigNUM&)const;
	bool operator< (BigNUM&)const;
	static void Swap(BigNUM&, BigNUM&);
private:
	string num;
};
