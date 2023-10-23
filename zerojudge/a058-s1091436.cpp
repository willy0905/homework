#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e;
    while(cin>>a)
    {
        c=d=e=0;
        for(int i=0;i<a;i++)
        {
            cin>>b;
            if(b%3==0)
                c++;
            if((b-1)%3==0)
                d++;
            if((b-2)%3==0)
                e++;
        }
        cout<<c<<" "<<d<<" "<<e;
    }
}
