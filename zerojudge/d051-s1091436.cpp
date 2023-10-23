#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a;
    while(cin>>a)
    {
        cout<<fixed<<setprecision(3)<<(a-32)/9*5<<endl;
    }
}
