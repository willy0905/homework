#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a;
    while (cin >> a)
    {
        for (int i = 0; i < a; i++)
        {
            int x[6];
            string str;
            cin>>str;
            for(int j=0;j<str.size();j++)
            {
                cout<<str[j];
            }
        }
    }
}