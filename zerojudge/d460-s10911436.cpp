#include <iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        cout<<((a>=6&&a<=11)?1:0)*590+((a>=12&&a<=17)?1:0)*790+((a>=18&&a<=59)?1:0)*890+((a>=60)?1:0)*399<<endl;
    }
}