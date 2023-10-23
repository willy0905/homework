#include <iostream>

using namespace std;

int main()
{
    int a,b=0;
    while(cin>>a)
    {
        b=0;
        int x[100]={0};
        while(a!=0)
        {
            if(a%2==0)
            {
                x[b]=0;
                b++;
            }
            else
            {
                x[b]=1;
                b++;
            }
            a/=2;
        }
        for(int i=b-1;i>=0;i--)
        {
            cout<<x[i];
        }
        cout<<endl;
    }
}
