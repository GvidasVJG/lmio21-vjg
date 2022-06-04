#include <iostream>
#include <string>
#include <map>
#include <cmath>

int main(){
    std::string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.";
    std::map <char, char> dict;
    for(int i = 0; i < abc.length(); ++i){
        char from = abc[i], to;
        int index = i+1;
        index = int(std::pow(index, 3))%29;
        dict.insert({abc[index], abc[i]});
    }

    std::string e;
    std::cin >> e;
    for(int l = 0; l < e.length(); ++l){
        std::cout << dict[e[l]];
    }
    std::cout << std::endl;
}
