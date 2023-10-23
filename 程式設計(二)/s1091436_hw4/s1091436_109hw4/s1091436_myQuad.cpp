#pragma once
#include <iostream>
#include "s1091436_myQuad.h"
ostream & operator<<(ostream&output,  myQuadrilateral & Tra)
{
	output<<Tra.getType()<<"\n";
	output << "("<<Tra.A.x<<","<<Tra.A.y<<")\n" << "(" << Tra.B.x << "," << Tra.B.y << ")\n" << "(" 
		<< Tra.C.x << "," << Tra.C.y << ")\n" << "(" << Tra.D.x << "," << Tra.D.y << ")";
	return output;
}
myQuadrilateral::myQuadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4):A1(x1,y1), B1(x2, y2),C1(x3,y3),D1(x4,y4)
{
	A = A1;
	B = B1;
	C = C1;
	D = D1;
}
double myQuadrilateral::getArea()
{
	double sum;
	sum = A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * D.y - D.x * C.y + D.x * A.y - A.x * D.y;
	if (sum < 0)
		sum *= -1;
	return sum / 2;
}
void myQuadrilateral::print()
{
	cout << "(" << A.x << "," << A.y << ")\n" << "(" << B.x << "," << B.y << ")\n" << "("
		<< C.x << "," << C.y << ")\n" << "(" << D.x << "," << D.y << ")";
}
string myQuadrilateral::getType()
{
	string x = "Quadrilateral";
	return x;
}
bool myQuadrilateral::isValid()
{
	double t1 = (C.x - A.x)*(B.y - A.y)-(C.y-A.y)*(B.x-A.x);
	double t2 = (A.x - B.x)*(C.y - B.y) - (A.y - B.y)*(C.x - B.x);
	double t3 = (B.x - C.x)*(D.y - C.y) - (B.y - C.y)*(D.x - C.x);
	double t4 = (C.x - D.x)*(A.y - D.y) - (C.y - D.y)*(A.x - D.x);
	double sumx = (A.x + B.x + C.x + D.x) / 4;
	double sumy = (A.y + B.y + C.y + D.y) / 4;
	Point2 sum(sumx, sumy);
	if ((Point2::getDistance(A, sum) == Point2::getDistance(B, sum) && Point2::getDistance(B, sum) == Point2::getDistance(C, sum) && Point2::getDistance(C, sum) == Point2::getDistance(D, sum))||t1*t2*t3*t4<0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool myTrapezium::isValid()
{
	if (Point2::isParallel(A, B, C, D))
	{
		if (!Point2::isParallel(A, C, B, D))
		{
			return true;
		}
	}
	else if (!Point2::isParallel(A,B,C,D))
	{
		if (Point2::isParallel(A, B, C, D))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

string myTrapezium::getType()
{
	string y = myQuadrilateral::getType();
	string x = "-Trapezium";
	y = y.append(x);
	return y;
}

bool myParallelogram::isValid()
{
	if (Point2::isParallel(A, B, C, D))
	{
		if (Point2::isParallel(A, C, B, D))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

string myParallelogram::getType()
{
	string y = myQuadrilateral::getType();
	string x = "-Parallelogram";
	y = y.append(x);
	return x;
}

bool myRectangle::isValid()
{
	if (Point2::getDistance(A, B)== Point2::getDistance(C, D)&& Point2::getDistance(B, C)== Point2::getDistance(A, D))
	{
		return true;
	}
	else
	{
		return false;
	}
}

string myRectangle::getType()
{
	string y = myQuadrilateral::getType();
	string x = "-Rectangle";
	y = y.append(x);
	return y;
}

bool mySquare::isValid()
{
	if (Point2::getDistance(A, B) == Point2::getDistance(B, C))
	{	
		return true;
	}
	else
	{
		return false;
	}
}

string mySquare::getType()
{
	string y = myRectangle::getType();
	string x = "-Square";
	y = y.append(x);
	return y;
}
