#include <iostream>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a)
    {
        int x[a],sum=0;
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<a;i++)
        {
            for(int j=i;j<a;j++)
            {
                if(x[j]<x[i])
                {
                    b=x[i];
                    x[i]=x[j];
                    x[j]=b;
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
}
