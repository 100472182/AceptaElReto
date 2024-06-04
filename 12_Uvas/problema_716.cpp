#include <iostream>

int main() {
    /* std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); */
    int regletas;
    int enchufes;
    int total;
    while (std::cin >> regletas) {
        total = 0;
        if (regletas == 0)
            return 0;
        while (true) {
            std::cin >> enchufes;
            total += enchufes;
            regletas--;
            if (regletas == 0) {
                std::cout << total << "\n";
                break;
            }
            total--;
        }
    }
}