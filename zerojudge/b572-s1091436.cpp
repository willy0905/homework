#include <iostream>
using namespace std;
int main()
{
    int a, h1, m1, h2, m2, t;
    while (cin >> a)
    {

        for (int i = 0; i < a; i++)
        {
            cin >> h1 >> m1 >> h2 >> m2 >> t;
            m1 += t;
            h1 += m1 / 60;
            m1 %= 60;
            if (h1 < h2 || (h1 == h2 && m1 <= m2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}