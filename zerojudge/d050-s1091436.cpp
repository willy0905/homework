#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        a-=15;
        if(a<0)
            a+=24;
        cout<<a<<endl;
    }
}