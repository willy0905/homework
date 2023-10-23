#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c)
    {
        d=a-c;
        while(d!=b)
        {
            d+=c;
            cout<<d<<" ";
            
        }
        cout<<endl;
    }
}