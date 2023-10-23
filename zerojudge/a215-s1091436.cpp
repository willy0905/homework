#include <iostream>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int sum=a,c=1;
        a++;
        while(sum<=b)
        {
            sum+=a;
            a++;
            c++;
        }
        cout<<c<<endl;
    }
}
