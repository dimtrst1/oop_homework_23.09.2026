#include <iostream>
#include "Var.h"
using namespace std;

int main()
{
    Var a = 15;
    Var b = "Hello";
    Var c = 7.8;
    Var d = "50";

    b = a + d;
    b.Show();

    if (a == b)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    cout << "\nArithmetic:\n";

    Var x = 10;
    Var y = "120";
    Var result;

    result = x + y;
    result.Show();

    result = y + x;
    result.Show();

    cout << "\nStrings:\n";

    Var s1 = "Microsoft";
    Var s2 = "Windows";

    result = s1 * s2;
    result.Show(); 

    result = s1 / s2;
    result.Show();

    cout << "\nOther operations:\n";

    Var n1 = 20;
    Var n2 = 5;

    (n1 + n2).Show();
    (n1 - n2).Show();
    (n1 * n2).Show();
    (n1 / n2).Show();

    n1 += n2;
    n1.Show();

    n1 -= n2;
    n1.Show();

    n1 *= n2;
    n1.Show();

    n1 /= n2;
    n1.Show();

    cout << "\nComparison:\n";

    cout << (n1 == n2) << endl;
    cout << (n1 != n2) << endl;
    cout << (n1 > n2) << endl;
    cout << (n1 < n2) << endl;
    cout << (n1 >= n2) << endl;
    cout << (n1 <= n2) << endl;

    cout << "\nConversion:\n";

    Var num = "123";

    int i = static_cast<int>(num);
    double db = static_cast<double>(num);
    char* text = static_cast<char*>(num);

    cout << i << endl;
    cout << db << endl;
    cout << text << endl;

    delete[] text;

    return 0;
}
