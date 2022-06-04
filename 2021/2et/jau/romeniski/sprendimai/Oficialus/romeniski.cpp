/**
 * Sprendimas uždaviniui "Apgavikas".
 *
 * Sprendimo idėja:
 *
 * Pasižymėkime masyvą S su visais romėniškais skaičiais iš eilės. Tuomet kiekvienam 
 * romėniškam skaičiui pereikime per duotą simbolių eilutę s ir patikrinkime
 * ar yra nors vienas posekis lygus šiam romėniškam simboliui. Jei tokį posekį
 * randame - galime atspausdinti tą romėnišką skaičių atitinkantį numerį, ir 
 * tęsti su kitu.
 *
 * Autorius: Irus Grinis
 */

#include <iostream>

using namespace std;

const string S[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};
string s;
int n;

int main() {

    cin >> n;
    cin >> s;

    for (int i = 0;i < 12;++i) {
        for (int j = 0;j < n - int(S[i].size()) + 1;++j) {
            bool tinka = true;
            for (int k = 0;k < S[i].size();++k) {
                if (S[i][k] != s[j + k]) {
                    
                    tinka = false;
                    break;
                }
            }

            if (tinka) {
                cout << i + 1 << " ";
                break;
            }
        }
    }

    cout << "\n";
    
    return 0;
}
