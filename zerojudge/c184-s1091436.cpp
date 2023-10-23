#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a&&a!=0)
    {
        b=0;
        int sum=0,sum1=0;;
        for(int i=1;i<=(a+1)/2;i++)
        {
            if(a%i==0)
            {
                sum+=i;
            }
        }
        for(int i=1;i<sum;i++)
        {
            if(sum%i==0)
            {
                sum1+=i;
            }
        }
        if(sum==a)
        {
            cout<<"="<<a<<endl;
        }
        else if(a==sum1)
        {
            cout<<sum<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
}