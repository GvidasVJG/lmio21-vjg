/**
 * Sprendimas uždaviniui "Raketa".
 *
 * Sprendimo idėja:
 * Sprendimas pagrįstas dinaminiu programavimu. Jei žinome aukštį, į kurį galime pakilti, ir 
 * didžiausią greitį v_max, kai turime F kuro vienetų, tai su kuru F + 1:
 * - pažymėkime pradinį raketos pagreitį a. Tada pirmą sekundę pakylame a metrų.
 * - toliau kylame labai panašiai, kaip su F kuro vienetų, tik pradinis greitis ne 0, o a. Taigi 
 *   papildomai pakilsime F * a metrų daugiau
 * - pasibaigus kurui suskaičiuojame naują didžiausią greitį kaip senas_didziausias_greitis + a, ir
 *   pakylame dar į aukštį didziausias_greitis - g + didziausias_greitis - 2g + ... + 
 *   didziausias_greitis % g. Šį reiškinį nesunku suskaičiuoti naudojant aritmetinės progresijos 
 *   sumos formulę.
 * 
 * Tokio sprendimo laiko sudėtingumas yra O(N * K), nes užtenka išbandyti kuro kiekį iki K. Toks 
 * sprendimas surenka 57 taškus.
 *
 * Antras pastebėjimas yra tai, kad didelis kiekis pagreičių reikšmių bus vienodos. Galime 
 * tokias reikšmes sugrupuoti kartu ir didinti kuro kiekį ne po 1 vienetą, o iš karto pridėdami visą 
 * kuro grupę, kuri atitinka kažkurį pagreitį (tikslūs paaiškinimai pateikti prie kiekvienos formulės 
 * funkcijoje sprendimas žemiau). Galiausiai, kai esame arti atsakymo (t. y. žinome, su kokiu 
 * pagreičiu pradedame pakilimą), galime atlikti dvejetainę paiešką surasti tikslų atsakymą. 
 * 
 * Šio sprendimo sudėtingumas O(N*K^(1/2)), nes yra O(K^(1/2)) pagreičio grupių: gali būti skirtingi 
 * pagreičiai, kol kuro kiekis F <= K^(1/2), o kai F > K^(1/2), tai bus dar daugiausiai K^(1/2) 
 * skirtingų pagreičių, nes K / (M + F) < K^(1/2). Galutinė dvejetainė paieška užtrunka 
 * O(log K) < O(K^(1/2)).
 *
 * Abiejų sprendimų atminties sudėtingumas: O(1).
 *
 * Autorius: Daumilas Ardickas
 */

#include <iostream>

using namespace std;

// kiek daugiausiai kuro galima turėti raketoje, kad judėtume su teigiamu pagreičiu į viršų
long long daugiausiai_kuro(long long K, long long M, long long g){
    return -M + K / (g+1) + 1;
}

int sprendimas(long long M, long long K, long long H, long long g){
    // žymi maksimalų įmanomą atsakymą
    long long max_kuras = daugiausiai_kuro(K, M, g);

    long long dabartinis_kuras = 0;

    // žymi aukštį, kurį galima pasiekti su dabartiniu kuru iki jam pasibaigiant
    long long aukstis_kol_kuras = 0;

    // žymi aukštį, kurį galima pasiekti su dabartiniu kuru (įskaitant ir jam pasibaigus)
    long long aukstis = 0;

    // greitis, kuris pasiekiamas iš karto pasibaigus kurui
    long long didziausias_greitis = 0;
    while(aukstis < H && dabartinis_kuras <= max_kuras){
        // žymi pagreitį, kai kuro yra dabartinis_kuras + 1
        long long greicio_pokytis = K / (dabartinis_kuras + M) - g;

        // žymi didžiausią kiekį kuro, su kuriuo pagreitis lygus greicio_pokytis
        long long kuro_riba = daugiausiai_kuro(K, M, g + greicio_pokytis - 1);

        // naujo kuro kiekis, jei prisipildom iki kuro_riba
        long long naujas_kuras = kuro_riba - dabartinis_kuras;

        // perskaičiuojame visus dydžius, jei pripiltume kuro iki kuro_riba:

        // kiekvieną sekundę nuo kuro_riba iki dabartinis_kuras greitėjame per greicio_pokytis
        long long naujas_didziausias_greitis = didziausias_greitis + naujas_kuras * greicio_pokytis;

        // Galėjome pakilti į aukštį aukstis_kol_kuras su dabartinis_kuras kuro. Pradėdami su
        // kuro_riba kuro, mes naujas_kuras kartų pagreitėsime po greicio_pokytis, taigi pasieksime
        // aukštį greicio_pokytis * (1 + 2 + ... + naujas_kuras - 1), kol pasieksime dabartinis_kuras 
        // + 1 kuro. Toliau kilsime labai panašiai, kaip prie dabartinis_kuras kuro, tik mūsų 
        // pradinis greitis bus ne 0, o naujas_kuras * greicio_pokytis. Taigi dabartinis_kuras kartų
        // papildomai pakylame naujas_kuras * greicio_pokytis. Atkreipkite dėmesį, kad skridimą
        // greičiu naujas_didziausias_greitis priskaičiuojame prie aukstis_pasibaigus_kurui.
        long long naujas_aukstis_kol_kuras = aukstis_kol_kuras + naujas_kuras * greicio_pokytis * dabartinis_kuras + greicio_pokytis * naujas_kuras * (naujas_kuras - 1) / 2;

        // Suskaičiuojame aukštį, į kurį galima pakilti pasibaigus kurui. Iš pradžių turėsime
        // naujas_didziausias_greitis kuro, ir jis kas sekundę mažės po g. Kilsime, kol greitis bus
        // teigiamas. Taigi norime surasti greičių aritmetinės progresijos sumą (nuo a1 iki an).
        long long an = naujas_didziausias_greitis;
        long long a1 = an % g;
        long long n = (an - a1) / g + 1;
        long long naujas_aukstis_pasibaigus_kurui = n * (a1 + an) / 2;

        // bendras aukštis susidaro iš aukščio, kol turim kuro, ir aukščio po to, kai baigiasi kuras
        long long naujas_aukstis = naujas_aukstis_kol_kuras + naujas_aukstis_pasibaigus_kurui;
        if(naujas_aukstis >= H){
            // žinome, kad kuro_riba yra užtektinai kuro
            // atliekame dvejetainę paiešką, kad surastume tikslų atsakymą
            long long a = dabartinis_kuras;
            long long b = kuro_riba;
            while(b > a + 1){
                // tie patys skaičiavimai kaip aukščiau, tik su vid vietoj kuro_riba
                long long vid = (a + b) / 2;
                long long naujas_kuras = vid - dabartinis_kuras;
                long long naujas_aukstis_kol_kuras = aukstis_kol_kuras + naujas_kuras * greicio_pokytis * dabartinis_kuras + greicio_pokytis * naujas_kuras * (naujas_kuras - 1) / 2;
                long long naujas_didziausias_greitis = didziausias_greitis + naujas_kuras * greicio_pokytis;
                long long an = naujas_didziausias_greitis;
                long long a1 = an % g;
                long long n = (an - a1) / g + 1;
                long long naujas_aukstis_pasibaigus_kurui = n * (a1 + an) / 2;
                long long naujas_aukstis = naujas_aukstis_kol_kuras + naujas_aukstis_pasibaigus_kurui;
                if(naujas_aukstis < H) a = vid; // šio kuro neužtenka
                else b = vid; // šio kuro užtenka
            }
            return b; // mažiausias kiekis kuro, kurio užtenka
        }
        else{
            // atsakymui reikės daugiau nei kuro_riba kuro; pripilame iki kuro_riba
            aukstis = naujas_aukstis;
            aukstis_kol_kuras = naujas_aukstis_kol_kuras;
            didziausias_greitis += greicio_pokytis * naujas_kuras;
            dabartinis_kuras = kuro_riba;
        }
    }
    
    // nepavyko pakilti į H
    return -1;
}

int main(){
    long long N, g;
    cin>>N>>g;
    for(int i = 0; i < N; i++){
        long long K, M, H;
        cin >> K >> M >> H;
        cout << sprendimas(M, K, H, g) << endl;
    }
}