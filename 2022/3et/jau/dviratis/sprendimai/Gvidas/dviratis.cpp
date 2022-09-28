#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    bool ryte_nelyja[N]; 
    bool vakare_nelyja[N];

    bool namie = true;
    bool darbe = false;
    
    int kiek = 0;
    bool vaziavo = false;

    for(int i = 0; i < N; ++i){        
        int r, v;
        cin >> r >> v;

        ryte_nelyja[i] = r == 1 ? true : false;
        vakare_nelyja[i] = v == 1 ? true : false;
    }

    for(int i = 0; i < N - 1; ++i){

        bool a = ryte_nelyja[i], b = vakare_nelyja[i], c = ryte_nelyja[i+1], d = vakare_nelyja[i+1];
        if(a && namie && (!b&&!c&&!d || !b&&!c&&d || !b&&c&&!d || !b&&c&&d || b&&!c&&d)){
            kiek++;
            namie = false;
        } else if(b&&(!a&&!c&&!d&&!namie || !a&&!c&&d&&!namie || !a&&c&&!d&&!namie || !a&&c&&d&&!namie || a&&!c&&!d&&namie || a&&c&&!d&&!namie || a&&c&&!d&&namie || a&&c&&d&&!namie || a&&c&&d&&namie)){
            kiek++;
            namie = true;
        }
    }
    cout << kiek;

}