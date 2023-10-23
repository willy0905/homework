#pragma once
#include <iostream>
using namespace std;
class Point2 {
public:
	Point2();
	Point2(int, int);
	static float getDistance(const Point2&point1, const Point2&point2);
	static bool isParallel(const Point2 &A, const Point2 &B,const Point2 &C, const Point2 &D);
	float x, y;
};