#include <iostream>

using namespace std;

int main()
{
    int a,sum2,sum5;
    long long int sum;
    int x[1000];
    while(cin>>a)
    {
        int x[a+1];
        sum=1;
        sum2=0;
        sum5=0;
        for(int i=1;i<=a;i++)
        {
            x[i]=i;
            if(i%2==0)
            {
                while(x[i]%2==0)
                {
                    x[i]=x[i]/2;
                    sum2++;
                }
            }
            if(i%5==0)
            {
                while(x[i]%5==0)
                {
                    x[i]=x[i]/5;
                    sum5++;
                }
            }
        }
        for(int i=1;i<=a;i++)
        {
            sum*=x[i];
            sum%=1000000000;
        }
        if(sum2>sum5)
        {
            for(int i=0;i<sum2-sum5;i++)
            {
                sum*=2;
                sum%=1000000000;
            }
        }
        else
        {
            for(int i=0;i<sum5-sum2;i++)
            {
                sum*=5;
                sum%=1000000000;
            }
        }
        cout<<sum%1000000000<<endl;
    }
}
