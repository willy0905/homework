#include <iostream>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==b)
            cout<<a<<endl;
        else
            cout<<b+1<<endl;
    }
}
