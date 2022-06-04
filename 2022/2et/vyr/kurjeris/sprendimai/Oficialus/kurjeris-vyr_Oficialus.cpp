#include <iostream>
#include <vector>

const int MAX_Z = 100;

std::vector<int> dirba_iki;
std::vector<int> uzdarbis;

int main() {
    int n, m;
    std::cin >> n >> m;

    // Dienos pradžioje kurjeriai nedirba
    dirba_iki.assign(n, 0);
    // ir nėra dar nieko uždirbę
    uzdarbis.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int t, v, min_j, min_z = MAX_Z + 1;
        std::cin >> t >> v;
        // Ieškome kurjerio, kuris yra laisvas ir greičiausia įvykdytų užsakymą
        for (int j = 0; j < n; j++) {
            int z;
            std::cin >> z;
            if (z < min_z && dirba_iki[j] <= t) {
                min_z = z; min_j = j;
            }
        }
        if (min_z <= MAX_Z) {
            // kurjeris rastas, pasižymime, iki kada jis užimtas ir priskiriame uždarbį
            dirba_iki[min_j] = t + min_z;
            uzdarbis[min_j] += v;
        }
    }

    std::cout << uzdarbis[0];
    for (int i = 1; i < n; i++)
        std::cout << " " << uzdarbis[i];

    return 0;
}