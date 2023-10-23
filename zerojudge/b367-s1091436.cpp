#include <iostream>
using namespace std;
int main()
{
    int a;
    while (cin >> a)
    {
        int x, y ;
        for (int i = 0; i < a; i++)
        {
            int b = 1;
            cin >> x >> y;
            int z[x][y];
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    cin >> z[i][j];
                }
            }
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (z[i][j] != z[x - 1 - i][y - 1 - j])
                    {
                        b = 0;
                        break;
                    }
                }
            }
            if (b == 1)
                cout << "go forward\n";
            else
                cout << "keep defending\n";
        }
    }
}