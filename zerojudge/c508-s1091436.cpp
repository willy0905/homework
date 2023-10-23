#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int a,b;
    while(cin>>a)
    {
        int x[100000]={0};
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
        }
        sort(x,x+a);
        for(int i=0;i<a;i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<"\n";
        for(int i=a-1;i>=0;i--)
        {
            if(x[i]!=x[i+1])
                cout<<x[i]<<" ";
        }
        cout<<"\n";
    }
}