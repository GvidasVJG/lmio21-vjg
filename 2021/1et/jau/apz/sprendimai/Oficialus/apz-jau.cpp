/**
 * Sprendimas uždaviniui "Akmuo, popierius, žirklės".
 *
 * Sprendimo idėja:
 * 
 * Kai skaičiuojame Viliaus didžiausią galimą taškų skaičių:
 *
 *   1) Priskiriame Viliui kiek įmanoma daugiau pergalių
 *   2) Priskyrę pergales, priskiriame kuo daugiau lygiųjų
 *   3) Visi likę žaidimai Viliui turi būti pralaimėjimai
 *
 * Gali būti ir daugiau optimalių ženklų suporavimų: 
 * kartais galime pergalę ir pralaimėjimą pakeisti į 2
 * lygiasias, tačiau bendras taškų skaičius nepakis.
 *
 * Skaičiuodami mažiausią Viliaus taškų skaičių darome atvirkščiai:
 * pirmiausiai priskiriame pralaimėjimus, tada lygiasias, tada pergales.
 * Taip pat galime panaudoti, kad [Adomo taškai] + [Viliaus taškai] = 0,
 * ir gauti Viliaus mažiausią taškų skaičių iš Adomo didžiausio.
 *
 * Algoritmo sudėtingumas: O(1) tiek atminties, tiek laiko atžvilgiu
 *
 * Autorius: Zigmas Bitinas
 */


#include <iostream>

using namespace std;

// suranda, kiek daugiausiai žaidejas 1 gali turėti tašku
int daugiausiai(int a1, int p1, int z1, int a2, int p2, int z2){
    int ats = 0;
    // kiek galima daugiau pergalių žaidejui 1
    int maz = min(a1, z2);
    a1 -= maz;
    z2 -= maz;
    int mzp = min(z1, p2);
    z1 -= mzp;
    p2 -= mzp;
    int mpa = min(p1, a2);
    p1 -= mpa;
    a2 -= mpa;
    // už kiekvieną pergalę po tašką
    ats += maz + mzp + mpa;

    // dabar kuo daugiau lygiųjų
    p1 -= min(p1, p2);
    a1 -= min(a1, a2);
    z1 -= min(z1, z2);

    // kas liko bus pralaimėjimai
    ats -= p1 + a1 + z1;
    return ats;
}

int main(){
    int a1, p1, z1, a2, p2, z2;
    cin >> a1 >> p1 >> z1 >> a2 >> p2 >> z2;
    // Didžiausias įmanomas Viliaus taškų skaičius
    cout<<daugiausiai(a1, p1, z1, a2, p2, z2)<<endl;
    // Mažiausias įmanomas Viliaus taškų skaičius
    // (skaičiuojamas kaip minus didžiausias Adomo taškų skaičius)
    cout<<-daugiausiai(a2, p2, z2, a1, p1, z1)<<endl;
}
