#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x,y;
    int a, b;

    while (getline(cin, x))
    {
        a = 0;
        b = 0;
        getline(cin,y);
        for (int i = 0; i < x.size(); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < y.size(); j++)
                {
                    cout << y[j];
                }
                cout<<", ";
            }
            if(x[i]==32)
            {
                cout<<"\n";
                for (int j = 0; j < y.size(); j++)
                {
                    cout << y[j];
                }
                cout<<", ";
            }
            else
            {
                cout<<x[i];
            }
        }
    }
}