/**
 * Sprendimas uždaviniui "Ateivių Kojinės".
 *
 * Sprendimo idėja:
 * 
 * Jei kiekvienos spalvos kojinių yra mažiau nei k, tuomet Broniui rasti kojinių
 * nepavyks, ir galima išvesti -1. Jaunesniųjų grupei šito pastebėti nereikėjo,
 * nes sąlyga garantavo, kad Broniui kojines ištraukti pavyks visada.
 *
 * Labiausiai Broniui nepasiseks, jei jis ištrauks kojines taip: iš pradžių ištrauks
 * visas spalvas, kurių kojinių yra mažiau nei k, tuomet visų likusių spalvų trauks
 * po k-1 kojinę. Tuomet Broniui užteks ištraukti tik vieną kojinę ir turės vienos spalvos
 * k kojinių komplektą.
 *
 * Šis atvejis gali būti apskaičiuojamas pereinant per visas spalvas m_i ir prie atsakymo
 * pridedant min(m_i, k-1), t.y. m_i, jei m_i < k ir k-1 jei m_i >= k. Prie šios sumos
 * pridėję 1 gausime atsakymą.
 *
 * Algoritmo sudėtingumas: O(k) laiko atžvilgiu, O(k) atminties.
 *
 * Autorius: Zigmas Bitinas
 */

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXS = 1e3;

int k, s;
int m[MAXS];

int main() {
    scanf("%d %d", &k, &s);

    int max_color = 0;

    for (int i = 0;i < s;++i) {
        scanf("%d", &m[i]);
        max_color = max(max_color, m[i]);
    }

    if (max_color < k) {
        printf("-1\n");
        return 0;
    }

    int ans = 1;

    for (int i = 0;i < s;++i)
        ans += min(k - 1, m[i]);

    printf("%d\n", ans);

    return 0;
}
