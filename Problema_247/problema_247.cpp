#include <iostream>

int main() {
    int cantidad;
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    while (std::cin >> cantidad) {
        bool fallo = false;
        int actual = 0;
        int prev = 0;
        if (cantidad == 0) {
            return 0;
        }
        while (!fallo && cantidad > 0) {
            std::cin >> actual;
            if (actual <= prev) {
                std::cout << "NO" << std::endl;
                fallo = true;
                std::cin.ignore(1000, '\n');
            }
            prev = actual;
            cantidad--;
        }
        if (!fallo) {
            std::cout << "SI" << std::endl;
        }
    }
}