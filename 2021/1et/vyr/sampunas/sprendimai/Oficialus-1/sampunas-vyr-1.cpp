/**
 * Sprendimas uždaviniui "Šampūnas".
 *
 * Sprendimo idėja:
 * 
 * Plovimų skaičius suskaičiuojamas nagrinėjant kiekvieną šventinę dieną:
 *
 *   1) Šventinė diena reiškia, kad bus plaunama galva bent vieną kartą.
 *   2) Taip pat reikia suskaičiuoti, kiek plovimų įvyko nuo praeitos šventinės
 *      dienos. Jų bus (d - last_d - 1) / 2, kadangi tarpe yra (d - last_d - 1)
 *      dienų.
 *
 * Šio sprendimo ypatumas tas, kad reikia būti itin atidiems su kraštiniais
 * atvejais: šventinė diena gali sutapti su pirma diena, arba/ir paskutine
 * diena periode.
 *
 * Algoritmo sudėtingumas: O(K) laiko atžvilgiu, O(1) atminties.
 *
 * Autorius: Linas Petrauskas
 */

#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int answer = 1;
    int last_d = 1;

    // Naginėjame visas šventines dienas.
    for (int i = 0; i < K; i++) {
        int d; cin >> d;
        if (d == 1) {
            // Šiuo atveju galvos plovimas pirmą dieną jau įskaičiuotas.
            continue;
        }
        // Pridedame 1, nes šventinę dieną būtinai plausime galvą, plius
        // suskaičiuojame kiek plovimų buvo nuo paskutinės šventinės dienos.
        answer += 1 + (d - last_d - 1) / 2;
        last_d = d;
    }

    // Pridedame paskutinę dieną.
    answer += (N - last_d) / 2;
    cout << answer << endl;

    return 0;
}
