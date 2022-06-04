#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int k1[2] = {0, 0}; // 1 indexas - statusas, 2 indexas - uzdarbis
    int k2[2] = {0, 0}; // 1 indexas - statusas, 2 indexas - uzdarbis
    int ltemp = 0;
    int k2temp = 0;
    int k1temp = 0;
    int l = 0;
    cin >> l;
    int s[l][4] = {};
    for (int x=0;x<l;x++) {
        for (int y=0;y<4;y++) {
            int i = 0;
            cin >> i;
            s[x][y] = i;
        }
    }
    for (int n=0;n<l;n++) {
            if (k1[0] > 0) {
                k1[0]-=1;
            }
            else if (k2[0] > 0) {
                k2[0]-=1;
            }
            else {
                continue;
            }
            if (k1temp + ltemp > s[n][0]) {
                k2[0] += s[n][3];
                k2[1] += s[n][1];
                k2temp = s[n][3];
            }
            else if (k2temp + ltemp > s[n][0]) {
                k1[0] += s[n][2];
                k1[1] += s[n][1];
                k1temp = s[n][2];
            }
            if (s[n][2] > s[n][3]) {
                k2[0] += s[n][3];
                k2[1] += s[n][1];
                k2temp = s[n][3];
            }
            else if (s[n][2] < s[n][3]) {       //buvo: else; pakeista, kad kompiliuotusi: else if
                k1[0] += s[n][2];
                k1[1] += s[n][1];
                k1temp = s[n][2];
            }
        }
    std::cout << k1[1] << " " << k2 [1];

}

