#include <stdio.h>
#include <string.h>

// Naudojami simboliai: simbolio indeksas šiame 
// masyve atitinka numerį sąlygoje.
// Žvaigždutė nenaudojama (jos indeksas yra 0). 
const char* abecele = "*ABCDEFGHIJKLMNOPQRSTUVWXYZ_,."; 

// Funkcija grąžina simbolio numerį pagal sąlygą („kodą“)
int simbolioKodas(char c){
   if(c >= 'A' && c <= 'Z') return c - 'A' + 1;
   switch(c){
      case '_' : return 27;
      case ',' : return 28;
      case '.' : return 29;
      default: return 0; 
   }
}


int main(){
   // įvesties eilutė (įskaitnat simbolį '\0'):
   char eilute[81] = "";                  
   // dešifravimo abėcėlė: ją pildome pradžioje „nuliais“
   char desifravimoAbecele[30] = "*"; 

   // esminis sprendimo žingsnis: kadangi kiekvienam simboliui 
   // atitinka vienintelis „sšfruotas“ simbolis toje pačioje 
   // abėcėlėje, tai nesunku įžvelgti atvirkštinį atitikimą:
   // kiekvienam šifruotam simboliui, kurio numeris yra 
   // „i * i * i % 29 + 1“  atitinka nešifruotas simbolis 
   // su numeriu „i“
   for (int i=1;i<30;i++)
      desifravimoAbecele[i * i * i % 29 + 1] = abecele[ i ];  

   // skaitome šifruotą teksto eilutę:
   scanf("%80s",eilute);

   // ciklas pagal visus šifruotos eilutės simbolius:
   char* p = eilute;
   while (*p){
      int rastas = simbolioKodas(*p);      // šifruoto simbolio kodas
      if (rastas) 
        *p = desifravimoAbecele[rastas];   // dešifruoto simbolio kodas
      p++;                                 // ... kitas simbolis
   }
   
   // rašome dešifruotą teksto eilutę:
   printf("%s\n",eilute);

   return 0;


}
