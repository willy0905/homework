#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    int a;
    while (getline(cin, x))
    {
        if((x[0] == '0'&&x.size()==1))
        {
            return 0;
        }
        int sum = 0;
        a = 1;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] >= 'A' && x[i] <= 'Z')
            {
                sum+=x[i]-64;
            }
            else if (x[i] >= 'a' && x[i] <= 'z')
            {
                sum+=x[i]-96;
            }
            else
            {
                a = 0;
            }
        }
        if (a == 1)
            cout << sum << endl;
        else
        {
            cout << "Fail\n";
        }
    }
}