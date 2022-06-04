#include <iostream>
using namespace std;

int main() {
  int N, k;
  cin >> N >> k;
  N += k - 1;

  string prognoze;
  cin >> prognoze;

  // Kiek lietingų dienų yra slenkančiame lange kurio ilgis k.
  int lietingu_dienu = 0;

  int geriausia_diena = 1;
  int daugiausiai_lietingu_dienu = 0;
  for (int lango_paskutine_diena = 0; lango_paskutine_diena < N;
       lango_paskutine_diena += 1) {
    const int lango_pirma_diena = lango_paskutine_diena - k + 1;

    // Pridedame naujausią dieną į slenkantį intervalą.
    lietingu_dienu += prognoze[lango_paskutine_diena] == 'L';
    // Išmetame seniausią dieną iš slenkančio intervalo.
    if (lango_pirma_diena - 1 >= 0) {
      lietingu_dienu -= prognoze[lango_pirma_diena - 1] == 'L';
    }

    if (lango_pirma_diena >= 0 && daugiausiai_lietingu_dienu < lietingu_dienu) {
      geriausia_diena = lango_pirma_diena + 1;
      daugiausiai_lietingu_dienu = lietingu_dienu;
    }
  }

  cout << geriausia_diena << endl;

  return 0;
}
