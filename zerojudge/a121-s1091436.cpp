#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, sum = 0;
    while (cin >> a >> b)
    {
        double x;
        sum = 0;
        for (int i = a; i <= b; i++)
        {
            x = i;
            c = 1;
            if (i == 2 || i == 3)
            {
                c = 1;
            }
            else if ((i % 6 == 1 || i % 6 == 5) && i > 4)
            {
                for (int j = 5; j <= sqrt(x); j += 6)
                {
                    if (i % j == 0 || i % (j + 2) == 0)
                    {
                        c = 0;
                        break;
                    }
                }
            }
            else if (i % 6 != 1 && i % 6 != 5)
            {
                c = 0;
            }
            if (c == 1)
                sum++;
        }
        if (a == 1)
            sum--;
        cout << sum << endl;
    }
}
