#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        if(a<=25)
        {
            cout<<25-a<<endl;
        }
        else
        {
            cout<<85-a<<endl;
        }
    }
}