#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

enum class Vejas { NERA = 0, SIAURE = 1, RYTAI = 2, PIETUS = 3, VAKARAI = 4 };

struct Pozicija {
  Pozicija(int x, int y) : _x(x), _y(y) {}
  int _x, _y;

  void atspausinti_koordinates(int aukstis) {
    cout << _x << " " << aukstis - _y - 1 << endl;
  }
};

struct Langelis {
  Langelis(const Vejas &vejas, const bool viesulas, const bool uola)
      : _vejas(vejas), _viesulas(viesulas), _uola(uola) {}

  // Vėjas gali kisti priklausomai nuo to kiek esame padarę ėjimų.
  Vejas gauti_veja(int laikas) const {
    if (_viesulas && _vejas != Vejas::NERA) {
      // Skaičiuojame vėją (mod 4).
      return static_cast<Vejas>(
          ((static_cast<int>(_vejas) - 1) + laikas % 4) % 4 + 1);
    }
    return _vejas;
  }

  Pozicija pajudeti(const Pozicija &is, int laikas) const {
    Pozicija kita = is;

    switch (gauti_veja(laikas)) {
      case Vejas::NERA:
        break;
      case Vejas::SIAURE:
        kita._y -= 1;
        break;
      case Vejas::RYTAI:
        kita._x += 1;
        break;
      case Vejas::PIETUS:
        kita._y += 1;
        break;
      case Vejas::VAKARAI:
        kita._x -= 1;
        break;
    }

    return kita;
  }

  Vejas _vejas;
  bool _viesulas;
  bool _uola;
};

int main() {
  int plotis, aukstis;
  cin >> plotis >> aukstis;

  // Dėl patogumo apdėliojame salą dykumomis.
  aukstis += 2;
  plotis += 2;
  vector<vector<Langelis>> sala(
      aukstis, vector<Langelis>(plotis, {Vejas::NERA, /*viesulas=*/false,
                                         /*uola=*/false}));

  for (int y = 1; y < aukstis - 1; y += 1) {
    for (int x = 1; x < plotis - 1; x += 1) {
      int sk;
      cin >> sk;
      Langelis &langelis = sala[y][x];

      switch (sk) {
        case 0:
          break;

        case 1:
          langelis._vejas = Vejas::SIAURE;
          break;
        case 2:
          langelis._vejas = Vejas::RYTAI;
          break;
        case 3:
          langelis._vejas = Vejas::PIETUS;
          break;
        case 4:
          langelis._vejas = Vejas::VAKARAI;
          break;

        case 5:
          langelis._vejas = Vejas::SIAURE;
          langelis._viesulas = true;
          break;
        case 6:
          langelis._vejas = Vejas::RYTAI;
          langelis._viesulas = true;
          break;
        case 7:
          langelis._vejas = Vejas::PIETUS;
          langelis._viesulas = true;
          break;
        case 8:
          langelis._vejas = Vejas::VAKARAI;
          langelis._viesulas = true;
          break;

        case 9:
          langelis._uola = true;
          break;
      }
    }
  }

  int prad_x, prad_y;
  cin >> prad_x >> prad_y;
  // Koordinates laikome taip, kad kairys viršutinis langelis atitiktų (0, 0).
  Pozicija pozicija(prad_x, aukstis - prad_y - 1);

  // Joks langelis nebus aplankytas daugiau negu 4 kartus (keturi skirtingi
  // viesuliniai vėjai). Dėl paprastumo leidžiama simuliacija 5 kartus daugiau
  // nei turime langelių -- jei plunksna vis dar juda, ji niekada nenusileis.
  for (int laikas = 0; laikas < aukstis * plotis * 5; laikas += 1) {
    const Langelis langelis = sala[pozicija._y][pozicija._x];

    Pozicija kita_pozicija = langelis.pajudeti(pozicija, laikas);
    Langelis kitas_langelis = sala[kita_pozicija._y][kita_pozicija._x];

    // Jei kitame langelyje uola, reikia tęsti darbą (galbūt dabar stovime ant
    // vijurko).
    if (kitas_langelis._uola) {
      kita_pozicija = pozicija;
      kitas_langelis = langelis;
    }

    if (langelis._vejas == Vejas::NERA) {
      cout << 1 << endl;
      pozicija.atspausinti_koordinates(aukstis);
      return 0;
    }

    // Išskrendame iš ribų.
    if (kita_pozicija._x == 0 || kita_pozicija._x == plotis - 1 ||
        kita_pozicija._y == 0 || kita_pozicija._y == aukstis - 1) {
      cout << 2 << endl;
      pozicija.atspausinti_koordinates(aukstis);
      return 0;
    }

    pozicija = kita_pozicija;
  }

  cout << 0 << endl;

  return 0;
}
