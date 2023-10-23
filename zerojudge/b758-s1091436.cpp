#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        a+=2;
        b+=30;
        a+=b/60;
        b%=60;
        a%=24;
        cout<<setw(2)<<setfill('0')<<a<<":"<<setw(2)<<setfill('0')<<b;
    }
}