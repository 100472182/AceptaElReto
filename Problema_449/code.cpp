#include <iostream>
#include <string>
#include <array>
#include <algorithm>
std::string palabra;

int dinamica(std::array<std::array<int, 81>, 81> matriz, int start, int end) {
    // Debería de comprobar cuántas letras iguales hay

    while (palabra[start] == palabra[start + 1]) {
        start = start + 1;
    }

    while (palabra[end] == palabra[end - 1]) {
        end = end - 1;
    } 
    //std::cout << "El valor de start es:"<< start << "\n";
    //std::cout << "El valor de end es:" << end << "\n";

    if (matriz[start][end] == -1) {
        // Caso base
        if (start >= end) {
            matriz[start][end] = 0;
            //std::cout << "El valor es 0 \n";
            return 0;
        }
        // Caso de que ambas letras sean iguales
        else if (palabra[start] == palabra[end]) {
            matriz[start][end] = dinamica(matriz, start + 1, end - 1) + 1;
            //std::cout << "El número de pasos que llevo es:" << matriz[start][end] << "\n";
            return matriz[start][end];
        }
        // Caso en que las letras son distintas
        else {
            matriz[start][end] = std::min(dinamica(matriz, start + 1, end), dinamica(matriz, start, end - 1)) + 1;
            //std::cout << "El número de pasos minimo que eligo es:" << matriz[start][end] << "\n";
            return matriz[start][end];
        }
    }
    // Si el valor ya ha sido tratado se devuelve
    //std::cout << "El valor a imprimir es" << matriz[start][end] << "\n";
    return matriz[start][end];
}
int iteraciones(std::array<std::array<int, 81>, 81> matriz, int start, int end) {
    for (int colStart = 0; colStart <= end; ++colStart) {

        for (int row = 0, col = colStart; col <= end; ++row, ++col) {
            // Procesa matriz[row][col]
            //std::cout << "El valor de row es:" << row << "\n";
            //std::cout << "El valor de col es:" << col << "\n";

            if (matriz[row][col] == -1) {
                if (row >= col) {
                    //std::cout << "El valor de " << row << "," << col << " es: 0 \n";
                    matriz[row][col] = 0;
                }
                else if (palabra[row] == palabra[col]) {
                    matriz[row][col] = matriz[row + 1][col - 1] + 1;
                    //std::cout << "El valor de " << row << "," << col << " es: "<< matriz[row][col] << "\n";

                }
                else {
                    matriz[row][col] = std::min(matriz[row + 1][col], matriz[row][col - 1]) + 1;
                    //std::cout << "El valor de " << row << "," << col << " es: "<< matriz[row][col] << "\n";

                }
            }
            if (row == start && col == end) {
                //std::cout << "Devuelve el valor:" << matriz[start][end] << "\n";
                return matriz[start][end];
            }
        }
        
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int start, end;
    while (std::cin >> palabra) {
        palabra.erase(std::unique(palabra.begin(), palabra.end()), palabra.end());
        std::array<std::array<int, 81>, 81> matriz;
        for (int i = 0; i < 81; ++i) {
            matriz[i].fill(-1);
        }
        start = 0;
        end = palabra.size() - 1;
        std::cout << iteraciones(matriz, start, end) + 1 << "\n";
    }

}