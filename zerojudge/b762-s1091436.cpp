#include <iostream>
#include <string>
using namespace std;
int main()
{
    int y;
    while (cin >> y)
    {
        string x;
        int k = 0, k1 = 0, d = 0, a = 0;
        for (int i = 0; i < y; i++)
        {
            cin >> x;
            if (x == "Get_Kill")
            {
                k++;
                k1++;
                if (k < 3)
                    cout << "You have slain an enemie.\n";
                if (k == 3)
                    cout << "KILLING SPREE!\n";
                if (k == 4)
                    cout << "RAMPAGE~\n";
                if (k == 5)
                    cout << "UNSTOPPABLE!\n";
                if (k == 6)
                    cout << "DOMINATING!\n";
                if (k == 7)
                    cout << "GUALIKE!\n";
                if (k >= 8)
                    cout << "LEGENDARY!\n";
            }
            if (x == "Get_Assist")
            {
                a++;
            }
            if (x == "Die")
            {
                if (k >= 3)
                {
                    cout << "SHUTDOWN.\n";
                }
                else
                {
                    cout << "You have been slained.\n";
                }
                d++;
                k = 0;
            }
        }
        cout << k1 << "/" << d << "/" << a << endl;
    }
}