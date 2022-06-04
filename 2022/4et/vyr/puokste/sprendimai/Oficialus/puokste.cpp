#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

int N, M;

bool geles[500][300];

int be_geliu_kaire[500][300], be_geliu_desine[500][300];

// Randa, kiek daugiausiai į kairę galima nueiti nuo duoto kambario nesutinkant nei vienos gėlės.
int BeGeliuIKaire(int i, int floor) {
    if (floor >= N) return i;
    return be_geliu_kaire[floor][i];
}

// Randa, kiek daugiausiai į dešinę galima nueiti nuo duoto kambario nesutinkant nei vienos gėlės.
int BeGeliuIDesine(int i, int floor) {
    if (floor >= N) return i;
    return be_geliu_desine[floor][i];
}

// Paruosia be_geliu_kaire ir be_geliu_desine masyvus.
void ParuostiBeGeliu() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j > 0 && !geles[i][j - 1])be_geliu_kaire[i][j] = be_geliu_kaire[i][j - 1];
            else be_geliu_kaire[i][j] = j;
        }
        for (int j = M - 1; j >= 0; --j) {
            if (j + 1 < M && !geles[i][j + 1])be_geliu_desine[i][j] = be_geliu_desine[i][j + 1];
            else be_geliu_desine[i][j] = j;
        }
    }
}

// Kiek yra būdų būti surinkus gėles iš intervalo dabartiniame aukšte.
long long dabartiniame_aukste[300][300];
// Kiek yra būdų būti paėmus vieną gėlę aukšte atitinkamoje vietoje. Tikra i-oji reikšmė yra visų verčių šiame masyve
// iki i suma,
long long kitame_aukste[300];

long long Spresti() {
    ParuostiBeGeliu();
    kitame_aukste[0] = 1;
    for (int aukstas = 0; aukstas < N; ++aukstas) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                dabartiniame_aukste[i][j] = 0;
            }
        }
        long long dabartine_suma = 0;
        for (int i = 0; i < M; ++i) {
            dabartine_suma = (dabartine_suma + kitame_aukste[i]) % mod;
            if (!geles[aukstas][i])continue;
            // Išplečiame intervalą, kad jis apimtų visus kambarius, kuriuos galima aplankyti paėmus tik dabar
            // nagrinėjamą gėle, bet jokių kitų gėlių šiame aukšte.
            int kairys_galas = BeGeliuIKaire(i, aukstas);
            int desinys_galas = BeGeliuIDesine(i, aukstas);
            dabartiniame_aukste[kairys_galas][desinys_galas] = dabartine_suma;
        }
        for (int i = 0; i < M; ++i) {
            kitame_aukste[i] = 0;
        }
        // Einame per visus intervalus dabartiniame aukšte.
        for (int ilgis = 0; ilgis < M; ++ilgis) {
            for (int kairys_galas = 0; kairys_galas < M; ++kairys_galas) {
                int desinys_galas = kairys_galas + ilgis;
                if (desinys_galas >= M)break;
                long long dabar = dabartiniame_aukste[kairys_galas][desinys_galas];
                if (dabar == 0)continue;
                // Jei kita paimama gėlė bus kairiau nuo intervalo.
                if (kairys_galas > 0) {
                    int paemus_gele_kaireje = BeGeliuIKaire(kairys_galas - 1, aukstas);
                    dabartiniame_aukste[paemus_gele_kaireje][desinys_galas] =
                            (dabartiniame_aukste[paemus_gele_kaireje][desinys_galas] + dabar) % mod;
                }
                // Jei kita paimama gėlė bus dešiniau nuo intervalo.
                if (desinys_galas + 1 < M) {
                    int paemus_gele_desineje = BeGeliuIDesine(desinys_galas + 1, aukstas);
                    dabartiniame_aukste[kairys_galas][paemus_gele_desineje] =
                            (dabartiniame_aukste[kairys_galas][paemus_gele_desineje] + dabar) % mod;
                }
                // Jei kita paimama gėlė bus kitame aukšte.
                // Randame intervalą kitame aukšte, kuriame yra kiekviena gėlė, kurią galima paimti pirmą kitame aukšte,
                // jeigu dabartiniame aukšte paimame dabar nagrinėjamą intervalą gėlių.
                int kitame_aukste_kaire = kairys_galas;
                int kitame_aukste_desine = desinys_galas;

                if (aukstas + 1 < N && !geles[aukstas + 1][kitame_aukste_kaire]) {
                    kitame_aukste_kaire = BeGeliuIKaire(kitame_aukste_kaire, aukstas + 1) - 1;
                    if (kitame_aukste_kaire < 0)kitame_aukste_kaire = 0;
                }
                if (aukstas + 1 < N && !geles[aukstas + 1][kitame_aukste_desine]) {
                    kitame_aukste_desine = BeGeliuIDesine(kitame_aukste_desine, aukstas + 1) + 1;
                    if (kitame_aukste_desine >= M)kitame_aukste_desine = M - 1;
                }

                kitame_aukste[kitame_aukste_kaire] = (kitame_aukste[kitame_aukste_kaire] + dabar) % mod;
                if (kitame_aukste_desine + 1 < M) {
                    kitame_aukste[kitame_aukste_desine + 1] =
                            (kitame_aukste[kitame_aukste_desine + 1] - dabar + mod) % mod;

                }

            }
        }
    }
    long long answer = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            answer = (answer + dabartiniame_aukste[i][j]) % mod;
        }
    }
    return answer;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            geles[i][j] = (c == 'X');
        }
    }
    cout << Spresti() << endl;
    return 0;
}