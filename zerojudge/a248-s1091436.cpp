#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c)
    {
        int x[c];
        cout<<a/b<<".";
        d=a%b;
        for(int i=0;i<c;i++)
        {
            cout<<d*10/b;;
            d=d*10%b;
        }
        cout<<endl;
    }
}
