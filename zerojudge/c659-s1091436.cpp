#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x, y;
    while (cin >> x)
    {
        getline(cin, y);
        for (int i = 1; i < y.size(); i++)
        {
            if (y[i] != 32)
            {
                cout << y[i];
            }
            else
            {
                cout << " " << x << " ";
            }
        }
    }
}