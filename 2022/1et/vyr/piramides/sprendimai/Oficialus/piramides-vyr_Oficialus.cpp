#include <iostream>

int main() 
{
    int n;
    std::cin >> n;

    // kartojame, kol yra kaladėlių
    while (n > 0) {
        // k - piramidės aukštis arba pagrinde esančių kaladėlių skaičius - abu lygūs.
        int k;
        // kiekvienam k nuo 1 tikrinime, ar užtenka piramidei reikalingų kaladėlių.
        // Piramidei reikalingų kaladėlių skaičių apskaičiuojame naudodamiesi
        // aritmetinės progresijos formule: (k + 1) * k / 2
        for (k = 1; (k + 1) * k / 2 <= n; k++);
        k--; // sumažiname per vieną, nes su parinktu k kaladėlių jau nebeužtenka
        std::cout << k << "\n";
        // apskaičiuojame likusių kaladėlių skaičių
        n -= (k + 1) * k / 2;
    }

    return 0;
}