/**
 * Sprendimas uždaviniui "Apgavikas".
 *
 * Sprendimo idėja:
 *
 * Susikurkime du masyvus:
 *
 *      1) zino[i] - kuriame pasižymime, kurie žaidėjai žino apie apgaviką, t.y.
 *          spaus raudoną mygtuką
 *      2) gyvas[i] - kuriame pasižymime, kurie žaidėjai vis dar nepašalinti
 * 
 * Tuomet galime eiti per kiekvieną turą, ir pažymėti zino[i] = true, jei to turo
 * metu žaidėjas i buvo tam pačiam kambaryje kaip ir pašalintas žaidėjas.
 *
 * Galiausiai kiekvieno turo pabaigoje, kiek yra žaidėjų, kurie vis dar gyvi ir
 * žino apie apgaviką, ir ar jų užtenka, kad jį išbalsuotų.
 *
 * Algoritmo sudėtingumas: O(NM) laiko atžvilgiu, O(N) atminties.
 *
 * Autorius: Andrius Ovsianas
 */
#include <stdio.h>

using namespace std;

const int MAXN = 1000;

int N, M;
int p[MAXN];
int k[MAXN];
bool zino[MAXN];
bool gyvas[MAXN];

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0;i < N;++i) {
        scanf("%d", &p[i]);
        p[i]--;
    }

    for (int i = 0;i < N;++i) {
        zino[i] = false;
        gyvas[i] = true;
    }

    for (int i = 0;i < N;++i) {
        for (int j = 0;j < N;++j)
            scanf("%d", &k[j]);

        for (int j = 0;j < N;++j)
            if (k[j] == k[p[i]])
                zino[j] = true;

        gyvas[p[i]] = false;

        int raudoni = 0;

        for (int j = 0;j < N;++j)
            if (gyvas[j] && zino[j])
                raudoni++;

        if (2 * raudoni > N - i) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("%d\n", N);

    return 0;
}
