#include <iostream>
using namespace std;
int main()
{
    int a,sum;
    while(cin>>a)
    {
        sum=0;
        for(int i=1;i<=(a+1)/2;i++)
        {
            if(a%i==0)
                sum+=i;
        }
        if(sum==a)
        {
            cout<<"��ȫ��\n";
        }
        else if(sum>a)
        {
            cout<<"ӯ��\n";
        }
        else
        {
            cout<<"̝��\n";
        }
    }
}