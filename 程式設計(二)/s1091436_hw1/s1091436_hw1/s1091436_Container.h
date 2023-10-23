#pragma once
#include "s1091436_Date.h"
class Container
{
public:
	Container(int); //建立空容器（輸入值為容器大小）
	void addDate(Date);
	void removeLast(); //移除最後放入的（沒得移時無作用）
	void printALL(); //印出所有日期
private:
	Date* time;
	int num;
};