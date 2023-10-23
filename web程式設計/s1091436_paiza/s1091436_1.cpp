#include <iostream>
using namespace std;
int main(void){
    int a,b,c,d;
    while(cin>>a)
    {
        int x[a][a];
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                cin>>x[i][j];
            }
        }
        cin>>b;
        int y[b][b];
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<b;j++)
            {
                cin>>y[i][j];
            }
        }
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                if(x[i][j]==y[0][0])
                {
                    c=1;
                    for(int k=i;k<i+b;k++)
                    {
                        for(int l=j;l<j+b;l++)
                        {
                            if(x[k][l]!=y[k-i][l-j])
                            {
                                c=0;
                                break;
                            }
                        }
                        if(c==0)
                            break;
                    }
                    if(c==1)
                        cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
}
