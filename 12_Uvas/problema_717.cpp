/* #include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n_casos;
    std::cin >> n_casos;
    std::unordered_map<int, int> fechas;
    int valor;
    bool insulsos = false;
    while (n_casos--) {
        for (int i = 0; i < 3; i++) {
            std::cin >> valor;
            fechas[valor / 10]++;
            fechas[valor % 10]++;
        }
        insulsos = false;
        for (const auto &par : fechas) {
            if (par.second % 2 != 0) {
                std::cout << "INSULSOS\n";
                insulsos = true;
                break;
            }
        }
        if (!insulsos)
            std::cout << "DIVERTIDOS\n";
        fechas.clear();
    }
} */

// La idea es mirar si el primer dígito del dia está en el segundo dígito del mes o año si
// está hay que mirar si el segundo dígito del dia está en el primer dígito del mes o año

// Por ejemplo 87 38 83, cogemos el 8 del día y miramos si está en el mes o año como
// segundo dígito, como está cogemos el segundo dígito del día y miramos si está en el año
// como primer dígito, en el mes no hay que mirar porque ya estará asignado a la segunda
// posición, como si está