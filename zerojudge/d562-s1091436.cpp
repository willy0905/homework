#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    while(cin>>a)
    {
        c=a;
        b=0;
        int x[a];
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
        }
        while(a>0)
        {
            for(int i=b;i<a;i++)
            {
                if(x[i]!=-1)
                cout<<x[i]<<" ";
            }
            x[b]=-1;
            b++;
             cout<<"\n";
            c--;

            if(c==0)
                break;
           
            for(int i=a-1;i>=b;i--)
            {
                if(x[i]!=-1)
                cout<<x[i]<<" ";
            }
            cout<<"\n";
            a--;
            x[a]=-1;
            c--;
            if(c==0)
                break;
        }
    }
}