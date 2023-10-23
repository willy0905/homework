#include <iostream>
using namespace std;

int x(int);

int main()
{
    int a;
    while (cin >> a)
    {
        cout << x(a) << endl;
    }
    return 0;
}
int x(int a)
{
    if (a == 1)
        return 1;
    if (a > 1)
        return x(a - 1) + (a - 1);
    else
        return 0;
}