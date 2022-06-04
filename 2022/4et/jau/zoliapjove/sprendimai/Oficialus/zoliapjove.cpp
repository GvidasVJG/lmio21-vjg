#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;

  // Nuskaitome pradinius žolės aukščius.
  vector<ll> auksciai(N);
  for (ll &aukstis : auksciai) {
    cin >> aukstis;
  }

  // Aukščių tvarka nesvarbi -- tai (1) uždavinio idėja, kadangi
  // ji leidžia laikyti pinai nukirptus žolės kuokštus "kairėje". Šių kuokštų
  // kirpti nereikės.
  // Sudėtingumas: O(Nlog(N)).
  sort(auksciai.begin(), auksciai.end());

  ll M;
  cin >> M;
  vector<ll> perejimu_sk(M);
  for (ll &perejimai : perejimu_sk) {
    cin >> perejimai;
  }

  // Aukščių suma nuo nulio skaičiuosime tik vieną kartą -- vėliau seksime
  // kaip suma keičiasi po kiekvieno kirpimo kaip visuma ((2) uždavinio idėja).
  // Sudėtingumas: O(N).
  ll auksciu_suma = 0;
  for (const ll &aukstis : auksciai) {
    auksciu_suma += aukstis;
  }

  // Pozicija pirmo kuokšto kuris nėra 0.
  ll ne_nulio_poz = 0;

  ll paaugo = 0;
  ll nukirpta = 0;

  // Ciklo vidus bus įvykdytas O(M) kartų.
  for (const ll &perejimai : perejimu_sk) {
    // Skaičiuojame kiek paaugimų ir nukirpimų buvo iki šios dienos.
    paaugo += 1;
    nukirpta += perejimai;

    // Visi dar nenukirpti kuokštai "juda" kartu. Tai nėra visiškai teisinga,
    // kadangi toks skaičiavimas gali nupjauti kai kuriuos kuokštus į neigiamą
    // aukštį -- šie aukščiai bus ištaisyti cikle žemiau.
    auksciu_suma += (N - ne_nulio_poz) * 1;
    auksciu_suma -= (N - ne_nulio_poz) * perejimai;

    // Randame pilnai nukirptus kuokštus ir ištaisome sumą.
    // Pastaba: kadangi ne_nulio_poz visada didėja, šio ciklo vidus bus
    // įvykdytas nedaugiau kaip O(N) kartų per visą programos veikimo laiką!.
    for (; ne_nulio_poz < N; ne_nulio_poz += 1) {
      const ll aukstis = auksciai[ne_nulio_poz];
      // Žinant bendrą paaugimų ir nukirpimų skaičių galima pasakyti koks
      // kuokšto aukštis.
      const ll naujas_aukstis = aukstis + paaugo - nukirpta;
      // Jei jis teigiamas, kuokštas dar nėra pilnai nukirptas ir jo aukštis yra
      // gerai įskaičiuotas į auksciu_suma.
      if (naujas_aukstis > 0) {
        break;
      }
      // Jei neigiamas (ar 0) kuokštas yra pilnai nukirptas ir reikia taisyti
      // sumą (į šį kuokštą daugiau nebežiūrėsime).
      auksciu_suma += -naujas_aukstis;
    }

    cout << auksciu_suma << endl;
  }

  return 0;
}
