#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long int a,b,sum,t;
    while(cin>>a>>b)
    {
        sum=0;
        t=1;
        while(sum<a&&b>0)
        {
            sum+=t;
            t+=b;
        }
        if(sum==a||b==0)
            cout<<"Go Kevin!!\n";
        else
            cout<<"No Stop!!\n";
    }
}