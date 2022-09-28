#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int valandos, robotai, robotas, lcm;
    cin >> valandos >> robotai;
    vector<int> vektorius;
    bool vienoda = false;

    for (int i = 0; i < robotai; i++){
        cin >> robotas;
        for (int j = 0; j < vektorius.size(); j++){
            if (robotas == vektorius[i]){
                vienoda = true;
            }
        }
        if (vienoda == false){
            vektorius.push_back(robotas);
        }
    }

    lcm = vektorius[0];
    bool bruh = false;
    for (int i = 1; i < vektorius.size(); i++){
        int laikinas = lcm;
        while (bruh == false){
            if (lcm % laikinas == 0 && lcm % vektorius[i] == 0){
            break;
            }
            else{
            lcm++;
            }
        }
    }
    cout << valandos / lcm;
}