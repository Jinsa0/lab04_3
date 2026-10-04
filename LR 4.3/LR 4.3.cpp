// LR 4.3.cpp
// Кіц Роман Романович
// Лабораторна робота № 4.3
// Табуляція функції, заданої формулою: функція з параметрами.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main()
{
    double a, b, c, x, xp, xk, dx, F;
    bool ok;   // true, якщо в точці x функція визначена (немає ділення на 0)

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(7) << "x" << "   |"
        << setw(10) << "F" << "   |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        ok = true;
        F = 0;

        if (x < 0.6 && b + c != 0)
        {
            F = a * x * x + b * b + c;
        }
        else
            if (x > 0.6 && b + c == 0)
            {
                if (x == c)
                    ok = false;            // ділення на нуль
                else
                    F = (x - a) / (x - c);
            }
            else
            {
                if (c == 0 || a == 0)
                    ok = false;            // ділення на нуль
                else
                    F = x / c + x / a;
            }

        cout << "|" << setw(7) << setprecision(2) << x << "   |";
        if (ok)
            cout << setw(10) << setprecision(3) << F << "   |" << endl;
        else
            cout << setw(10) << "undef" << "   |" << endl;

        x += dx;
    }
    cout << "---------------------------" << endl;

    return 0;
}
