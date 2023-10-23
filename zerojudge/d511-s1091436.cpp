#include <iostream>
using namespace std;
int main()
{
    int a[5][3],b,sum=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
        for(int j=0;j<3;j++)
        {
            for(int k=j;k<3;k++)
            {
                if(a[i][j]>a[i][k])
                {
                    b=a[i][j];
                    a[i][j]=a[i][k];
                    a[i][k]=b;
                }
            }
        }
        if(a[i][0]+a[i][1]>a[i][2])
             sum++;
    }
    cout<<sum;
}