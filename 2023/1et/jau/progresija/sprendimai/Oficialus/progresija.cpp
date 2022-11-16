#include <iostream>

/*
Sprendimo idėja: galima pakeisti bet kurį vieną narį iš duotos skaičių sekos (a, b, c)
norint gauti aritmetinę progresiją.

* Jei keistumėme pirmą narį (a), tai reikia jį keisti taip, kad skirtumas tarp pirmo ir antro
narių po pakeitimo būtų lygus skirtumui tarp antro ir trečio. T.y., turi galioti lygybė: 
((a + d) - b = b - c), kur d - mūsų ieškomas skirtumas.
Kadangi d yra nežinomasis, galima jį išreikšti per kitus narius: d = b - c + b - a;
Dar būtina patikrinti, kad gautas d > 0

* Jei keistumėme antrą sekos narį (b), tai po to turi galioti lygybė:
a - (b + d) = (b + d) - c;
d galima išreikšti per kitus žinomus lygybės narius:
2d = a + c - 2b
d = (a + c - 2b)/2
Šiuo atveju reikia dar patikrinti, kad d yra sveikas skaičius didesnis už 0.

* Kodėl nebandome keisti trečiojo nario (c)? Galima, bet gautas sprendinys būtų toks pats, kaip
keičiant pirmąjį narį (a).

Uždavinio atsakymas - mažesnis iš gautų galimų sprendinių
*/

using namespace std;

const int D = 99999;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int d = D;
    int ad = b - c + b - a;
    if (ad > 0)
        d = ad;

    if ((c + a - 2 * b) % 2 == 0) {
        int bd = (c + a - 2 * b) / 2;
        if (bd > 0 && bd < d)
            d = bd;
    }

    if (d != D)
        cout << d << endl;
    else
        cout << -1 << endl;

    return 0;
}
