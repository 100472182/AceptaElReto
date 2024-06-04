#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int cantidad;
    while (std::cin >> cantidad) {
        if (cantidad == 0) {
            return 0;
        }
        int actual;
        int prev = 0;
        for (; cantidad > 0; --cantidad) {
            std::cin >> actual;
            if (actual <= prev) {
                std::cout << "NO" << std::endl;
                std::cin.ignore(800, '\n');
                break;
            }
            prev = actual;
        }

        if (cantidad == 0) {
            std::cout << "SI" << std::endl;
        }
    }
}