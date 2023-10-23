#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        int x[a],y;
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<a;i++)
        {
            for(int j=i;j<a;j++)
            {
                if(x[i]>x[j])
                {
                    y=x[i];
                    x[i]=x[j];
                    x[j]=y;
                }
            }
        }
        cout<<x[a-1]<<endl;
    }
}