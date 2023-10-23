#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    while(cin>>x)
    {
        for(int i=1;i<=6;i++)
        {
             if(x[i]>x[i-1])
                cout<<x[i]-x[i-1];
             else
                cout<<x[i-1]-x[i];
        }
        cout<<endl;
    }
}
