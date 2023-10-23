#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    while(cin>>x)
    {
        int a=x.size(),b=0;
        int y[a];
        for(int i=0;i<a;i++)
        {
            y[i]=x[a-i-1];
        }
        for(int i=0;i<a;i++)
        {
            if(y[i]!=x[i])
            {
                cout<<"no";
                b=1;
                break;
            }
        }
        if(b==0)
            cout<<"yes";
    }
}
