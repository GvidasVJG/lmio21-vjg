/*

Sprendimo idėja:
Suskaičiuoti, kiek draugų aplenkė Martyną. Tuomet atsakymas bus šis
skaičius, padidintas vienetu.

Pavyzdžiui, jei Martyną aplenkė keturi draugai, tai tuomet Martyno
vieta yra 4+1 = 5.

*/

#include <iostream>

using namespace std;

int main()
{
    int n, martynoLaikas;
    cin >> n >> martynoLaikas;

    int kiekAplenke = 0; // kiek draugų aplenkė Martyną
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < martynoLaikas) { // jei šis draugas baigė greičiau už Martyną
            kiekAplenke++;
        }
    }

    int vieta = kiekAplenke + 1;
    cout << vieta << endl;

    return 0;
}
