#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
struct point {
	int x, y, top=NULL;
	set<int>connect;
};
int main()
{
	ifstream input("input.txt", ios::in);
	if (!input.is_open()) {
		cerr << "Failed to open file.\n";
		return 1;
	}
	int size, d;
	vector<point> points;
	set<pair<int, int>> arr;
	set<int> place;
	input >> size >> d;
	for(int i=0;i<size;i++){
		pair<int, int> temp;
		input >> temp.first >> temp.second;
		arr.insert(temp);
	}
	int x = 0;
	for (pair<int, int> i : arr) {
		point tem;
		tem.x = i.first;
		tem.y = i.second;
		tem.top = x;
		tem.connect.insert(x);
		x++;
		points.push_back(tem);
	}
	for (int i = 0; i < points.size(); i++) {
		for (int j = i+1; j < points.size(); j++) {
			if (abs(points[i].x - points[j].x)+ abs(points[i].y - points[j].y)<=d) {
				for (int k : points[points[j].top].connect) {
					points[k].top = points[i].top;
					points[points[i].top].connect.insert(k);
				}
				points[j].top = points[i].top;
				points[points[i].top].connect.insert(j);
			}
		}
	}
	for (int i = 0; i < points.size(); i++) {
		place.insert(points[i].top);
	}
	ofstream output_file("output.txt", std::ios::binary);
	if (output_file.is_open()) {
		output_file << place.size() << "\n";
		output_file.close();
	}
}