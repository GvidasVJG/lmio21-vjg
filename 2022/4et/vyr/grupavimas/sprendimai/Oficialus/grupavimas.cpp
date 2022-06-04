#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, R;
  cin >> N >> R;

  // Nusiskaitome žodžius kaip skaičius, kur skaičiaus i-tasis
  // bitas nurodo ar žodyje pasirodė i-toji abėcėlės raidė.
  auto zodziu_raides = vector<int>(N, 0);
  for (int i = 0; i < N; i++) {
    string zodis;
    cin >> zodis;

    for (const auto& raide : zodis) {
      int raides_eile = raide - 'A';
      zodziu_raides[i] |= 1 << raides_eile;
    }
  }

  // Atsakymas negali būti didesnis nei galimų raidžių skaičius.
  int atsakymas = R;

  // Pabandome visus grupavimo variantus su pora 
  // optimizacijų ir taip randame geriausią atsakymą.
  for (int pasirinktos_raides = 1; pasirinktos_raides < (1<<R); 
      pasirinktos_raides++) {

    // Suskaičiuojame kelių raidžių sprendimą bandome.
    int raidziu_skaicius = 0;
    for (int raides_eile = 0; raides_eile < R; raides_eile++) {
      if ((pasirinktos_raides & (1 << raides_eile)) > 0) {
        raidziu_skaicius++;
      }
    }

    // Jei jau radome tokį pat arba geresnį sprendimą, šio
    // galime netikrinti.
    if (raidziu_skaicius >= atsakymas) continue;

    // Patikriname, kad kiekvienas žodis patenka bent į vieną
    // iš pasirinktų grupių.
    bool sprendimas_teisingas = true;
    for (const auto& zodzio_raides : zodziu_raides) {
      // Jeigu žodyje esančios raidės nepatenka nei į vieną grupę,
      // grupavimas neteisingas ir galime daugiau žodžių netikrinti.
      if ((zodzio_raides & pasirinktos_raides) == 0) {
        sprendimas_teisingas = false;
        break;
      }
    }

    if (sprendimas_teisingas) {
      atsakymas = raidziu_skaicius;
    }
  }

  cout << atsakymas << endl;
}
