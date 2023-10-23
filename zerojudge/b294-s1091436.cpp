#include <iostream>

using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        int x,sum=0;
        for(int i=0;i<a;i++)
        {
            cin>>x;
            sum+=x*(i+1);
        }
        cout<<sum<<endl;
    }
}
