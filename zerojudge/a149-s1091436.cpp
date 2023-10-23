#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    string x;
    while(cin>>a)
    {
        for(int j=0;j<a;j++)
        {
            cin>>x;
            int sum=1;
            for(int i=0;i<x.size();i++)
            {
                sum*=x[i]-48;
            }
            cout<<sum<<endl;
        }
    }
}
