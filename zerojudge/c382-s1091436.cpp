#include <iostream>
using namespace std;
int main()
{
    int a,c;
    char b;
    while(cin>>a>>b>>c)
    {
        if(b=='+')
        {
            cout<<a+c<<endl;
        }
        if(b=='-')
        {
            cout<<a-c<<endl;
        }
        if(b=='*')
        {
            cout<<a*c<<endl;
        }
        if(b=='/')
        {
            cout<<a/c<<endl;
        }
    }
}