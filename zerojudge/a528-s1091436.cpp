#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c;
    while(cin>>a)
    {
        b=0;
        c=0;
        string x[a];
        string y;
        int z[100]={0};
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
            if(x[i][0]=='-')
            {
                b++;
            }
        }
        c=b;
        for(int i=0;i<a;i++)
        {
            if(x[i][0]=='-')
            {
                for(int j=0;j<a;j++)
                {
                    if(x[j][0]!='-')
                    {
                        y=x[i];
                        x[i]=x[j];
                        x[j]=y;
                    }
                }
            }
        }
        for(int i=0;i<a;i++)
        {
            for(int j=i;j<a;j++)
            {
                if(x[i][0]=='-')
                {
                    if(x[j][0]=='-')
                    {
                        if(x[i].size()>x[j].size())
                        {
                            y=x[i];
                            x[i]=x[j];
                            x[j]=y;
                        }
                        if(x[i].size()==x[j].size())
                        {
                            for(int k=1;k<x[i].size();k++)
                            {
                                if(x[i][k]<x[j][k])
                                {
                                    break;
                                }
                                if(x[i][k]>x[j][k])
                                {
                                    y=x[i];
                                    x[i]=x[j];
                                    x[j]=y;
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if(x[i].size()>x[j].size())
                    {
                        y=x[i];
                        x[i]=x[j];
                        x[j]=y;
                    }
                    if(x[i].size()==x[j].size())
                    {
                        for(int k=0;k<=x[i].size();k++)
                        {
                            if(x[i][k]<x[j][k])
                            {
                                break;
                            }
                            if(x[i][k]>x[j][k])
                            {
                                y=x[i];
                                x[i]=x[j];
                                x[j]=y;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(c>0)
        {
            for(int i=c-1;i>=0;i--)
            {
                cout<<x[i]<<endl;
            }
            for(int i=c;i<a;i++)
            {
                cout<<x[i]<<endl;
            }
        }
        else
            for(int i=0;i<a;i++)
        {
            cout<<x[i]<<endl;
        }
    }
}
