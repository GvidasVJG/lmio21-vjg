#include <iostream>

using namespace std;

int main()
{
    int dienusk, sum = 0;
    bool arnamie = true;

    cin >> dienusk;

    struct prog{
    bool rytop;
    bool vakarop;
    };
    prog prognoze[dienusk];

    for (int i = 0; i < dienusk; i++){
        cin >> prognoze[i].rytop >> prognoze[i].vakarop;
    }

    for (int i = 0; i < dienusk; i++){
        if (prognoze[i].rytop == true && prognoze[i].vakarop == true){
            if(arnamie){
                sum++;
            }
            if (prognoze[i + 1].rytop == false && prognoze[i + 1].vakarop == true){
                arnamie = false;
            }
            if (prognoze[i + 1].rytop == true && prognoze[i + 1].vakarop == false){
                arnamie = true;
            }
            if (prognoze[i + 1].rytop == true && prognoze[i + 1].vakarop == true){
                arnamie = true;
            }
            if (prognoze[i + 1].rytop == false && prognoze[i + 1].vakarop == false){
                int j = 1;
                while (j <= dienusk - i){
                    if (prognoze[i + j].rytop == false && prognoze[i + j].vakarop == true){
                        arnamie = false;
                        break;
                    }
                    if (prognoze[i + j].rytop == true && prognoze[i + j].vakarop == false){
                        arnamie = true;
                        break;
                    }
                    if (prognoze[i + j].rytop == true && prognoze[i + j].vakarop == true){
                        arnamie = true;
                        break;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        else if (prognoze[i].rytop == true && prognoze[i].vakarop == false){
            if (arnamie == true){
                arnamie = false;
                sum++;
            }
        }
        else if (prognoze[i].rytop == false && prognoze[i].vakarop == true){
            if (arnamie == false){
                arnamie = true;
                sum++;
            }
        }
    }
    cout << sum;
}