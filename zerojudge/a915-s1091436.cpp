#include <iostream>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a)
    {
        int x[a][2];
        for(int i=0;i<a;i++)
        {
            cin>>x[i][0]>>x[i][1];
        }
        for(int i=0;i<a;i++)
        {
            for(int j=i;j<a;j++)
            {
                if(x[i][0]>x[j][0])
                {
                    b=x[i][0];
                    x[i][0]=x[j][0];
                    x[j][0]=b;
                    b=x[i][1];
                    x[i][1]=x[j][1];
                    x[j][1]=b;
                }
                if(x[i][0]==x[j][0])
                {
                    if(x[i][1]>x[j][1])
                    {
                        b=x[i][1];
                    x[i][1]=x[j][1];
                    x[j][1]=b;
                    }
                }
            }
        }
        for(int i=0;i<a;i++)
        {
            cout<<x[i][0]<<" "<<x[i][1]<<endl;
        }
    }
}
