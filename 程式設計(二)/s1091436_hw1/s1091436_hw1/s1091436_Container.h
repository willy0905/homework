#pragma once
#include "s1091436_Date.h"
class Container
{
public:
	Container(int); //�إߪŮe���]��J�Ȭ��e���j�p�^
	void addDate(Date);
	void removeLast(); //�����̫��J���]�S�o���ɵL�@�Ρ^
	void printALL(); //�L�X�Ҧ����
private:
	Date* time;
	int num;
};