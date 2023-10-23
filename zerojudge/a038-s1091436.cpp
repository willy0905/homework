#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    while(cin>>x)
    {
        int a=x.size(),b=0,c=0;
        for(int i=0;i<a;i++)
        {
            if(x[i]!='0')
                c=1;
        }
        if(c==0)
            cout<<"0";
        for(int i=a-1;i>=0;i--)
        {
            if(b==0&&x[i]=='0')
            {

            }
            else
            {
                cout<<x[i];
                b=1;
            }
        }
        cout<<endl;
    }
}
