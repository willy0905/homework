#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        int b,c,x=0,y=0;
        for(int i=0;i<a;i++)
        {
            cin>>b>>c;
            if(b==0)
            {
                y+=c;
            }
            if(b==1)
            {
                x+=c;
            }
            if(b==2)
            {
                y-=c;
            }
            if(b==3)
            {
                x-=c;
            }
        }
        cout<<x<<" "<<y<<"\n";
    }
}