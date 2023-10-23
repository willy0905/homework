#include<iostream>
using namespace std;
#pragma once
class Container
{
	friend istream &operator>>(istream &a, Container &b);
	friend ostream &operator<<(ostream &, Container b);
public:
	Container(int); //�إߪŮe���]��J�Ȭ��e���j�p�^
	void push(int);
	int pop(); //�����̫��J���æ^�ǲ��X���]�S���h��0�^
	void printALL(); //�L�X�Ҧ����e�A�t���~�T��+����C
	void resize( int); //���ܮe���j�p
	static Container  cat( Container&,const Container&);
	Container operator+(const Container&);
	Container operator+(int );
private:
	int *size;
	int determine = 0;
	int len;
	int *ans;
};