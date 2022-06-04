#include <bits/stdc++.h>

using namespace std;

struct Platform {
    long long x_left, x_right, y_left, y_right;

    int platform_on_left, platform_on_right;
};

vector<Platform> platforms;
map<int, int> platform_on_top;

// Palygina, ar viena platforma yra žemiau už kitą. Platformos privalo persidengti, t.y. viena turi būti tiesiai virš
// kitos bent viename taške.
struct PlatformComparator {
    bool operator()(int a_index, int b_index) const {
        if (a_index == b_index) {
            return false;
        }
        const Platform &a = platforms[a_index];
        const Platform &b = platforms[b_index];
        // Randame bendrą x koordinatę, kurioje palyginsime platformų aukščius.
        long long coordinate = max(a.x_left, b.x_left);
        if (coordinate > a.x_right || coordinate > b.x_right) {
            exit(1);
        }
        // Koordinatėje x=coordinate, platformos a y koordinatė yra lygi a_numerator/a_denominator, o platformos b y
        // koordinatė lygi b_numerator/b_denominator.
        long long a_numerator =
                (long long) a.y_right * (coordinate - a.x_left) + (long long) a.y_left * (a.x_right - coordinate);
        long long a_denominator = a.x_right - a.x_left;
        long long b_numerator =
                (long long) b.y_right * (coordinate - b.x_left) + (long long) b.y_left * (b.x_right - coordinate);
        long long b_denominator = b.x_right - b.x_left;
        long long cmp = a_numerator * b_denominator - b_numerator * a_denominator;
        if (cmp == 0) {
            exit(2);
        }
        return cmp < 0;
    }
};

// Kiekvienai platformai randa, ant kurios platformos nukrenta kamuoliukas, jei nukrenta nuo jos kairio galo ir jei
// nukrenta nuo jos dešinio galo.
// Svarbu pastebėti, kad šie ryšiai tarp platformų nesikeičia dėl veiksmų vykdymo.
void FindDrops() {
    int n = platforms.size();

    // Einame per visą lentą iš kairės į dešinę. Vienu metu nagrinėjame platformas, kurios yra tam tikroje x
    // koordinatėje.

    // Platformų operacijos, einant iš kairės į dešinę: kokioje x koordinatėje turime pridėti platformą ir kokioje ją
    // išimti.
    vector<pair<int, int>> platform_additions;
    for (int i = 0; i < n; ++i) {
        platform_additions.push_back({platforms[i].x_left, i});
        platform_additions.push_back({platforms[i].x_right, n + i});
    }
    sort(platform_additions.begin(), platform_additions.end());

    // Dabartinėje x koordinatėje esančios platformos. Laikomos std::set, kad galėtume pažiūrėti, kuri platforma
    // viršutinė ir konkrečiai platformai kuri platforma yra tiesiai po ja.
    set<int, PlatformComparator> current_platforms;

    for (auto operation : platform_additions) {
        int platform_index = operation.second;
        bool remove = (platform_index >= n);
        if (remove) {
            platform_index -= n;
        }

        if (!remove)current_platforms.insert(platform_index);

        // Randame, kuri platforma šiuo metu yra tiesiai po dabar pridedama/išimama, nes and jos kris kamuoliukas nuo
        // dabar nagrinėjamo platformos galo.
        int falls_on = -1;
        auto iter = current_platforms.find(platform_index);
        if (iter != current_platforms.begin()) {
            iter--;
            falls_on = *iter;
        }

        if (remove) {
            platforms[platform_index].platform_on_right = falls_on;
            current_platforms.erase(platform_index);
        } else {
            platforms[platform_index].platform_on_left = falls_on;
        }

        // Pasižymime, kuri platforma dabar yra viršutinė, kad paskui rastume, kuri platforma bus pirmoji, ant kurios
        // nukris kamuoliukas.
        iter = current_platforms.end();
        if (iter != current_platforms.begin()) {
            iter--;
            platform_on_top[operation.first] = *iter;
        }
    }
}

// Duotai platformai randa, ant kurios platformos nuo jos nukris kamuoliukas. Suspaudžia kelius, einančius per nekintančias
// platformas, t.y. jei kelias 1-->2-->3-->4-->5, o vienintelė kintanti platforma yra 4, tai drops_to[1] bus lygu 4.
void GetDropsTo(int platform_index, vector<int> &drops_to, const vector<bool> &changing_platforms) {
    if (drops_to[platform_index] != -2) {
        return;
    }
    const Platform &platform = platforms[platform_index];
    int next = platform.y_left < platform.y_right ? platform.platform_on_left : platform.platform_on_right;
    if (next == -1) {
        drops_to[platform_index] = -1;
        return;
    }
    if (!changing_platforms[next]) {
        GetDropsTo(next, drops_to, changing_platforms);
        if (drops_to[next] != -1) {
            next = drops_to[next];
        }
    }
    drops_to[platform_index] = next;
}

// Įvykdo duotą dalį atliekamų veiksmų. Jei pateikiami K veiksmų, tai sudėtingumas O(N+K^2).
void ProcessBatch(const vector<pair<int, int>> &moves) {
    // Pirma surandame, kurios platformos bus judinamos atliekant šiuos veiksmus.
    vector<bool> changing_platforms(platforms.size(), false);
    for (auto move : moves) {
        if (move.first != 0) {
            changing_platforms[abs(move.first) - 1] = true;
        }
    }
    // Randame, ant kurios platformos nukris kamuoliukas nuo bet kurios duotos platformos, suspausdami kelius, einančius
    // per nekintamas viršūnes.
    vector<int> drops_to(platforms.size(), -2);
    for (int i = 0; i < platforms.size(); ++i) {
        GetDropsTo(i, drops_to, changing_platforms);
    }

    for (auto move : moves) {
        if (move.first != 0) {
            int index = abs(move.first) - 1;
            Platform &platform = platforms[index];
            if (move.first > 0) {
                platform.y_right = move.second;
            } else {
                platform.y_left = move.second;
            }
            drops_to[index] =
                    platform.y_left < platform.y_right ? platform.platform_on_left : platform.platform_on_right;
        } else {
            long long coord = move.second;

            // Randame pirmą platformą, ant kurios užkris kamuoliukas.
            int platform_index = -1;
            auto iter = platform_on_top.upper_bound(coord);
            if (iter != platform_on_top.begin()) {
                --iter;
                if (platforms[iter->second].x_right >= coord) {
                    platform_index = iter->second;
                }
            }

            if (platform_index == -1) {
                cout << coord << "\n";
            } else {
                while (drops_to[platform_index] != -1) {
                    platform_index = drops_to[platform_index];
                }
                const Platform &platform = platforms[platform_index];
                long long answer = platform.y_left < platform.y_right ? platform.x_left : platform.x_right;
                cout << answer << "\n";
            }
        }
    }
}

int main() {

    int n, k;
    cin >> n >> k;


    for (int i = 0; i < n; ++i) {
        Platform platform;
        cin >> platform.x_left >> platform.y_left >> platform.x_right >> platform.y_right;
        platforms.push_back(platform);
    }

    FindDrops();
    vector<pair<int, int>> moves;

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        moves.push_back({a, b});
    }
    int batch_size = sqrt(moves.size());
    int move_index = 0;
    while (move_index < moves.size()) {
        vector<pair<int, int>> current_batch;
        while (move_index < moves.size() && current_batch.size() < batch_size) {
            current_batch.push_back(moves[move_index++]);
        }
        ProcessBatch(current_batch);
    }
    return 0;
}