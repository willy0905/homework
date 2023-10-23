#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    while(cin>>a>>b)
    {
        c=0;
        if(a>=7&&a<17)
        {
            if(a==7)
            {
                if(b>=30)
                {
                    c=1;
                }
                else
                {
                    c=0;
                }
            }
            else
            {
                c=1;
            }
        }
        else
        {
            c=0;
        }
        if(c==0)
        {
            cout<<"Off School\n";
        }
        if(c==1)
        {
            cout<<"At School\n";
        }
        
    }
}