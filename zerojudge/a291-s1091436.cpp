#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x[4], y[4], z[4], a, b, c, q = 0, p = 0;
    while (cin >> x[0] >> x[1] >> x[2] >> x[3])
    {
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            for (int i = 0; i < 4; i++)
            {
                y[i] = x[i];
            }
            for (int j = 0; j < 4; j++)
            {
                cin >> z[j];
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