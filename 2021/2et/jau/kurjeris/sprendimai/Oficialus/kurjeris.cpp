/**
 * Sprendimas uždaviniui "Kurjeris".
 *
 * Sprendimo idėja:
 * Kurjeriui nėra prasmės apsisukti daugiau negu vieną kartą. Iš visų duotų
 * adresų galime rasti tolimiausią miestą, iki kurio reikės nuvažiuoti. O visus
 * kitus siuntinius kurjeris gali palikti "pakeliui". Tačiau reikia taip pat
 * patikrinti, kad kiekvienas siuntinys atkeliaus laiku. Tą galime padaryti
 * tiesiog suskaičiavę atstumą nuo sandėlio iki kiekvieno miesto, ir
 * patikrindami, ar kiekvieno užsakymo laikas nėra didesnis už šį atstumą.
 *
 * Autorius: Linas Petrauskas
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> dist(N + 1);
    // Tiesiogiai suskaičiuojame atstumus nuo sandėlio iki kiekvieno miesto:
    // atstumas(i) = atstumas(i - 1) + m_i.
    for (int i = 1; i <= N; i++) {
        int m; cin >> m;
        dist[i] = dist[i - 1] + m;
    }
    int max_a = 0;
    int possible = true;
    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int a, t; cin >> a >> t;
        if (t < dist[a])
            possible = false;
        max_a = max(max_a, a);
    }
    if (possible) {
        cout << dist[max_a] * 2 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
