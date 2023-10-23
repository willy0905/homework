#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int sum=(b-a)/2-((a%2==0&&b%2==0&&a!=b)?1:0);
        sum+=(a%2==0?1:0)+((b%2==0&&a!=b)?1:0);
        cout<<sum<<"\n";
    }
}