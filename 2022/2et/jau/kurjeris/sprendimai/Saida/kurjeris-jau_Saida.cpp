#include <iostream>

using namespace std;

int main()
{
    int M, t, v, z1, z2, sum1 = 0, sum2 = 0, t1 = 0, t2 = 0, h = 0;
    cin >> M;

    for (M; M > 0; M--)
    {
        cin >> t >> v >> z1 >> z2;
        if (h > 0)
        {
            if (t1 > (t - h))
            {
                t1 = t1 - (t - h);
            }
            else
            {
                t1 = 0;
            }
            if (t2 > (t - h))
            {
                t2 = t2 - (t - h);
            }
            else
            {
                t2 = 0;
            }
        }
        if (t1 == 0 && t2 == 0)
        {
            if (z1 < z2)
            {
                t1 += z1;
                sum1 += v;
            }
            else
            {
                t2 += z2;
                sum2 += v;
            }
        }
        else if (t1 == 0 && t2 > 0)
        {
            t1 += z1;
            sum1 += v;
        }
        else if (t1 > 0 && t2 == 0)
        {
            t2 += z2;
            sum2 += v;
        }
        h = t;
    }
    cout << sum1 << " " << sum2;
}