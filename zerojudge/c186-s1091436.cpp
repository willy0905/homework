#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    getline(cin,x);
    for(int i=0;i<x.size();i++)
    {
        if(x[i]!=32)
            cout<<x[i];
        else
            cout<<"\n";
    }
}