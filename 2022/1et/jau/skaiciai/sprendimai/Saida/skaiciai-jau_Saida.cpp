#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x, a1, b1, c1, x1, x2, x3, x4, x5, x6;
    cin >> a >> b >> c;
    cin >> x;

    int arr[6] = {x1, x2, x3, x4, x5, x6};
    a1 = min(a, min(b, c));
    c1 = max(a, max(b, c));
    if ((a < b && a > c) || (a < c && a > b))
    {
        b1 = a;
    }
    else if ((b < a && b > c) || (b < c && b > a))
    {
        b1 = b;
    }
    else
    {
        b1 = c;
    }
    x1 = 100 * a1 + 10 * b1 + c1;
    x2 = 100 * a1 + 10 * c1 + b1;
    x3 = 100 * b1 + 10 * a1 + c1;
    x4 = 100 * b1 + 10 * c1 + a1;
    x5 = 100 * c1 + 10 * a1 + b1;
    x6 = 100 * c1 + 10 * b1 + a1;

    if (x == x1)
    {
        cout << 1;
    }
    if (x == x2)
    {
        cout << 2;
    }
    if (x == x3)
    {
        cout << 3;
    }
    if (x == x4)
    {
        cout << 4;
    }
    if (x == x5)
    {
        cout << 5;
    }
    if (x == x6)
    {
        cout << 6;
    }
}
