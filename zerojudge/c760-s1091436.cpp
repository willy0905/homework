#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    while(cin>>x)
    {
        x[0]-=32;
        cout<<x<<endl;
    }
}