#include <algorithm>
#include <iostream>

/*
Sprendimo idėja:
1. išrikiuojame visus turimus skaičius didėjimo arba mažėjimo tvarka.
Sąlygoje duota, kad visi skaičiai skirtingi.
2. Jei sugrupuotume skaičius po du, tai galima sukeisti tose porose
esančius skaičius ir gausime vieną iš galimų atsakymų.
Uždavinio sprendimų gali būti ir kitokių.
*/
using namespace std;

int main()
{
    int n;
    int sk[1000];

    // nuskaitome pradinius duomenis
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sk[i];
    }
    // išrikiuojame skaičius
    sort(sk, sk + n);

    // sukeičiame po du skaičius
    for (int i = 0; i < n-1; i += 2) {
        swap(sk[i], sk[i+1]);
    }

    for (int i = 0; i < n; i++) {
        cout << sk[i] << " ";
    }

    return 0;
}
