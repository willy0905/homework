#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> c)
    {
        for (int i = 0; i < c; i++)
        {
            cin >> a;
            if (a % 4 == 0)
            {
                if (a % 100 == 0)
                {
                    if (a % 400 == 0)
                        b = 1;
                    else
                        b = 0;
                }
                else
                {
                    b = 1;
                }
            }
            else
            {
                b = 0;
            }
            if (b == 0)
            {
                cout << "a normal year\n";
            }
            else
            {
                cout << "a leap year\n";
            }
        }
    }
}