#include <iostream>
#include <algorithm>

int main(){
    int m;
    std::cin >> m;
    int t[m], v[m], z1[m], z2[m];
    for(int i = 0; i < m; ++i){
        std::cin >> t[i] >> v[i] >> z1[i] >> z2[i];
    }

    int id = 0;
    int k1_profit = 0, k2_profit = 0;
    bool k1_free = true, k2_free = true;
    int k1_oncall = 0, k2_oncall = 0;
    for(int time = 0; true; ++time){
        
        k1_oncall = k1_oncall > 0 ? k1_oncall - 1 : 0;
        k2_oncall = k2_oncall > 0 ? k2_oncall - 1 : 0;
        k1_free = k1_oncall == 0 ? true : false;
        k2_free = k2_oncall == 0 ? true : false;

        if(time != t[id]){
            continue;
        }

        if(k1_free && k2_free){
            if(z1[id] < z2[id]){
                k1_free = false;
                k1_oncall = z1[id];
                k1_profit += v[id];
            }
            else{
                k2_free = false;
                k2_oncall = z2[id];
                k2_profit += v[id];
            }
        }
        else if(k1_free && !k2_free){
            k1_free = false;
            k1_oncall = z1[id];
            k1_profit += v[id];
        }
        else if(!k1_free && k2_free){
            k2_free = false;
            k2_oncall = z2[id];
            k2_profit += v[id];
        }

        ++id;
        if(id == m)
            break;
    }
    std::cout << k1_profit << " " << k2_profit;
}