#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    // greitis kalno viršuje (pradinis) yra 0
    int s = 0, a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        // greitis pasikeičia per a.
        // Jei s buvo daugiau už x, tai mergina įjungė stabdžius
        // ir greitis buvo 1 mažesnis
        if (s > x) {
            s += a - 1;
        }
        else {
            s += a;
        }
    }

    cout << s;

    return 0;
}
