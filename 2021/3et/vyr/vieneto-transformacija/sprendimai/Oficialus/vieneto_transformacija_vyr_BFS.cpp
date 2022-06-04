#include <cstdio>
#include <iostream>
#include <fstream>

#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>      


// Pagalbinės preprocesoriaus konstantos:  
#define u64      uint64_t 
#define u8       uint8_t 
//---------------------------------------
using namespace std;
//žžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžž

vector<u64> v;                                  // Tiriamųjų skaičių eilė
map<u64, u64> ats;                              // Einamųjų atstumų (transformaacijos kainų) žodynas 

//------------------------------------------------------------------------------
// Funkcijoje bandoma „atimti“ 1 iš paskutiniojo (dešiniausio)  skaitmens.
// Jeigu tai įmanoma, grąžina skaičių, kuris pasižymi tuo, 
// kad pridėjus prie paskutiniojo skatmens 1 pagal uždavinio sąlygos 
// taisykles, gausime „n“ (funckijos parametras).
// Pvz. 1. Jeigu „n“ yra 15, tai funkcija grąžins 14.
// Pvz. 2. Jeigu „n“ yra 210, tai funkcija grąžins 29.
// Jeigu atitinkamo skaičiaus nėra, pvz. 20, tai funkcija  grąžina 0
//-------------------------------------------------------------------------------
u64 atimik1Gale(u64 n){  
   
   u64 psk = n % 10;
   if (psk > 0) return n - 1;
   else if (n / 10 % 10 == 1) return (n / 100) * 10 + 9;
        else return 0;

}
//-------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Funkcijoje bandoma „atimti“ 1 iš pirmojo (kairiausiojo)  skaitmens.
// Funkcija veikia analogiškai funkcijai „atimik1Gale(...)“
// Pvz. 1. Jeigu „n“ yra 25, tai funkcija grąžins 15.
// Pvz. 2. Jeigu „n“ yra 1011, tai funkcija grąžins 911.
// Jeigu atitinkamo skaičiaus nėra, pvz. 115, tai funkcija  grąžina 0.
//-------------------------------------------------------------------------------

u64 atimik1Priekyje(u64 n){  
   if (n == 1) return 0;
   string sn = to_string(n);
   if (sn[0] > '1')
      sn[0] -= 1;
   else if (sn[1] == '0'){
           sn[0]='0'; sn[1]='9';
         }
        else return 0; 
      
   return stoul(sn);         
      
}
//-------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Funkcijoje bandoma „padalinti“  pirmąjį (kairiausiąjį)  skaitmenį iš „d“ (parametras).
// Parametras „d“ turi  būti tarp 2 ir 9 (imtinai).
// Funkcija veikia analogiškai funkcijai „atimik1Gale(...)“
// Pvz. 1. Jeigu „n“ yra 85, o „d“  yra 2, tai funkcija grąžins 45.
// Pvz. 2. Jeigu „n“ yra 614567, o „d“ 3, tai funkcija grąžins 214567.
// Jeigu padalinti negalima, pvz. kai n=94565, o d=4,  tai funkcija  grąžina 0.
//-------------------------------------------------------------------------------

u64 dalinkPirmaSkaitmeniPriekyje(u64 n, u64 d){  
   if (n == 1) return 0;
   string sn = to_string(n);
   u64 pirmas = sn[0]-'0';
   if ((sn[0] > '1') && (pirmas % d == 0))
      sn[0] = pirmas/d+'0';
   else return 0; 
      
   return stoul(sn);       
}

//------------------------------------------------------------------------------
// Funkcijoje bandoma „padalinti“ dvižeknlį skaičių, sudarytą iš pirmųjų dviejų  
// (kairiausiųjų)  skaitmenų, iš „d“ (parametras).
// Parametras „d“ turi  būti tarp 2 ir 9 (imtinai).
// Funkcija veikia analogiškai funkcijai „dalinkPirmaSkaitmeniPriekyje(...)“
// Pvz. 1. Jeigu „n“ yra 4578, o „d“  yra 5, tai funkcija grąžins 978.
// Pvz. 2. Jeigu „n“ yra 2021, o „d“ 4, tai funkcija grąžins 521.
// Jeigu padalinti negalima, pvz. kai n=4565, o d=4,  tai funkcija  grąžina 0.
//-------------------------------------------------------------------------------

u64 dalinkPirmusDuSkaitmenisPriekyje(u64 n, u64 d){  
   string sn = to_string(n);
   if(sn.length()<2) return 0;
   u64 du = stoul(sn.substr(0,2));
   
   if ((du % d == 0) && ( du / d <10))
       sn = to_string(du/d)+sn.substr(2);
   else return 0; 
      
   return stoul(sn);  
      
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Funkcijoje bandoma „padalinti“  paskutinįjį (dešiniausiąjį)  skaitmenį iš „d“ (parametras).
// Parametras „d“ turi  būti tarp 2 ir 9 (imtinai).
// Funkcija veikia analogiškai funkcijai „dalinkPirmaSkaitmeniPriekyje(...)“
// Pvz. 1. Jeigu „n“ yra 856, o „d“  yra 3, tai funkcija grąžins 853.
// Pvz. 2. Jeigu „n“ yra 45679, o „d“ 3, tai funkcija grąžins 45673.
// Jeigu padalinti negalima, pvz. kai n=965, o d=4,  tai funkcija  grąžina 0.
//-------------------------------------------------------------------------------

u64 dalinkSkaitmeniGale(u64 n, u64 d){  
   
   u64 psk = n % 10;
   if ((psk % d) == 0) 
      return n / 10 * 10 + psk / d;
   else 
      return 0;

}
//-------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Funkcijoje bandoma „padalinti“ dvižeknlį skaičių, sudarytą iš paskutiniųjų dviejų  
// (dešiniausiųjų)  skaitmenų, iš „d“ (parametras).
// Parametras „d“ turi  būti tarp 2 ir 9 (imtinai).
// Funkcija veikia analogiškai funkcijai „dalinkPirmusDuSkaitmenisPriekyje(...)“
// Pvz. 1. Jeigu „n“ yra 4572, o „d“  yra 8, tai funkcija grąžins 459.
// Pvz. 2. Jeigu „n“ yra 2021, o „d“ 7, tai funkcija grąžins 203.
// Jeigu padalinti negalima, pvz. kai n=4565, o d=4,  tai funkcija  grąžina 0.
//-------------------------------------------------------------------------------


u64 dalinkDuSkaitmenisGale(u64 n, u64 d){  // jeigu gražins 0, tai negalima  
   
   u64 psk2 = n % 100;
   if(psk2 < 10) return 0;
   if (((psk2 % d) == 0) && ((psk2 / d) < 10)) 
      return n / 100 * 10 + psk2 / d;
   else 
      return 0;

}
//-------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Funkcija bando atnaujinti tiriamųjų skaičių eilę ir žodyną.
// ParametraI:
// vi - tiriamoji reikšmė; 
// val - reikšmė po  vieno „vi“ transformacijos žingsnio atgal;
// inc - transformacijos žingsnio  kaina (1 ar 2);
// target - reikšmė, kruią reikia pasiekti (šiuo atveju - „1“);
//------------------------------------------------------------------------------

void naujink(u64 val, u64 vi, u64 inc, u64 target){

 
     u64 nv = ats.at(vi) + inc;
     if (  ats.find(val) != ats.end() ){
        if (nv < ats.at(val)){ 
             ats[val] = nv;
             v.push_back(val);
        }}                
     else if (val >= target){   
        ats[val] = nv;
        v.push_back(val);
     }   

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//
// Pagrindinis algoritmas
//
//------------------------------------------------------------------------------

int main(){
   const int ATIMTIS = 1;                               // Vieneto pridėjimo  kaina
   const int DALYBA = 2;                                // daugybos iš skaitmens kaina
   
   int numTests;                                        // kiek skaičių reikės „transformuoti“?
   cin >> numTests;                                     
   
   u64 n;                                               // einamasis skaičius
   // Ciklas pagal testo  skaičius
   for(int t=1;t<=numTests;t++){ 
      v.clear();                                        // išvalome eilę   
      ats.clear();                                      //  ... ir žodyną  
      cin >> n;
      v.push_back(n);                                   // dedame nuskaityą skaičių į eilę
      ats[n] = 0;                                       // einamoji kaina <- 0 
      u64 target = 1;                                   // bandome tarnsformuoti iki 1
      u64 i = 0;                                        // pozicija eilėje   
      //
      // kol yra tiriamųjų skaičių   
      //
      while (v.size() > i){                             
      //  
      // bandome transformuoti atbulai ir atnaujinti eilę ir žodyną, jeigu reikia:
      //
        u64 val = atimik1Gale(v[i]);                    
        if (val != v[i])
           naujink(val, v[i], ATIMTIS, target);
        u64 valp = atimik1Priekyje(v[i]);
        if (valp != 0)
           naujink(valp, v[i], ATIMTIS, target);
     
        for(u64 d=2;d<10;d++){
           u64 vald1 = dalinkSkaitmeniGale(v[i], d);
           if (vald1 != 0)
              naujink(vald1, v[i], DALYBA, target);
           u64 vald2 = dalinkDuSkaitmenisGale(v[i], d);
           if (vald2 != 0)
              naujink(vald2, v[i], DALYBA, target);
           u64 vald3 = dalinkPirmaSkaitmeniPriekyje(v[i], d);
           if (vald3 != 0)
              naujink(vald3, v[i], DALYBA, target);
           u64 vald4 = dalinkPirmusDuSkaitmenisPriekyje(v[i], d);
           if (vald4 != 0)
              naujink(vald4, v[i], DALYBA, target);
              
        }
        // ---------------------------------------------------------------------------
        i++;                                            // kitas tiriamasis skaičius ...
      }
        
     if(ats.find(1) != ats.end())                       // jeigu  VIENETĄ išėjo pasiekti ...
         cout << ats[1] << endl;
     else                                               // jeigu ne ...
         cout << -1 << endl; 
  } // Ciklo pagal testo  skaičius pabaiga
  return 0;
}
