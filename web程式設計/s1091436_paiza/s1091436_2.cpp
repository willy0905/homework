#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f,g,h,z,min1,min2;
    while(cin>>a>>b>>c>>d)
    {
        g=0;
        h=0;
        int x[1000];
        int y[1000];
        int x1[d+1];
        int y1[d+1];
        for(int i=0;i<d;i++)
        {
            cin>>e;
            if(e==0)
                {
                    cin>>x[g];
                    g++;
                }
            else
                {
                    cin>>y[h];
                    h++;
                }
        }
        for(int i=0;i<g;i++)
        {
            for(int j=i;j<g;j++)
            {
                if(x[i]>x[j])
                {
                    z=x[i];
                    x[i]=x[j];
                    x[j]=z;
                }
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int j=i;j<h;j++)
            {
                if(y[i]>y[j])
                {
                    z=y[i];
                    y[i]=y[j];
                    y[j]=z;
                }
            }
        }
        x1[0]=x[0];
        y1[0]=y[0];
        for(int i=0;i<=g;i++)
        {
            if(i==0)
                {
                    x1[0]=x[0];
                    min1=x[0];
                }
            else if(i==g)
            {
                x1[i]=a-x[i-1];
            }
            else
                x1[i]=x[i]-x[i-1];
            if(x1[i]<min1)
                min1=x1[i];
        }
        for(int i=0;i<=h;i++)
        {
            if(i==0)
            {
                y1[0]=y[0];
                min2=y[0];
            }
            else if(i==h)
            {
                y1[i]=b-y[i-1];
            }
            else
                y1[i]=y[i]-y[i-1];
            if(min2>y1[i])
            {
                min2=y1[i];
            }
        }
        if(g==0)
            min1=a;
        if(h==0)
            min2=b;
        cout<<(min1*min2)*c<<endl;
    }
}
