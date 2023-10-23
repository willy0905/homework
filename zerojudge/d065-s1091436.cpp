#include <iostream>
using namespace std;
int main()
{
    int a[3];
    while(cin>>a[0]>>a[1]>>a[2])
    {
        int temp;
        for(int i=0;i<3;i++)
        {
            for(int j=i;j<3;j++)
            {
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        cout<<a[2]<<endl;
    }
}