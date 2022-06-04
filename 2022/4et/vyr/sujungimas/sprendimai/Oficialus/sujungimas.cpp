#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <vector>
using namespace std;

// Begalybė... plius minus :) Galima naudoti ir bet kokį kitą didelį skaičių.
const int oo = numeric_limits<int>::max();

struct Miestas {
  int verte;
  int spalva = -1;
  vector<int> linijos;
};

// Miestus pasiekiamus iš m nuspalviname duotąja spalva.
void dfs(int m, int spalva, vector<Miestas> &miestai) {
  auto &miestas = miestai[m];

  // Jei miestas nuspalvintas, nieko daryti nereikia.
  // Pastaba: tai reiškia, kad dfs(m, spalva) nebūtinai pakeis miesto m spalvą,
  // bet tai palengvina kitas programos dalis.
  if (miestas.spalva != -1) {
    return;
  }
  miestas.spalva = spalva;

  for (int kitas : miestas.linijos) {
    dfs(kitas, spalva, miestai);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<Miestas> miestai(N);

  for (auto &m : miestai) {
    cin >> m.verte;
  }

  // Sukonstruojame miestų grafą.
  for (int i = 0; i < M; i += 1) {
    int u, v;
    cin >> u >> v;
    // Linijos eina į abi puses.
    miestai[u - 1].linijos.push_back(v - 1);
    miestai[v - 1].linijos.push_back(u - 1);
  }

  // Randame jungias komponentes. Miestams esantiems jungioje komponentėje
  // priskirsime unikales spalvas.
  for (int i = 0; i < N; i += 1) {
    dfs(i, i, miestai);
  }

  // Kiekvienoje jungioje komponentėje randame miestą su mažiausia verte.
  // Linijos bus jungiamos tik į/iš šių miestą, kadangi jungimas su ne pigiausiu
  // miestu didins linijos tiesimo kainą.
  map<int, int> grupes;
  for (auto &m : miestai) {
    grupes[m.spalva] = +oo;
  }
  for (auto &m : miestai) {
    grupes[m.spalva] = min(grupes[m.spalva], m.verte);
  }

  // Pats pigiausias miestas.
  pair<int, int> mm = {+oo, -1};
  for (auto &[spalva, verte] : grupes) {
    mm = min(mm, {verte, spalva});
  }

  int ats = 0;
  // Kiekvienos jungios komponentės pigiausią miestą jungiame su pačiu pigiausiu
  // miestu.
  for (auto &[spalva, verte] : grupes) {
    if (mm != make_pair(verte, spalva)) {
      ats += mm.first * verte;
    }
  }

  cout << ats << endl;

  return 0;
}
