// Laikome žvakes sąraše ir daliname tortą rekursyviai. Kiekvieno
// žingsnio metu žvakių sąrašą irgi padaliname į du sąrašus -- po
// vieną abiem naujiems gabalams.
//
// Svarbi optimizacija -- jei pasiekiame gabalą, kurį jau dalinome,
// tai rekursiją ties juo nutraukiame. Taip ne tik gauname teisingą
// atsakymą (nes neskaičiuojame to paties gabalo kelis kartus), bet
// ir smarkiai pagreitiname programą: kiekvieną gabalą prieisime
// daugiausia du, o ne K kartų.
//
// Koks tokio sprendimo sudėtingumas?
// * Iš pradžių skaičiuokime sudėtingumą M ir N atžvilgiu, nes taip
//   galvoti apie uždavinį yra lengviau. Vėliau šiuos skaičiavimus
//   išreikšime per K -- tik taip įsitikinsime, kad sprendimas yra
//   pakankamai greitas visoms dalinėms užduotims
// * Kiekvieną gabalą pasiekiame O(1) kartų, o iš viso yra O(NM)
//   pasiekiamų gabalų (nes yra O(M + M/2 + M/4 + ...) = O(M)
//   vertikalios ir O(N + N/2 + N/4 + ...) = O(N) horizontalios
//   dalinimo linijos)
// * Pasiektus gabalus galime laikyti arba set, arba unordered_set
//   duomenų struktūroje. Šiame sprendime rinkomės mažiau efektyvią
//   set struktūrą -- sudėtingumas O(NM log(NM)). Su unordered_set
//   struktūra sudėtingumas būtų dar geresnis -- O(NM)
// * Kiek užtrunka žvakių sąrašo manipuliavimas? Intuityviai galime
//   palyginti šį sprendimą su quicksort algoritmu ir nuspręsti,
//   kad "nebus blogiau nei K*(log K)^(kažkoks mažas laipsnis) --
//   užteks greičio". Išsamesnės analizės šiame komentare
//   nepateikiame (bet ji nėra smarkiai sunkesnė nei tai, ką čia
//   pateikiame)
// * Kad išreikštume skaičiavimus K atžvilgiu, net jei M, N yra labai
//   dideli, efektyvus torto plotas neviršija O(K), kadangi pjauti
//   galime daugiausia log K kartų, o kiekvienas pjovimas efektyvų
//   plotą padidina dukart
// * Sudėję viską kartu gauname
//   O(K*(log K)^(kažkoks mažas laipsnis)). Ribojimui K <= 100000
//   tokio sudėtingumo paprastai pakanka. Taip yra ir šio uždavinio
//   atžvilgiu
//
// Panašų sudėtingumą galima pasiekti įvairiais būdais ir ne visi jie
// iš karto tilps į laiko limitą. Kai kuriuos iš jų reikia optimizuoti
// naudojantis iš sistemos gautais rezultatais.
//
// Čia pateikiamas sprendimas specialiai nėra pilnai optimizuotas ir
// jis išsprendžia visus testus per 300ms.

#include <bits/stdc++.h>

using namespace std;

using Zvake = pair<int, int>;
using GabaluLentele = set<tuple<int, int, int, int>>;

int DalinkGabala(int v0, int v1, int h0, int h1, vector<Zvake> zvakes,
                 GabaluLentele &jau_dalinti_gabalai)
{
    auto yra_naujas = jau_dalinti_gabalai.emplace(v0, v1, h0, h1).second;
    if (!yra_naujas)
        return 0;
    if (zvakes.size() == 1)
        return 1;

    int rezultatas = 0;
    auto aukstis = v1 - v0;
    auto plotis = h1 - h0;

    if (aukstis % 2 == 0)
    {
        auto vidurys = (v0 + v1) / 2;
        vector<Zvake> apatines_zvakes;
        vector<Zvake> virsutines_zvakes;
        for (auto z : zvakes)
        {
            if (z.first < vidurys)
                apatines_zvakes.push_back(z);
            else
                virsutines_zvakes.push_back(z);
        }
        if (apatines_zvakes.size() == virsutines_zvakes.size())
        {
            rezultatas += DalinkGabala(v0, vidurys, h0, h1, apatines_zvakes,
                                       jau_dalinti_gabalai);
            rezultatas += DalinkGabala(vidurys, v1, h0, h1, virsutines_zvakes,
                                       jau_dalinti_gabalai);
        }
    }

    if (plotis % 2 == 0)
    {
        auto vidurys = (h0 + h1) / 2;
        vector<Zvake> kaires_zvakes;
        vector<Zvake> desines_zvakes;
        for (auto z : zvakes)
        {
            if (z.second < vidurys)
                kaires_zvakes.push_back(z);
            else
                desines_zvakes.push_back(z);
        }
        if (kaires_zvakes.size() == desines_zvakes.size())
        {
            rezultatas += DalinkGabala(v0, v1, h0, vidurys, kaires_zvakes,
                                       jau_dalinti_gabalai);
            rezultatas += DalinkGabala(v0, v1, vidurys, h1, desines_zvakes,
                                       jau_dalinti_gabalai);
        }
    }

    return rezultatas;
}

int main()
{
    int M, N, K;
    vector<Zvake> zvakes;
    GabaluLentele gabalai;

    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        int v, h;
        cin >> v >> h;
        zvakes.emplace_back(v, h);
    }

    auto rezultatas = DalinkGabala(0, M, 0, N, zvakes, gabalai);
    cout << rezultatas << endl;
    return 0;
}
