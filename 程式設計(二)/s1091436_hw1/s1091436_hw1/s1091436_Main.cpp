#include <iostream>
#include <stdlib.h> //srand(), rand()
#include <time.h>   //time()
#include "s1091436_Date.cpp"
#include "s1091436_Container.cpp"
using namespace std;
int main()
{
	Date x;
	srand(time(NULL));
	Container t(rand() % 10 + 2);
	t.addDate(x);
	t.printALL();
	return 0;
}