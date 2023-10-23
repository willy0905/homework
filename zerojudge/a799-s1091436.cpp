#include <iostream>

using namespace std;

int main()
{
    long long int a;
    while(cin>>a)
    {
        if(a<0)
            cout<<a*-1<<endl;
        else
            cout<<a<<endl;
    }
}
