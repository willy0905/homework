#include <iostream>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a)
    {
        int x[a];
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<a;i++)
        {
            for(int j=i;j<a;j++)
            {
                if(x[j]%10<x[i]%10)
                {
                    b=x[i];
                    x[i]=x[j];
                    x[j]=b;

                }
                if(x[j]%10==x[i]%10)
                {
                if(x[j]>x[i])
                    {
                        b=x[i];
                        x[i]=x[j];
                        x[j]=b;
                    }
                }
            }
        }
        for(int i=0;i<a;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }
}
