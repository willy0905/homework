#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        if(a%2==0)
        {
            cout<<"Even\n";
        }
        else
        {
            cout<<"Odd\n";
        }
    }
}