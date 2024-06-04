#include <array>
#include <iostream>
// CREO QUE SE IMPLEMENTA CON UN A*, ASI QUE NO LO VOY A HACER
int main() {
    int cubos;
    std::array<int, 1000> comidas;
    int head;
    int tail;
    int ind_selecc;
    while (std::cin >> cubos) {
        if (cubos == 0) {
            return 0;
        }
        head = 0;
        tail = cubos - 1;
        for (int i = 0; i < cubos; i++) {
            std::cin >> comidas[i];
        }
        for (int turno = 0; turno < cubos; turno++) {
            if (comidas[head] >= comidas[tail]) {
                ind_selecc = head;
                head += 1;
            } else if (comidas[head] < comidas[tail]) {
                ind_selecc = tail;
                tail -= 1;
            }
        }

        comidas.fill(0);
    }
}