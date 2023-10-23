#include <iostream>
using namespace std;
int main()
{
    int a,b,sum;
    while(cin>>a>>b)
    {
        sum=(a<b)?b-a:100-a+b;
        cout<<sum;
    }
}