#include <iostream>

using namespace std;

int main()
{
    int a,sum=0;
    while(cin>>a)
    {
        if(a<=10)
        {
            sum+=a*6;
        }
        if(a>10&&a<=20)
        {
            sum+=60;
            sum+=(a-10)*2;
        }
        if(a>20)
        {
            sum=80;
            sum+=(a-20);
        }
        if(a>=40)
            sum=100;
        cout<<sum<<endl;
        sum=0;
    }
}
