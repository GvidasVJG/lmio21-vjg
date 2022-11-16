#include <iostream>

using namespace std;

int skirtumas(int h_pab, int min_pab, int h_pr, int min_pr) {
    return (h_pr * 60 + min_pr) - (h_pab * 60 + min_pab);
}

int main()
{
    int n, skait_min = 0, h_ankst = 6, min_ankst = 30;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h_pr, min_pr, h_pab, min_pab;
        cin >> h_pr >> min_pr >> h_pab >> min_pab;
        skait_min += skirtumas(h_ankst, min_ankst, h_pr, min_pr);
        h_ankst = h_pab;
        min_ankst = min_pab;
    }
    skait_min += skirtumas(h_ankst, min_ankst, 22, 30);

    cout << skait_min;
    
    return 0;
}