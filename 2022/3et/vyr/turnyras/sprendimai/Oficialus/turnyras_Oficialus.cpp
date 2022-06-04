#include <iostream>
#define MAXN 1<<16
int n, k, j, a[MAXN], b[MAXN], i, t;
bool id;
using namespace std;

//Išrikiuoja seką taip, kad ji būtų mažiausia identiška duotai sekai,
//t.y. a_1 mažiausias kiek įmanoma, tada a_2 kuo mažesnis ir t.t.
//Pirmiausia rekursiškai taip pat išrikiuojamos abi turnyro šakos 
//(t.y. pirma pusė ir antra pusė žaidėjų), tada jei pirmo pirmos šakos žaidėjo 
//numeris didesnis nei pirmo antros šakos žaidėjo, šakos sukeičiamos vietomis.
void sort(int* x, int m) {
	m /= 2;
	if (m-1) {
		sort(x, m);
		sort(x+m, m);
	}
	if (*x < *(x+m)) return;
	for (i = 0; i < m; i++) {
		t = *(x+i); *(x+i) = *(x+i+m); *(x+i+m) = t;
	}
}

int main(){
	cin >> n >> k;
	for (i = 0; i < n; i++) cin >> a[i];
	//Pakeičiame seką į mažiausią jai identišką
	sort(a, n);
	for (j = 0; j < k; j++) {
		for (i = 0; i < n; i++) cin >> b[i];
		//Pakeičiame seką į mažiausią jai identišką
		sort(b, n);
		//Patikriname, ar sekos lygios
		id = 1;
		for (i = 0; i < n; i++) id &= a[i] == b[i];
		cout << (id ? "TAIP" : "NE") << endl;
	}
}