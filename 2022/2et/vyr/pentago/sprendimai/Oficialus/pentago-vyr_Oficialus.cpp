#include <iostream>

// Žaidimo lenta
int gb[6][6];

// Galimų sukti kvadratų pradžios koordinatės
int square[4][2] = {{0, 0}, {0, 3}, {3, 0}, {3, 3}};

// galimų burbuliukų eilučių krytys
int dir[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };

/*
* Tikriname, ar yra 5 balti burbuliukai iš eilės
*/
bool has_5_in_row() {
    for (int r = 0; r < 6; r++)
        for (int c = 0; c < 6; c++)
            if (gb[r][c] == 1)
                for (int d = 0; d < 4; d++) {
                    bool wins = true;
                    for (int z = 1; (z < 5) && wins; z++) {
                        int r1 = r + dir[d][0] * z, c1 = c + dir[d][1] * z;
                        wins = r1 >= 0 && r1 < 6 && c1 >= 0 && c1 < 6 && gb[r1][c1] == 1;
                    }
                    // Radome penkių burbuliukų eilę
                    if (wins) return true;
                }
    return false;
}

/*
* Procedūra pasuka nurodytą kvadratą 90 laipsnių kampu
*/
void rotate90(int sq) {
    // Išsaugomos esamos sukamo kvadrato reikšmės
    int orig[3][3];
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            orig[r][c] = gb[square[sq][0] + r][square[sq][1] + c];

    // Kvadratas sukamas 90 laipsnių kampu
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            gb[square[sq][0] + r][square[sq][1] + c] = orig[c][2 - r];
}

int main() {
    for (int r = 0; r < 6; r++)
        for (int c = 0; c < 6; c++)
            std::cin >> gb[r][c];

    // Bandome sukti visus kvadratus
    for (int sq = 0; sq < 4; sq++) {
        // Bandome sukti 90 laipsnių kampu
        rotate90(sq);
        if (has_5_in_row()) {
            // Atlikus šį pasukimą baltieji laimi
            std::cout << "LAIMI" << std::endl << sq + 1 << " 90";
            return 0;
        }
        else {
            // bandome sukti 270 laipsnių kampu
            rotate90(sq);
            rotate90(sq);
            if (has_5_in_row()) {
                // Atlikus šį pasukimą baltieji laimi
                std::cout << "LAIMI" << std::endl << sq + 1 << " 270";
                return 0;
            }
            else {
                // Atstatome pradinę lentos būseną dar kartą pasukdami
                rotate90(sq);
            }
        }
    }
    std::cout << "NELAIMI";

    return 0;
}
