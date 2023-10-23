#include <iostream>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a)
    {
        int x[a];
        int sum=0;
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
            sum+=x[i];
        }
        if(sum/a>=60||(sum/a==59&&sum%a!=0))
            cout<<"no";
        else
            cout<<"yes";
        cout<<endl;
    }
}
