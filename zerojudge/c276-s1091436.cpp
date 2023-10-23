#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int x[4], y[4], z[4], a, b, c, q = 0, p = 0, d, e;
    while (cin >> d)
    {
        {
            for (int i = 3; i >= 0; i--)
            {
                x[i] = d % 10;
                d /= 10;
            }
        }
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            for (int i = 0; i < 4; i++)
            {
                y[i] = x[i];
            }
            cin >> e;
            for (int i = 3; i >= 0; i--)
            {
                z[i] = e % 10;
                e /= 10;
            }
            for (int j = 0; j < 4; j++)
            {
                if (z[j] == y[j])
                {
                    q++;
                    y[j] = -1;
                    z[j] = -1;
                }
            }
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (z[j] == y[k] && z[j] != -1)
                    {
                        if (j != k)
                        {
                            p++;
                            y[k] = -1;
                            break;
                        }
                    }
                }
            }
            cout << q << "A" << p << "B\n";
            p = q = 0;
        }
    }
}