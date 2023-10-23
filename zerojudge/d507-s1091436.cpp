#include <iostream>
using namespace std;
int main()
{
    int a[3],b;
    while(cin>>a[0]>>a[1]>>a[2])
    {
        for(int i=0;i<3;i++)
        {
            for(int j=i+1;j<3;j++)
            {
                if(a[i]>a[j])
                {
                    b=a[i];
                    a[i]=a[j];
                    a[j]=b;
                }
            }
        }
        int sum=a[0]*a[0]+a[1]*a[1]-a[2]*a[2];
        if(sum==0)
        {
            cout<<"right triangle\n";
        }
        else if(sum>0)
        {
            cout<<"acute triangle\n";
        }
        else
        {
            cout<<"obtuse triangle\n";
        }
    }
}