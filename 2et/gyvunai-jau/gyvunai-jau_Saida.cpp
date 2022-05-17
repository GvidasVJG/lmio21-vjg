#include <iostream>

using namespace std;

int main()
{
    int N, h1, min1, h2, min2, l1, l2, sk1, sk2;
    cin >> N;
    cin >> h1 >> min1 >> h2 >> min2;
    l1 = h1 * 100 + min1;
    l2 = h2 * 100 + min2;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> h1 >> min1 >> h2 >> min2;
        sk1 = h1 * 100 + min1;
        sk2 = h2 * 100 + min2;
        if ((l1 < sk1 && l2 <= sk1) || (l1 >= sk2 && l2 > sk2))
        {
            cout << "NE";
            break;
        }
        else
        {
            l1 = max(l1, sk1);
            l2 = min(l2, sk2);
            if (i == 1)
            {
                cout << "TAIP";
                cout << endl;
                min1 = l1 % 100;
                h1 = l1 / 100;
                min2 = l2 % 100;
                h2 = l2 / 100;
                cout << h1 << " " << min1 << " " << h2 << " " << min2;
            }
        }
    }
}