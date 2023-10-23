#include <iostream>

using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        cout<<((a+1)*a*(a-1))/6+a+1<<endl;
    }
}
