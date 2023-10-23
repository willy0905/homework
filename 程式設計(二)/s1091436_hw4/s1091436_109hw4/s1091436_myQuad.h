#pragma once
#include <iostream>
#include <string>
#include "s1091436_myPoint2.h"
using namespace std;
class myQuadrilateral
{
	friend ostream  &operator<<(ostream&output,  myQuadrilateral&quad);
public:
	myQuadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	void print();
	virtual string getType();
	double getArea();
	virtual bool isValid();
	Point2 A, B, C, D;
private:
	Point2 A1, B1, C1, D1;
};
class myTrapezium :public myQuadrilateral
{
public:
	myTrapezium(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :myQuadrilateral(x1, y1, x2, y2, x3, y3, x4, y4) {
		
	};
	virtual bool isValid();
	string getType();
};
class myParallelogram :public myQuadrilateral
{
public:
	myParallelogram(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :myQuadrilateral(x1, y1, x2, y2, x3, y3, x4, y4) {
	};
	virtual bool isValid();
	string getType();
};
class myRectangle :public myParallelogram
{
public:

	myRectangle(int x1, int y1, int x2, int y2, int x3, int y3,int x4, int y4) :myParallelogram(x1, y1, x2, y2, x3, y3, x4, y4) {
	};
	virtual bool isValid();
	string getType();
};

class mySquare :public myRectangle
{
public:
	mySquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :myRectangle(x1, y1, x2, y2, x3, y3, x4, y4) {
	};
	virtual bool isValid();
	string getType();
};
