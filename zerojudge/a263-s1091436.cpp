#include <iostream>

using namespace std;

int main()
{
    int x[3], y[3], m[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    while (cin >> x[0] >> x[1] >> x[2] >> y[0] >> y[1] >> y[2])
    {
        int a, d1 = 0, d2 = 0, sum = 0, b = 1;
        for (int i = 0; i < 3; i++)
        {
            if (x[i] < y[i])
            {
                for (int j = 0; j < 3; j++)
                {
                    a = x[j];
                    x[j] = y[j];
                    y[j] = a;
                }
                break;
            }
            if (x[i] > y[i])
                break;
        }
        for (int i = 0; i < x[1] - 1; i++)
        {
            d1 += m[i];
        }
        d1 += x[2];
        if (x[1] > 2)
        {
            if (x[0] % 4 == 0 && (x[0] % 100 != 0 || x[0] % 400 == 0))
                d1++;
        }
        if (y[1] > 2)
        {
            if (y[0] % 4 == 0 && (y[0] % 100 != 0 || y[0] % 400 == 0))
                d2++;
        }
        for (int i = 0; i < y[1] - 1; i++)
        {
            d2 += m[i];
        }
        d2 += y[2];
        for (int i = y[0]; i < x[0]; i++)
        {
            if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
            {
                if (i == y[0])
                {
                    sum += 366 - d2;
                }
                else
                    sum += 366;
            }
            else
            {
                if (i == y[0])
                {
                    sum += 365 - d2;
                }
                else
                    sum += 365;
            }
        }
        if(x[0]==y[0])
        {
            sum=d1-d2;
        }
        else
            sum+=d1;
        cout << sum << endl;
    }
}