#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int sum=0;
        for(int i=a;i<=b;i++)
        {
            if(i%4==0)
            {
                if(i%400==0)
                    sum++;
                else if(i%100!=0)
                    sum++;
            }
        }
        cout<<sum;
    }
}