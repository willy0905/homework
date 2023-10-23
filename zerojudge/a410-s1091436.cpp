#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double x1, y1, z1, x2, y2, z2, a, b, c, x, y;
    while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2)
    {
        a = x1 * y2 - x2 * y1;
        b = z1 * y2 - z2 * y1;
        c = x1 * z2 - x2 * z1;
        if (a == 0)
        {
            if (b == 0 && c == 0)
                cout << "Too many\n";
            else
                cout << "No answer\n";
        }
        else
        {
            cout << fixed << setprecision(2) << "x=" << b / a << "\n"
                 << "y=" << c / a << "\n";
        }
    }
}