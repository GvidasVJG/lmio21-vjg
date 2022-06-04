/**
 * Sprendimas uždaviniui "Šampūnas".
 *
 * Sprendimo idėja:
 * 
 * N dydžio loginiame masyve pasižymėsime visas šventines dienas. Toliau
 * naginėsime kiekvieną iš N dienų iš eilės, ir tikrinsime dvi paprastas
 * taisykles iš sąlygos: 1) ar šiandien šventinė diena, 2) ar vakar plauta
 * galva?
 *
 * Šis sprendimas pats paprasčiausias, bet reikalauja O(N) laiko ir atminties.
 *
 * Autorius: Linas Petrauskas
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<bool> holiday(N);
    for (int i = 0; i < K; i++) {
        int d; cin >> d;
        holiday[d - 1] = true;
    }

    int answer = 0;
    bool washed_yesterday = false;
    for (int i = 0; i < N; i++) {
        if (holiday[i] || !washed_yesterday) {
            answer += 1;
            washed_yesterday = true;
        } else {
            washed_yesterday = false;
        }
    }

    cout << answer << endl;

    return 0;
}
