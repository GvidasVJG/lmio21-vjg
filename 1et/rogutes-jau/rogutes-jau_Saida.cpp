#include <iostream>

using namespace std;

int main()
{
    int N, S, sk, sum = 0;
    cin >> N >> S;

    for (N; N > 0; N--)
    {
        cin >> sk;
        sum = sum + sk;
        if (sum > S && N != 1)
        {
            sum--;
        }
    }
    cout << sum;
}