/**
 * Sprendimas uždaviniui "Elektromobilis"
 *
 * Sprendimas:
 * Atkreipkime dėmesį, kad jei Vytautas dabar yra mieste m su e elektros, tai yra nesvarbu, kuriuo keliu
 * jis ten nusigavo, kur ir kiek įkrovinėjo elektros. Svarbu tik tai, kad jis yra mieste m su e elektros.
 *
 * Taip pat atkreipkime dėmesį, kad valandų skaičius pabaigus krauti bateriją arba atvykus į miestą
 * visada yra sveikasis. Mūsų prašo rasti trumpiausią kelionės laiką.
 *
 * Dėl praeitų dviejų pastebėjimų, mes galim tiesiog daryt paiešką platyn tokiame kryptiniame grafe:
 * viršūnės yra (m, e) poros ir (m1, e1) -> (m2, e2) tada, kai:
 * (a) m1 = m2 ir e2 = min(e1 + c[m1], K) arba
 * (b) e1 >= L ir yra tiesiogis kelias iš m1 į m2 ir e2 = e1 - L
 *
 * (a) atitinka valandos elektros krovimą mieste m1.
 * (b) atitinka važiavimą iš miesto m1 į m2.
 *
 * Algoritmo sudėtingumas:
 * O((N + M) * K)
 *
 * Autorius:
 * Jonas Pukšta
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

// patogiai saugosime mūsų sugalvoto grafo viršūnę
struct virsune{
    int m, e;

    virsune(int miestas, int elektra){
        m = miestas;
        e = elektra;
    }
};

int main(){
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
    int N, M, K, L;
    cin >> N >> M >> K >> L;
    vector<int> c(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> c[i];

    // gret_miestai[m] yra sąrašas miestų, gretimų m
    vector<vector<int> > gret_miestai(N + 1);
    while (M--){
        int m1, m2;
        cin >> m1 >> m2;
        gret_miestai[m1].push_back(m2);
        gret_miestai[m2].push_back(m1);
    }

    const int begalybe = 1e9;
    // trump_laik[m][e] saugo, kiek mažiausiai laiko užtrunka atsidurti
    // mieste m su e elektros (su pradine reiškme 1e9)
    vector<vector<int> > trump_laik(N + 1, vector<int>(K + 1, begalybe));
    queue<virsune> virsunes;

    // pradedam mieste 1 turėdami 0 elektros
    virsunes.push(virsune(1, 0));
    // užtrunka 0 valandų atsirasti mieste 1 su 0 elektros
    trump_laik[1][0] = 0;

    // paieška platyn naujame grafe
    while (!virsunes.empty()){
        int m = virsunes.front().m;
        int e = virsunes.front().e;
        virsunes.pop();

        // galim pakrauti bateriją 1 valandą
        // atitinka kryptinę (a) tipo kraštinę
        int nauj_e = min(e + c[m], K);
        if (trump_laik[m][nauj_e] == begalybe){
            trump_laik[m][nauj_e] = trump_laik[m][e] + 1;
            virsunes.push(virsune(m, nauj_e));
        }

        if (e >= L){
            // galim nuvažiuot į kiekvieną kaimyninį miestą per 1 valandą
            // atitinka (b) tipo kraštinę
            for (int gret_m : gret_miestai[m])
                if (trump_laik[gret_m][e - L] == begalybe){
                    trump_laik[gret_m][e - L] = trump_laik[m][e] + 1;
                    virsunes.push(virsune(gret_m, e - L));
                }
        }
    }

    // surandam kiek mažiausiai laiko užtruko nuvažiuoti iki miesto N
    int ats = begalybe;
    for (int e = 0; e <= K; e++)
        ats = min(ats, trump_laik[N][e]);

    // jei mažiausias surastas laikas yra begalybe, tai kelio iš miesto
    // 1 į N nėra
    if (ats == begalybe)
        cout << -1;
    else
        cout << ats;
}
