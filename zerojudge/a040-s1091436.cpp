#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x,y,z,a=0,b,num[100],sum=0;
    while(cin>>x>>y)
    {
        z=0;
        for(int i=x;i<=y;i++)
        {
            b=i;
            while(b>=1)
            {
                num[a]=b%10;
                b/=10;
                a++;
            }
            for(int j=0;j<a;j++)
            {
                sum+=pow(num[j],a);
            }
            if(sum==i)
            {
                z++;
                for(int j=a-1;j>=0;j--)
                {
                    cout<<num[j];
                }
                cout<<" ";
            }
            sum=0;
            a=0;
        }
        if(z==0)
            cout<<"none";
    }
}
