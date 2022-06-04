/**
 * "Robotai-vyr" sprendimas
 *
 * Naudojama dvejetainė paieska didžiausiam roboto kvadrato dydžiui a nustatyti.
 *
 * Langelis su koordinatėmis (i, j) laikomas 'pasiekiamu', jei visi langeliai
 * stačiakampyje su viršutiniu kairiuoju kampu (i, j) ir apatiniu dešiniuoju
 * kampu (i+a-1, j+a-1) yra laisvi ('.'). Ant tokių 'pasiekiamų' langelių galima
 * pastatyti roboto viršutinįjį kairįjį kampą.
 *
 *
 * Tam, kad greitai būtų surasti visi 'pasiekiami' langeliai, galima
 * naudoti 2D prefix sumų lentelę UzimtiDp[i][j],
 * rodančią, kiek užimtų langelių yra stačiakampyje su kampais (0,0) ir (i,j)).
 *
 * Lentelės užpildymas:
 *
 * UzimtiDp[i][j] = UzimtiDp[i-1][j] + UzimtiDp[i][j-1] - UzimtiDp[i-1][j-1] +
 * + arYraSiena[i][j]
 *
 * arYraSiena[i][j] yra 1, kai langelis (i, j) yra užimtas,
 * kitu atveju arYraSiena[i][j] lygi 0.
 *
 *
 * Tada, stačiakampyje su viršutiniu kairiuoju kampu (i,j) ir apatiniu
 * dešiniuoju kampu (i2, j2) yra uzimtiLangeliai[i][j] '#' langelių:
 *
 * uzimtiLangeliai[i][j] = UzimtiDp[i2][j2] - UzimtiDp[i-1][j2] - UzimtiDp[i2][j-1] +
 *   + UzimtiDp[i-1][j-1]
 *                                (Čia i2 > i ir j2 > j)
 *
 * Jei uzimtiLangeliai[i][j] yra lygus 0 (šiame stačiakampyje nėra '#'
 *  langelių), roboto viršutinis kairysis kampas gali buti pastatytas ant
 *  langelio (i, j), tada langelis (i, j) yra pasiekiamas.
 *
 *
 *
 *
 * Kvadrato dydžio a tikrinimas dvejetainėje paieškoje:
 *   1) Užpildoma UzimtiDp[i][j] lentelė
 *   2) Kiekvienam trasos langeliui suskaičiuojama 'uzimtiLangeliai[i][j]' reikšmė,
 *   pagal ją nustatoma, ar langelis yra pasiekiamas
 *   3) Kai visi pasiekiami langeliai yra surasti, vykdoma paieška į plotį/gylį
 *   pasiekiamais langeliais, ją pradedant nuo visų kairiojo stulpelio langelių.
 *   Jei paieška į plotį/gylį pasiekia dešiniojo stulpelio langelius,
 *   roboto kvadrato kraštinės dydis a yra tinkamas.
 *
 *
 * Sudėtingumas: O(nm log(n))
 *
 * Autorius: Dovydas Vadišius
**/

#include <bits/stdc++.h>

using namespace std;

int n, m, a;
char Trasa[502][502];
int UzimtiDp[502][502];
bool Aplankyta[502][502];

// Ar staciakampis su kampais (I, J) ir (I+a-1, J+a-1) neturi uzimtu '#' langeliu
bool arLaisvasKvadratas(int I, int J) {
    if (I + (a-1) > n) {
        return false;
    }
    int I2 = I + a - 1;
    int J2 = min(J+a-1, m);
    if (UzimtiDp[I2][J2] - UzimtiDp[I-1][J2] - UzimtiDp[I2][J-1] + UzimtiDp[I-1][J-1] > 0) {
        return false;
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

bool dvejetainePaieska() {
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
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m;

        for (int i = 0; i <= n+1; i++) {
            for (int j = 0; j <= m+1; j++) {
                Trasa[i][j] = '.';  // Aplink trasą pridedamas laisvų ('.') langelių rėmas
                UzimtiDp[i][j] = 0;
                Aplankyta[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> Trasa[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                UzimtiDp[i][j] = UzimtiDp[i-1][j] + UzimtiDp[i][j-1] - UzimtiDp[i-1][j-1];
                if (Trasa[i][j] == '#') {
                    UzimtiDp[i][j]++;
                }
            }
        }

        int kaire = 0, desine = n, tikrinamasA;
        while (desine - kaire > 1) {     // Dvejetainė paieška
            tikrinamasA = (kaire + desine) / 2;
            a = tikrinamasA;

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    Aplankyta[i][j] = 0;
                }
            }

            if (dvejetainePaieska()) {
                kaire = tikrinamasA;
            }
            else {
                desine = tikrinamasA;
            }
        }

        cout << kaire << endl;
    }
    return 0;
}
