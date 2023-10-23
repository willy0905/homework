#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x, y;
    int a = 0;
    while (getline(cin, x) && getline(cin, y))
    {
        for (int i = 0; i < y.size(); i++)
        {
            a = 0;
            if (y[i] == x[0])
            {
                for (int j = 0; j < x.size(); j++)
                {
                    if (y[i + j] != x[j])
                    {
                        a = 0;
                        break;
                    }
                    else
                    {
                        a = 1;
                    }
                }
            }
            if (a == 1)
            {
                cout << "\n";
                i += x.size()-1;
            }
            else
            {
                cout << y[i];
            }
        }
    }
}