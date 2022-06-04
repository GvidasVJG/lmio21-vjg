/**
 * Sprendimas uzdaviniui "Dviratis".
 *
 * Uzdavinys praso surasti, kiek daugiausiai skirtingu dienu Aleksas gales
 * pasinaudoti dviraciu. Is pavyzdziu matyti, kad kartais Aleksui geriau
 * nevaziuoti ta pacia diena pirmyn ir atgal dviraciu, o palikti ji darbe,
 * jeigu kitos dienos ryte lis (pvz, testas 1 1 ir 0 1).
 *
 * Taigi sprendziant si uzdavini patogiau yra sekti du variantus:
 *
 * 1) A[n] - kiek daugiausiai dienu Aleksas galejo pasinaudoti dviraciu per
 *    pirmas n dienu, kai n-tosios dienos vakare dviratis liko namie.
 * 2) B[n] - kiek daugiausiai dienu Aleksas galejo pasinaudoti dviraciu per
 *    pirmas n dienu, kai n-tosios dienos vakare dviratis liko darbe.
 *
 * A[n] bus lygus vienam is siu atveju:
 * 1) B[n - 1] + 1, jei n-taja diena Aleksas gali grizti is darbo dviraciu.
 * 2) A[n - 1] + 1, jei n-taja diena Aleksas gali ir nuvaziuoti, ir grizti.
 * 3) A[n - 1], priesingu atveju.
 *
 * Kadangi ieskome didziausio imanomo dienu skaiciaus, A[n] bus lygus
 * didesniajam skaiciui is dvieju.
 *
 * B[n] bus lygus:
 * 1) A[n - 1] + 1, jei n-taja diena Aleksas gali nuvaziuoti i darba dviraciu.
 * 2) B[n - 1] priesingu atveju.
 *
 * Pagal sia taisykle, galime pradeti nuo pirmosios dienos ir suskaiciuoti
 * atsakyma visoms likusioms dienoms. Atsakymas bus max(A[n], B[n]).
 *
 * Pavyzdys:
 * 2
 * 1 1
 * 0 1
 *
 * A[0] = 0; B[0] = -inf
 * A[1] = 1; B[1] = 1
 * A[2] = 2; B[2] = 1
 *
 * Atsakymas: max(A[2], B[2]) --> 2
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int a = 0, b = -N;
  for (int i = 0; i < N; i++) {
    int r, v;
    cin >> r >> v;

    int new_a = a;
    int new_b = b;
    if (r) { new_b = max(new_b, a + 1); }
    if (v) { new_a = max(new_a, b + 1); }
    if (r && v) { new_a = max(new_a, a + 1); }
    a = new_a;
    b = new_b;
  }

  cout << max(a, b) << endl;

  return 0;
}
