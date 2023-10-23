#include <iostream>
using namespace std;
int main()
{
    int a,z;
    while (cin >> z)
    {
        for (int l = 0; l < z; l++)
        {
            cin>>a;
            int x[a], b, sum, t = 0;
            for (int i = 0; i < a; i++)
                cin >> x[i];
            for (int i = 0; i < a; i++)
            {
                for (int j = i; j < a; j++)
                {
                    if (x[i] > x[j])
                    {
                        b = x[i];
                        x[i] = x[j];
                        x[j] = b;
                    }
                }
            }
            for (int i = 0; i < a; i++)
            {
                for (int j = i + 1; j < a; j++)
                {
                    for (int k = j + 1; k < a; k++)
                    {
                        if (x[i] * x[i] + x[j] * x[j] == x[k] * x[k])
                        {
                            t++;
                        }
                    }
                }
            }
            cout << t << endl;
        }
    }
}