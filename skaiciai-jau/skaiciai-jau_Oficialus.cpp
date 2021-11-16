#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c;
    cin >> x;

    // išrikiuojame pateiktus skaitmenis didėjimo tvarka, kad būtų a < b < c:
    if (b < a) {//sukeičiame vietomis
        int t = a;
        a = b;
        b = t;
    }
    if (c < a) {//sukeičiame vietomis
        int t = a;
        a = c;
        c = t;
    }
    if (b > c) {//sukeičiame vietomis
        int t = b;
        b = c;
        c = t;
    }
    // surašome visus galimus skaičius iš eilės:
    // skaicius1 < skaicius2 < skaicius3 < skaicius4 < skaicius5 < skaicius6
    // Iš viso galima sudaryti tik 6 skaičius.
    int skaicius1 = 100 * a + 10 * b + c;
    int skaicius2 = 100 * a + 10 * c + b;
    int skaicius3 = 100 * b + 10 * a + c;
    int skaicius4 = 100 * b + 10 * c + a;
    int skaicius5 = 100 * c + 10 * a + b;
    int skaicius6 = 100 * c + 10 * b + a;

    //tikriname, su kuriuo skaičiumi sutampa x

    if (x == skaicius1)
        cout << "1" << endl;
    if (x == skaicius2)
        cout << "2" << endl;
    if (x == skaicius3)
        cout << "3" << endl;
    if (x == skaicius4)
        cout << "4" << endl;
    if (x == skaicius5)
        cout << "5" << endl;
    if (x == skaicius6)
        cout << "6" << endl;

    return 0;
}
