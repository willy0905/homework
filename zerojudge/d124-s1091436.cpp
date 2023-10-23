#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    while(cin>>x)
    {
        int sum=0;
        for(int i=0;i<x.size();i++)
        {
            sum+=x[i]-'0';
        }
        if(sum%3==0)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
}