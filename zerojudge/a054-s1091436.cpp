#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c,sum,d;
    while(cin>>a)
    {
        sum=0;
        b=0;
        int x[10];
        while(a>0)
        {
            x[b]=a%10;
            a/=10;
            b++;
        }
        for(int i=1;i<=8;i++)
        {
            sum+=x[i]*i;
        }
        if(x[0]==0)
            x[0]=10;
        if(10-sum%10==x[0])
        {
            cout<<"BNZ";
        }
        if(10-(sum+1)%10==x[0])
        {
            cout<<"AMW";
        }
        if(10-(sum+2)%10==x[0])
        {
            cout<<"KLY";
        }
        if(10-(sum+3)%10==x[0])
        {
            cout<<"JVX";
        }
        if(10-(sum+4)%10==x[0])
        {
            cout<<"HU";
        }
        if(10-(sum+5)%10==x[0])
        {
            cout<<"GT";
        }
        if(10-(sum+6)%10==x[0])
        {
            cout<<"FS";
        }
        if(10-(sum+7)%10==x[0])
        {
            cout<<"ER";
        }
        if(10-(sum+8)%10==x[0])
        {
            cout<<"DOQ";
        }
        if(10-(sum+9)%10==x[0])
        {
            cout<<"CIP";
        }
    }
}
