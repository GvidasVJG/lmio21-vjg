/**
 * "Robotai-jau" sprendimas
 *
 * Kadangi robotų kvadratų dydžiai a yra maži (a <= 20, žr. robotai-vyr sprendimą
 * didesnėms a reikšmėms), pakanka patikrinti visus įmanomus robotų dydžius
 * nuo 1x1 iki 20x20 ir išvesti didžiausią, kuris gali įveikti trasą.
 *
 * Jei nei vienas robotas negalės įveikti trasos, išvedamas 0.
 *
 *
 * Langelis su koordinatėmis (i, j) laikomas 'pasiekiamu', jei visi langeliai
 * stačiakampyje su viršutiniu kairiuoju kampu (i, j) ir apatiniu dešiniuoju
 * kampu (i+a-1, j+a-1) yra laisvi ('.'). Ant tokių 'pasiekiamų' langelių galima
 * pastatyti roboto viršutinįjį kairįjį kampą.
 *
 * Norint patikrinti, ar langelis (i, j) yra pasiekiamas, šiai uždavinio versijai
 * tai pakanka padaryti su ciklu cikle, patikrinant ar kiekvienas anksčiau aprašyto
 * stačiakampio langelis yra laisvas.
 *
 *
 * Kvadrato dydžio a tikrinimas:
 *   1) Kiekvienam trasos langeliui nustatoma, ar langelis yra pasiekiamas.
 *   2) Vykdoma paieška į plotį/gylį pasiekiamais langeliais, ją pradedant nuo
 *   visų kairiojo stulpelio langelių. Jei paieška į plotį/gylį pasiekia dešiniojo
 *   stulpelio langelius, roboto kvadrato kraštinės dydis a yra tinkamas.
 *
 *
 * Sudėtingumas: O(nm(a_m)^3)
 *
 * Autorius: Dovydas Vadišius
**/

#include <bits/stdc++.h>

using namespace std;

int n, m, a;
char Trasa[502][502];
bool Aplankyta[502][502];

// Ar staciakampis su kampais (I, J) ir (I+a-1, J+a-1) neturi uzimtu '#' langeliu
bool arLaisvasKvadratas(int I, int J) {
    if (I + (a-1) > n) {
        return false;
    }
    int I2 = I + a - 1;
    int J2 = min(J+a-1, m);
    for (int i = I; i <= I2; i++) {
        for (int j = J; j <= J2; j++) {
            if (Trasa[i][j] == '#') {
                return false;
            }
        }
    }
    return true;
}

void dfs(int I, int J) {
    if (Aplankyta[I][J+1] == 0 && arLaisvasKvadratas(I, J+1) == true) {
        Aplankyta[I][J+1] = 1;
        dfs(I, J+1);
    }
    if (Aplankyta[I][J-1] == 0 && arLaisvasKvadratas(I, J-1) == true) {
        Aplankyta[I][J-1] = 1;
        dfs(I, J-1);
    }
    if (Aplankyta[I-1][J] == 0 && arLaisvasKvadratas(I-1, J) == true) {
        Aplankyta[I-1][J] = 1;
        dfs(I-1, J);
    }
    if (Aplankyta[I+1][J] == 0 && arLaisvasKvadratas(I+1, J) == true) {
        Aplankyta[I+1][J] = 1;
        dfs(I+1, J);
    }
}

bool robotoTikrinimas() {
    for (int i = 1; i <= n; i++) {
        if (arLaisvasKvadratas(i, 1) == true && Aplankyta[i][1] == 0) {
            Aplankyta[i][1] = 1;
            dfs(i, 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arLaisvasKvadratas(i, m) == true && Aplankyta[i][m] == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) {
            Trasa[i][j] = '.';  // Aplink lenta pridedamas laisvu ('.') langeliu remas
            Aplankyta[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> Trasa[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        a = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                Aplankyta[i][j] = 0;
            }
        }

        if (robotoTikrinimas()) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
