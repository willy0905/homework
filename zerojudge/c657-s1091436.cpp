#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    int len = 0, y = 1;
    char a;
    while (cin >> x)
    {
        len = 0;
        y = 1;
        for (int i = 1; i < x.size(); i++)
        {
            if (x[i] == x[i - 1])
            {
                y++;
            }
            if (x[i] != x[i - 1] || i == x.size()-1)
            {
                if (y > len)
                {
                    len = y;
                    a = x[i - 1];
                    y = 1;
                }
                else
                {
                    y=1;
                }
            }
        }
        cout << a << " " << len << "\n";
    }
}