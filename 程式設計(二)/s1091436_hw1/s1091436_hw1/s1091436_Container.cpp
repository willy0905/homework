#include <iostream>
#include <stdlib.h> //srand(), rand()
#include <time.h>   //time()
#include "s1091436_Container.h"
using namespace std;

inline Container::Container(int times)
{
	num = times;
	time = new Date[10];
}
inline void Container::addDate( Date t)
{
	for (int i = 0; i < num; i++)
	{
		time[i].setDate(t.getYear(), t.getMonth(), t.getDay());
	}
}
inline void Container::printALL()
{
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			time[i].print();
			cout << " ";
			time[i].x();
			cout << endl;
		}
		else
		{
			time[i].print();
			cout << " ";
			time[i].x();
			if (time[i - 1].earlier(time[i]) == 1)
			{
				cout << " (-"<<time[i - 1].distance(time[i])<<")\n";
			}
			else
				cout << " (+" << time[i - 1].distance(time[i]) << ")\n";
		}
	}
}