#include <iostream>

// Dienos pradžioje kurjeriai nedirba
int dirba_iki_1 = 0, dirba_iki_2 = 0;
// ir nėra dar nieko uždirbę
int uzdarbis_1 = 0, uzdarbis_2 = 0;

int main() {
    int m;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        int t, v, z1, z2;
        std::cin >> t >> v >> z1 >> z2;

        // Tikrinama, ar pirmasis kurjeris yra laisvas ir:
        // * gali užsakymą įvykdyti greičiau už antrąjį 
        // * arba antrasis yra užsiėmęs
        if (dirba_iki_1 <= t && (z1 < z2 || dirba_iki_2 > t)) {
            dirba_iki_1 = t + z1;
            uzdarbis_1 += v;
        }
        // Jei ankstesn sąlyga netenkinama, tikriname, 
        // ar antrasis kurjeris šiuo metu yra laisvas
        else if (dirba_iki_2 <= t) {
            dirba_iki_2 = t + z2;
            uzdarbis_2 += v;
        }
    }

    std::cout << uzdarbis_1 << " " << uzdarbis_2;

    return 0;
}