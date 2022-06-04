#include <iostream>
#include <vector>

using namespace std;

// Didžiausias bendras daliklis Euklido algoritmu.
int dbd(int a, int b) {
  while (b) a = a % b, swap(a, b);
  return a;
}

int main() {
  int N, R;
  cin >> N >> R;

  vector<int> A(R);
  for (auto &a : A) {
    cin >> a;
  }

  // Randama visų robotų veikimo laikų mažiausią bendrą kartotinį.
  int mbk = 1;
  for (const auto &a : A) {
    mbk = (mbk / dbd(mbk, a)) * a;
    // min(, N + 1) stabdo MBK augimą.
    // Jei MBM didesnis už N, tai užduoties atsakymas bus 0 (užduotis
    // nereikalavo to pastebėti, kadangi visada bus bent vienas pilnai
    // numargintas kiaušinis).
    mbk = min(mbk, N + 1);
  }

  cout << (N / mbk) << endl;

  return 0;
}
