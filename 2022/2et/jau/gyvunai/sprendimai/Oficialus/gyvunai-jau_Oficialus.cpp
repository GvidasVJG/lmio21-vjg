#include <iostream>

// Laikas: valanda, minutės
typedef struct {
    int h, m;
} t_time;

// Du laiko momentai, kurie apibrėžia intervalą
typedef struct {
    t_time f, t;
} t_interval;

// Funkcija grąžina didenį laiką iš duotų
t_time max_time(t_time a, t_time b) {
    if (a.h > b.h || a.h == b.h && a.m > b.m)
        return a;
    else
        return b;
}

// Funkcija grąžina mažesnį laiką iš duotų
t_time min_time(t_time a, t_time b) {
    if (a.h < b.h || a.h == b.h && a.m < b.m)
        return a;
    else
        return b;
}

// Patikrinimas, ar intervalas nėra tuščias
bool is_empty(t_interval t) {
    return (t.f.h == 0) && (t.f.m == 0) && (t.t.h == 0) && (t.t.m == 0);
}

void print_interval(t_interval t) {
    std::cout << t.f.h << " " << t.f.m << " " << t.t.h << " " << t.t.m << std::endl;
}

// Apskaičiuojama dviejų intervalų sankirta
t_interval intersect(t_interval a, t_interval b) {
    t_interval r;
    r.f = max_time(a.f, b.f);
    r.t = min_time(a.t, b.t);

    if (r.f.h > r.t.h || r.f.h == r.t.h && r.f.m >= r.t.m) {
        // Intervalai nesikerta
        r.f.h = r.f.m = r.t.h = r.t.m = 0;
    }

    return r;
}

int main() {
    int n;
    std::cin >> n;

    // išsaugomas didžiausias rastas intervalas
    t_interval maxi;
    std::cin >> maxi.f.h >> maxi.f.m >> maxi.t.h >> maxi.t.m;

    for (int i = 1; i < n; i++) {
        t_interval a;
        std::cin >> a.f.h >> a.f.m >> a.t.h >> a.t.m;
        // Apskaičiuojame didžiasio anksčiau apskaičiuoto
        // ir naujai nuskaityto intervalo susikirtimą
        maxi = intersect(maxi, a);
    }

    if (is_empty(maxi)) {
        // Nėra bendro intervalo
        std::cout << "NE";
    }
    else {
        std::cout << "TAIP" << std::endl;
        print_interval(maxi);
    }

    return 0;
}