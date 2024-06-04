#include <array>
#include <iostream>
#include <vector>

constexpr int CANTIDAD_PASOS = 10;

int main() {
    int n_escalones;
    while (true) {
        std::cin >> n_escalones;
        if (n_escalones == 0) {
            return 0;
        }
        int n_pasos;
        std::cin >> n_pasos;
        std::vector<int> pasos(n_pasos);
        for (int i = 0; i < n_pasos; i++) {
            std::cin >> pasos[i];
        }
        std::array<int, 100> escalones;
        escalones.fill(0);

        for (int i = 0; i < n_escalones; i++) {
            for (size_t j = 0; j < CANTIDAD_PASOS; j++) {
                int cantidad = escalones[i + j] + 1;
                if (cantidad < n_escalones) {
                    escalones[i + j] = cantidad;
                }
            }
        }
        for (int i = 0; i < n_escalones; i++)
            std::cout << escalones[i] << "\n";
        std::cout << escalones[n_escalones - 1] << "\n";
    }
}