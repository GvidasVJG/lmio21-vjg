#include <iostream>
#include <algorithm>

int main()
{
    unsigned int skaitmenys[3];
    std::cin >> skaitmenys[0] >> skaitmenys[1] >> skaitmenys[2];
    unsigned int x;
    std::cin >> x;
    
    std::sort(skaitmenys, skaitmenys + 3);

    unsigned int skaiciai[6];    
    unsigned int indeksas = 0;
    for (unsigned int i = 0; i < 3; ++i)
        for (unsigned int j = 0; j < 3; ++j)
            for (unsigned int k = 0; k < 3; ++k)
                if (i != j && i != k && j != k)
                    skaiciai[indeksas++] = skaitmenys[i] * 100 + skaitmenys[j] * 10 + skaitmenys[k];

    std::cout << std::find(skaiciai, skaiciai+6, x) - skaiciai + 1;
}
