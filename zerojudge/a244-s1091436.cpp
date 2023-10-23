#include <iostream>

using namespace std;

int main()
{
    long long int x,a,b,c;
    while(cin>>x)
    {
        for(int i=0;i<x;i++)
        {
            cin>>a>>b>>c;
        if(a==1)
        {
            cout<<b+c<<endl;
        }
        if(a==2)
        {
            cout<<b-c<<endl;
        }
        if(a==3)
        {
            cout<<b*c<<endl;
        }
        if(a==4)
        {
            cout<<b/c<<endl;
        }
        }
    }
}
