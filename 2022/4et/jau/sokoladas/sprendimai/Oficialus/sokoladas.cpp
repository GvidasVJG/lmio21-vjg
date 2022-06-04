#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

using namespace std;

const int oo = numeric_limits<int>::max();

struct Langelis {
  int y, x;

  friend ostream &operator<<(ostream &os, const Langelis &l) {
    return os << "{" << l.y << ", " << l.x << "}";
  }
};

int main() {
  int M, N, G;
  cin >> M >> N >> G;

  // Surenkame visų sričių koordinates.
  map<int, vector<Langelis>> sritys;
  for (int y = 0; y < M; y += 1) {
    for (int x = 0; x < N; x += 1) {
      int g;
      cin >> g;
      sritys[g].push_back({y, x});
    }
  }

  for (const auto &[sritis, langeliai] : sritys) {
    // Randame sirties kampus.
    Langelis kairys_virsutinis{+oo, +oo};
    Langelis desinys_virsutinis{+oo, -oo};
    Langelis kairys_apatinis{-oo, +oo};
    Langelis desinys_apatinis{-oo, -oo};

    for (const auto &langelis : langeliai) {
      if (langelis.x <= kairys_virsutinis.x &&
          langelis.y <= kairys_virsutinis.y) {
        kairys_virsutinis = langelis;
      }

      if (langelis.x >= desinys_virsutinis.x &&
          langelis.y <= desinys_virsutinis.y) {
        desinys_virsutinis = langelis;
      }

      if (langelis.x <= kairys_apatinis.x && langelis.y >= kairys_apatinis.y) {
        kairys_apatinis = langelis;
      }

      if (langelis.x >= desinys_apatinis.x &&
          langelis.y >= desinys_apatinis.y) {
        desinys_apatinis = langelis;
      }
    }

    // Sistema ignoruoja cerr išveimą, tačiau išvestis užtrunka. Tad
    // prieš siuntimą verta užkomentuoti arba izoliuoti su `ifndef EVAL`
    // (EVAL yra makro nurodyta kompiliavimo metu, žr. sokoladas-jau > Nuostatos
    // > Kompiliavimo komandos).
#ifndef EVAL
    cerr << sritis << " = {kairys_virsutinis:" << kairys_virsutinis
         << ", desinys_virsutinis: " << desinys_virsutinis
         << ", kairys_apatinis: " << kairys_apatinis
         << ", desinys_apatinis: " << desinys_apatinis << "}" << endl;
#endif

    // Tikriniame ar stačiakampis.
    if (!(
            // Viršus.
            kairys_virsutinis.y == desinys_virsutinis.y &&
            // Apačia.
            kairys_apatinis.y == desinys_apatinis.y &&
            // Kairė.
            kairys_virsutinis.x == kairys_apatinis.x &&
            // Dešinė.
            desinys_virsutinis.x == desinys_apatinis.x)) {
      cout << "NE" << endl;
      return 0;
    }

    // Tikriniame ar pilnai užpildytas.
    const int plotas = (kairys_apatinis.y - kairys_virsutinis.y + 1) *
                       (desinys_virsutinis.x - kairys_virsutinis.x + 1);
    if (plotas != static_cast<int>(langeliai.size())) {
      cout << "NE" << endl;
      return 0;
    }
  }

  cout << "TAIP" << endl;

  return 0;
}
