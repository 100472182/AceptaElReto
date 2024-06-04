#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n_casos;
    std::cin >> n_casos;
    while (n_casos--) {
        int uvas, personas;
        std::cin >> uvas >> personas;
        if (uvas / 12 < personas)
            std::cout << "NO\n";
        else
            std::cout << "SI\n";
    }
}