#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        for(int i=0;i<a;i++)
        {
            for(int j=i;j<a-1;j++)
            {
                cout<<"_";
            }
            for(int j=0;j<=i;j++)
            {
                cout<<"*";
            }
            cout<<"\n";
        }
    }
}