#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // Nuskaitome egzistuojančių stotelių pozicijas.
  vector<int> stoteles;
  for (int i = 0; i < N; i += 1) {
    int stotele;
    cin >> stotele;
    // Mums rūpi tik toks stotelės kurios yra prieš nustatytą atstumo ribą.
    if (stotele < K) {
      stoteles.push_back(stotele);
    }
  }

  // Dvi netikros stotelės kelionės pradžio ir pabaigos koordinatėms.
  stoteles.push_back(0);
  stoteles.push_back(K);

  // Išsirikiuojame.
  sort(stoteles.begin(), stoteles.end());

  // Atsakymas -- didžiausias atstumas tarp dviejų šalimų stotelių.
  int atsakymas = 0;
  for (int i = 0; i < static_cast<int>(stoteles.size()) - 1; i += 1) {
    atsakymas = max(atsakymas, stoteles[i + 1] - stoteles[i]);
  }

  cout << atsakymas << endl;

  return 0;
}
