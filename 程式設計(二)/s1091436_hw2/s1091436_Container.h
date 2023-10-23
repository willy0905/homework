#include<iostream>
using namespace std;
#pragma once
class Container
{
	friend istream &operator>>(istream &a, Container &b);
	friend ostream &operator<<(ostream &, Container b);
public:
	Container(int); //建立空容器（輸入值為容器大小）
	void push(int);
	int pop(); //移除最後放入的並回傳移出物（沒有則為0）
	void printALL(); //印出所有內容，含錯誤訊息+換行。
	void resize( int); //改變容器大小
	static Container  cat( Container&,const Container&);
	Container operator+(const Container&);
	Container operator+(int );
private:
	int *size;
	int determine = 0;
	int len;
	int *ans;
};