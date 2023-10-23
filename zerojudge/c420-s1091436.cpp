#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> a)
    {
        c = a - 1;
        b = 1;
        while (b <= a*2-1 )
        {
            for (int i = 0; i < c; i++)
            {
                cout << "_";
            }
            for (int i = 0; i < b; i++)
            {
                cout << "*";
            }
            for (int i = 0; i < c; i++)
            {
                cout << "_";
            }
            b+=2;
            c--;
            cout<<endl;
        }
    }
}