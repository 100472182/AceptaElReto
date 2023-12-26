#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

struct Coche {
    int tiempo;
    int vel;
};

int constexpr inf = __INT_MAX__;

void problema(int objetivo, std::vector<Coche> coches) {
    int tiempo_minimo = inf;
    for (int i = 0; i < coches.size(); ++i) {
        if (coches[i].tiempo >= 0) {
            tiempo_minimo =
                std::min(tiempo_minimo, (objetivo / coches[i].vel) + coches[i].tiempo);
        }
    }
    std::cout << tiempo_minimo << std::endl;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    std::vector<Coche> coches;
    int objetivo;
    while (std::cin >> objetivo) {
        int num_coches;
        std::cin >> num_coches;
        coches.resize(num_coches);
        for (int i = 0; i < num_coches; ++i) {
            int t, v;
            std::cin >> t >> v;
            coches[i] = {t, v};
        }
        problema(objetivo, coches);
        coches.clear();
    }
    return 0;
}