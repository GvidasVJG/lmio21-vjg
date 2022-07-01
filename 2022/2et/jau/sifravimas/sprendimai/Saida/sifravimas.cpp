#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

int main()
{
    int h;
    string ciph;
    cin >> ciph;
    string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.";

    for (int i = 0; ciph[i] != '\0'; i++){
        if (isalpha(ciph[i])){
            ciph[i] = (int)ciph[i] - 64;
        }
        else if ((int)ciph[i] == 95){
            ciph[i] = (int)ciph[i] - 68;
        }
        else if ((int)ciph[i] == 44){
            ciph[i] = (int)ciph[i] - 16;
        }
        else if ((int)ciph[i] == 46){
            ciph[i] = (int)ciph[i] - 17;
        }
        char cha = ciph[i];
        int intc = (int)cha;
        for (int j = 0; j < 29; j++){
            if (j * j * j % 29 + 1 == intc){
                if (j == 0){
                    cout << alph[28];
                }
                else{
                    cout << alph[j - 1];
                }
            }
        }
    }
}