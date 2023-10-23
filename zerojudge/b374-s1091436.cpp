#include <iostream>
using namespace std;
int main()
{
    int a;
    while (cin >> a)
    {
        int x[a], y[a], z[a] , b, c = 0, d;
        for(int i=0;i<a;i++)
        {
            cin>>x[i];
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = i; j < a; j++)
            {
                if (x[j] < x[i])
                {
                    b = x[i];
                    x[i] = x[j];
                    x[j] = b;
                }
            }
        }
        for (int i = 0; i < a; i++)
        {
            if (x[i] != 0)
            {
                y[c] = x[i];
                z[c]=1;
                for (int j = 0; j < a; j++)
                {
                    if (x[i] == x[j] && i != j)
                    {
                        z[c]++;
                        x[j] = 0;
                    }
                }
                c++;
            }
        }
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(z[i]>z[j])
                    z[j]=0;
            }
        }
        for(int i=0;i<c;i++)
        {
            if(z[i]!=0)
            {
                cout<<y[i]<<" "<<z[i]<<endl;
            }
        }
    }
}