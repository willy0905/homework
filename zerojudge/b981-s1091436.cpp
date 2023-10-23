#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string x;
    while (cin >> x)
    {
        double y;
        int a = 0, b=0;
        double sum1 = 0;
        long long int sum2 = 0;
        for (int i = 0; i < x.size(); i++)
        {   
            if ((x[i] >= 48 && x[i] <= 58) || x[i] == '.')
            {
                a++;
                if (x[i] == '.')
                    b = 1;
            }
            else
            {
                for (int j = a; j > 0; j--)
                {
                    if (x[i - j] == '.')
                    {
                        y=(x[i - j + 1] - 48);
                        sum1 += y / 10;
                        break;
                    }
                    else if (b == 0)
                        sum1 += (x[i - j] - 48) * pow(10, j - 1);
                    else if (b == 1)
                        sum1 += (x[i - j] - 48) * pow(10, j - 3);
                }
                b=0;
                a = 0;
            }
            if (x[i] == 'h')
            {
                sum2 += sum1 * 3600000;
            }
            else if (x[i] == 'm')
            {
                if (x[i + 1] == 's')
                    sum2 += sum1;
                else
                    sum2 += sum1 * 60000;
            }
            else if (x[i] == 's')
            {
                sum2 += sum1 * 1000;
            }
            sum1 = 0;
        }
        cout << sum2 << endl;
    }
}