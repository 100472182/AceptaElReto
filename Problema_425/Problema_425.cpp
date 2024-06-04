#include <array>
#include <iostream>
#include <string>

int calculo_matriz(std::array<std::array<int, 101>, 101> &matriz, int ind_ant,
                   int ind_post, std::string &palabra) {
    if (matriz[ind_ant][ind_post] == -1) {
        if (ind_ant >= ind_post) {
            matriz[ind_ant][ind_post] = 0;
            return 0;
        } else if (palabra[ind_ant] == palabra[ind_post]) {
            matriz[ind_ant][ind_post] =
                calculo_matriz(matriz, ind_ant + 1, ind_post - 1, palabra);
            return matriz[ind_ant][ind_post];
        } else {
            matriz[ind_ant][ind_post] =
                std::min(calculo_matriz(matriz, ind_ant + 1, ind_post, palabra),
                         calculo_matriz(matriz, ind_ant, ind_post - 1, palabra)) +
                1;
            return matriz[ind_ant][ind_post];
        }
    }
    return matriz[ind_ant][ind_post];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string linea;
    while (std::cin >> linea) {
        std::array<std::array<int, 101>, 101> matriz;
        for (int i = 0; i < 101; ++i) {
            matriz[i].fill(-1);
        }
        int ind_ant = 0;
        int ind_post = linea.size() - 1;
        std::cout << calculo_matriz(matriz, ind_ant, ind_post, linea) << std::endl;
    }
}