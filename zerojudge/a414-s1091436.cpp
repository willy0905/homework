#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a,b,c,x[100],sum;
    while(scanf("%d",&a)&&a!=0)
    {
        b=0;
        sum=0;
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
        if(x[0]==1)
        {
            for(int i=0;i<b;i++)
            {
                if(x[i]==1)
                    sum++;
                else
                    break;
            }
            printf("%d\n",sum);
        }
        else if(x[0]==0)
        {
            sum=0;
            printf("%d\n",sum);
        }
    }
}
