#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    if(b>a)
    {
        c=a;
        a=b;
        b=c;
    }
    while(b>0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    cout<<a;
}
