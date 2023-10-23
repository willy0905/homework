#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    while(cin>>x)
    {
        int y[26]={0},a=0,b=0,c=0;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]>='a'&&x[i]<='z')
            {
                x[i]-=97;
                y[x[i]]++;
                a++;
            }
            if(x[i]>='A'&&x[i]<='Z')
            {
                x[i]-=65;
                y[x[i]]++;
                a++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(y[i]%2==1)
                b++;
            else if(y[i]>0)
                c++;
        }
        if((a%2==0&&b==0)||(a%2==1&&b==1))
            cout<<"yes !"<<endl;
        else
            cout<<"no..."<<endl;
    }
}
