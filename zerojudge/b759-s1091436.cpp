#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    while(cin>>x)
    {
        int a=x.size();
        for(int i=0;i<a;i++)
        {
            for(int j=i;j<a;j++)
            {
                cout<<x[j];
            }
            for(int k=0;k<i;k++)
            {
                cout<<x[k];
            }
            cout<<endl;
        }
    }
}