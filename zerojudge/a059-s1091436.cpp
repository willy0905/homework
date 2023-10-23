#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d=1,sum=0;
    while(cin>>a)
    {
        for(int i=0;i<a;i++)
        {
            cin>>b>>c;
            for(int i=b;i<=c;i++)
            {
                for(int j=1;j<=(i+1)/2;j++)
                {
                    if(j*j==i)
                    {
                        sum+=i;
                        break;
                    }
                }
            }
            cout<<"Case "<<d<<": "<<sum<<endl;
            sum=0;
            d++;
        }
    }
}
