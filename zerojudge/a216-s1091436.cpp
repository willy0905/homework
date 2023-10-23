#include <iostream>
using namespace std;
int main()
{
    int a;
    while (cin >> a)
    {
        long long int sumf = 0, sumg = 0;
        for (int i = 1; i <= a; i++)
        {
            sumf += i;
            sumg = sumg + sumf;
        }
        cout << sumf << " " << sumg << endl;
    }
}