/**
 * Sprendimas uždaviniui "Kvantinis kompiuteris".
 *
 * Sprendimo idėja:
 * Sprendimas iš esmės nesudėtingas: einame kiekviena kryptimi (į viršų, apačią, 
 * dešinę, kairę) nuo jutiklio po vieną langelį, ir bandome ten pastatyti veidrodį.
 * Jeigu prieiname kraštą (su ar be veidrodžio), tai šiesos spinduliui judant atbulai
 * bus pataikyta į jutiklį.
 * Gana nesunku padaryti klaidą, jei kiekvienai krypčiai rašomas atskiras kodas. Yra
 * (bent) 2 būdai, kaip to galima išvengti:
 * * Kiekvieną kryptį pažymėti kaip vieną iš {0, +1}, {0, -1}, {+1, 0}, {-1, 0}, ir {x, y}
 *   statmenos kryptys tada yra {y, x} ir {-y, -x}.
 * * Bandyti pataikyti į jutiklį tik iš kažkurios vienos pusės ir sukioti mikroschemą.
 *   Po 4 pasukimų ir patikrinimų būsime patikrinę visus galimus variantus, ir sugrįžę į
 *   pradinę mikroschemos orientaciją. Šis metodas naudojamas šiame sprendime.
 *
 * Laiko ir atminties sudėtingumas: O(N*M).
 *
 * Autoriai: Martynas Budriūnas, Zigmas Bitinas
 */
 
#include <iostream>
#include <vector>

using namespace std;

bool atsakymas_rastas = false;
vector<string> mikroschema;
pair<int, int> jutiklio_pozicija;

void ieskoti_atsakymo_is_virsaus(){
    if(atsakymas_rastas)return;

    // pradedam nuo šios koordinatės ir einam į viršų
    int i = jutiklio_pozicija.first - 1, j = jutiklio_pozicija.second;
    int m = mikroschema[0].size();
    while(i > 0){
        if(mikroschema[i][j] != '.')return; // Atsitrenkėm į kažką, tikrai ne jutiklį
        // pabandom pastatyti veidrodį ant {i, j} ir šauti iš kairės
        for(int k = 0; k <= j; k++){
            if(k == j){ // pasiekėme veidrodį, taigi pataikom į mikroschemą
                atsakymas_rastas = true;
                mikroschema[i][j] = 'V';
                mikroschema[i][0] = 'L';
                return;
            }
            if(mikroschema[i][k] != '.') // atsitrankėme į kliūtį
                break;
        }
        // pabandom pastatyti veidrodį ant {i, j} ir šauti iš dešinės
        for(int k = j+1; k <= m; k++){
            if(k == m){ // pasiekėme kraštą; eidami atbulai pataikytume į mikroschemą
                atsakymas_rastas = true;
                mikroschema[i][j] = 'V';
                mikroschema[i][m-1] = 'L';
                return;
            }
            if(mikroschema[i][k] != '.') // atsitrankėme į kliūtį
                break;
        }
        i -= 1; // paeinam į viršų per vieną langelį
    }
    if(i == 0 && mikroschema[0][j] == '.'){ // suradom, kad galim šauti jutikliui iš viršaus be veidrodžio
        atsakymas_rastas = true;
        mikroschema[0][j] = 'L';
    }
}

// Pasukame mirkoschemą 90 laipsnių kampu
void pasukti_mikroschema(){
    int n = mikroschema.size();
    int m = mikroschema[0].size();
    vector<string>nauja_mikroschema(m, string(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            nauja_mikroschema[j][n-1-i] = mikroschema[i][j];
            if(nauja_mikroschema[j][n-1-i] == 'J')
                jutiklio_pozicija = {j, n-1-i};
        }
    }
    mikroschema = nauja_mikroschema;
}

int main(){
    int N, M;
    cin >> N >> M;
    mikroschema.resize(N);
    for(int i = 0; i < N; i++) cin >> mikroschema[i];

    // surandam jutiklį
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(mikroschema[i][j] == 'J') jutiklio_pozicija = {i, j};
        }
    }

    // 4 kartus ieškome atsakymo į viršų ir pasukame mikroschemą
    // Po 4 pasisukimų mikroschema grįš į pradinę padėtį
    for(int i = 0; i < 4; i++){
        ieskoti_atsakymo_is_virsaus();
        pasukti_mikroschema();
    }

    if(atsakymas_rastas){
        for(auto &eilute: mikroschema)
            cout<<eilute<<endl;
    }
    else cout<<"NEPASIEKIAMA"<<endl;
}
