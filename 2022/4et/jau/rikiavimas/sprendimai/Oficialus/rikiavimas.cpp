#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;

// Funkcija skirta užklausų darymui.
// Patogumo dėlei, užduodant tą patį klausimą du kartus, antrasis atsakymas
// bus grąžintas be komunikacijos (t.y. atsakymai yra įsimenami).
int atsakymai[201][201];
int klausti(int i, int j) {
  int &a = atsakymai[i][j];
  if (a != 0) {
    return a - 2;
  }

  cout << "? " << i << " " << j << endl;
  cin >> a;

  // 0 naudojamas kaip "klausimas nebuvo užduotas", tad reikšmę reikia
  // pastumpti.
  a += 2;
  return a - 2;
}

// Ši funkcija paima p elementą iš x ir pertvarko y taip, kad visos reikšmės
// mažesnės už x[p] būtų y pradžioje, o didesnės pabaigoje.
//
// rev -- reiškia, kad x ir y yra sukeisti vietomis.
//
// Grąžina x[p] pozicija masyve y.
int atskirti(bool rev, vector<int> &x, vector<int> &y, int l, int h, int p) {
  int lygu = -1;
  vector<int> mazesnes;
  vector<int> didesnes;
  for (int j = l; j < h; j += 1) {
    int ats;
    if (!rev) {
      ats = klausti(x[p], y[j]);
    } else {
      ats = klausti(y[j], x[p]);
      ats *= -1;
    }
    if (ats == 0) {
      lygu = y[j];
    } else if (ats == -1) {
      didesnes.push_back(y[j]);
    } else if (ats == 1) {
      mazesnes.push_back(y[j]);
    }
  }

  for (int i = 0; i < static_cast<int>(mazesnes.size()); i += 1) {
    y[l + i] = mazesnes[i];
  }
  y[l + mazesnes.size()] = lygu;
  for (int i = 0; i < static_cast<int>(didesnes.size()); i += 1) {
    y[l + mazesnes.size() + 1 + i] = didesnes[i];
  }

  return l + mazesnes.size();
}

// Atliekamas quicksort per abu masyvus vienus metu.
// Funkcijos darbo pabaigoje elementai rėžyje [l; h) bus išrikiuoti.
void rikiavimas(vector<int> &x, vector<int> &y, int l, int h) {
  if (l == h || l + 1 == h) {
    return;
  }

  mt19937 gen(random_device{}());
  int p = uniform_int_distribution<>(l, h - 1)(gen);

  // Pertvarkome y taip, kad visi mažesni už x[p] būtų masyvo pradžioje.
  p = atskirti(false, x, y, l, h, p);
  // Pertvarkome x taip, kad visi mažesni už x[p] būtų masyvo pradžioje.
  atskirti(true, y, x, l, h, p);

  // Rekursyviai pertvarkome kitas dalis.
  rikiavimas(x, y, l, p);
  rikiavimas(x, y, p + 1, h);
}

vector<int> perkelti(const vector<int> &x) {
  vector<int> m(x.size() + 1);
  for (int i = 0; i < static_cast<int>(x.size()); i += 1) {
    m[x[i]] = i + 1;
  }

  vector<int> r;
  for (int i = 0; i < static_cast<int>(x.size()); i += 1) {
    r.push_back(m[i + 1]);
  }

  return r;
}

int main() {
  int N;
  cin >> N;

  vector<int> x(N);
  vector<int> y(N);
  for (int i = 1; i <= N; i += 1) {
    x[i - 1] = i;
    y[i - 1] = i;
  }

  rikiavimas(x, y, 0, N);
  x = perkelti(x);
  y = perkelti(y);

  cout << "!" << endl;
  for (int i = 0; i < N; i += 1) {
    cout << (i == 0 ? "" : " ") << x[i];
  }
  cout << endl;
  for (int i = 0; i < N; i += 1) {
    cout << (i == 0 ? "" : " ") << y[i];
  }
  cout << endl;

  return 0;
}
