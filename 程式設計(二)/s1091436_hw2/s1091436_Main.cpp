#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "s1091436_Container.h"
using namespace std;
int main()
{
	
	int x,y,z;
	cout << "Input random seed: ";
	cin >> x;
	srand(x);
	z = rand() % 5 + 1;
	cout << "Allocate " << z << " slots\n";
	Container c(z);
	for (int i = 0; i < rand() % 6+ 15; i++)
	{
		y = rand() % 3 + 1;
		if (y == 1)
		{
			z = rand()%10+1;
			cout << "push " << z << "\n";
			c.push(z);
		}
		if (y == 2)
		{
			cout << "pop\n";
			c.pop();
		}
		if (y == 3)
		{
			z = rand() % 10 + 1;
			cout << "resize " << z << "\n";
			c.resize(z);
		}
		c.printALL();
	}
	Container A(3),B(5);
	cin >> A >> B;
	cout << A << B<<A+B;
	cout << (A = A + 3);
	Container C = A + B ;
	cout << C;
	C = A + C + B;
	cout << C + 4;
	cout << Container::cat(A, B);
}