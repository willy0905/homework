#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        int x,y;
        for(int i=0;i<a;i++)
        {
            cin>>x>>y;
            if(100-x-y>0&&100-x-y<=30)
            {
                cout<<"sad!\n";
            }
            else if(100-x-y>30&&100-x-y<=60)
            {
                cout<<"hmm~~\n";
            }
            else if(100-x-y>60&&100-x-y<100)
            {
                cout<<"Happyyummy\n";
            }
            else
                cout<<"evil!!\n";
        }
    }
}