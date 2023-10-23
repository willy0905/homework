#include <iostream>
#include <cmath>
#include "s1091436_myPoint2.h"
using namespace std;

Point2::Point2()
{
}

Point2::Point2(int cinx, int ciny)
{
	x = cinx;
	y = ciny;
}
float Point2::getDistance(const Point2 &point1, const Point2 &point2)
{
	float distance,dx,dy;
	dx = pow((point1.x - point2.x), 2);
	dy = pow((point1.y - point2.y), 2);
	distance = (dx + dy);
	return distance;
}

bool Point2::isParallel(const Point2 & A, const Point2 & B, const Point2 & C, const Point2 & D)
{
	float r1, r2;
	r1 = (A.x - B.x) / (A.y - B.y);
	r2 = (C.x - D.x) / (C.y - D.y);
	if (r1 == r2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
