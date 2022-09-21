#include <iostream>

using namespace std;

int main()
{
    int sum_dienu, sum = 0;
    //cout << "kiek dienu?: ";
    cin >> sum_dienu;

    struct prognoze{
    bool rytas;
    bool vakaras;
    };

    prognoze prog[sum_dienu];

    for (int i = 0; i < sum_dienu; i++){

        /*cout << "rytas: ";*/ cin >> prog[i].rytas;
        /*cout << "vakaras: ";*/ cin >> prog[i].vakaras;
    }
        bool ar_namie = false;
        bool ar_darbe = false;

    for (int i = 0; i < sum_dienu; i++){

        if (prog[i].rytas == true && prog[i].vakaras == true){
            sum++;
            if(prog[i + 1].vakaras == true){
                ar_namie = false;
                ar_darbe = true;
            }
            else if(prog[i + 1].rytas == true){
                ar_namie = true;
                ar_darbe = false;
            }
        }
        else if (prog[i].rytas == true){
            if (ar_namie == true){
                sum++;
                ar_namie = false;
                ar_darbe = true;
            }
        }
        else if (prog[i].vakaras == true){
            if (ar_darbe == true){
                sum++;
                ar_darbe = false;
                ar_namie = true;
            }
        }
    }
    cout << sum;
}