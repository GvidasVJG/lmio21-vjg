#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, R;
  cin >> N >> R;

  // Skirtingų a_i gali būti tik 100!
  const int max_a = 100;
  // Vienodi skaičiai nekeis atsakymo.
  vector<bool> A(max_a + 1, false);

  for (int i = 0; i < R; i += 1) {
    int a;
    cin >> a;
    A[a] = true;
  }

  int atsakymas = 0;
  for (int n = 1; n <= N; n += 1) {
    // Patikriname ar visi robotai nudažys kaišinį padėta n'tąją valandą.
    bool visi_dalus = true;
    for (int a = 1; a <= max_a; a += 1) {
      if (!A[a]) {
        continue;
      }

      visi_dalus = visi_dalus && (n % a == 0);
    }

    if (visi_dalus) {
      atsakymas += 1;
    }
  }

  cout << atsakymas << endl;

  return 0;
}
