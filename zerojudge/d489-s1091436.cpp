#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int sum=(a+b+c)/2;
        cout<<sum*(sum-a)*(sum-b)*(sum-c)<<"\n";
    }
}