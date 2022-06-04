/**
 * Sprendimas uždaviniui "Lankomumo žymėjimas".
 *
 * Sprendimo idėja:
 *
 * Jei Neringa pasirenka i-tąjį mokinį pirmą, tai paskutinis mokinys bus tas,
 * kuris turi pašaukti i-tąjį mokinį. Tam užtenka pereiti per mokiniams priskirtų
 * mokinių numerius a_j, surasti tą a_j, kur a_j = i, ir išvesti j.
 * 
 * Algoritmo sudėtingumas: O(N) laiko atžvilgiu, O(1) atminties.
 *
 * Autorius: Andrius Ovsianas
 */

#include <stdio.h>

using namespace std;

int N, q;
int a;
int s;

int main() {
    scanf("%d %d", &N, &q);

    for (int i = 0;i < N;++i) {
        scanf("%d", &a);
        if (a == q) {
           printf("%d\n", i + 1);
           break;
        }
    }
    
    return 0;
}
