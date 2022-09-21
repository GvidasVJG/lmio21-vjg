#include <iostream>

using namespace std;

int main()
{
    int valandos, robotai, laik_sum = 0, sum = 0, a;
    cin >> valandos >> robotai;
    int robo[robotai];

    for (int i = 0; i < robotai; i++){
        cin >> a;
        robo[i] = a;
    }

    for (int i = 1; i <= valandos; i++){
        laik_sum = 0;
        for (int j = 0; j < robotai; j++){
            if (i % robo[j] == 0){
                laik_sum++;
            }
        }
        if (laik_sum == robotai){
            sum++;
        }
    }
    cout << sum;
}