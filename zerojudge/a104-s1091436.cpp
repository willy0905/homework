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
                if(x[j]>x[i])
                {
                    b=x[i];
                    x[i]=x[j];
                    x[j]=b;
                }
            }
        }
        for(int i=a-1;i>=0;i--)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
}
