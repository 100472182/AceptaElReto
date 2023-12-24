#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

enum class Persona { Pedro, Pilar, Marco };

struct Apuestas {
  unsigned int numero;
  enum Persona persona;
};

int redondeo_superior(float numero) {
  if (numero == std::floor(numero)) {
    return numero + 1;
  } else {
    return std::ceil(numero);
  }
}

int redondeo_inferior(float numero) {
  if (numero == std::floor(numero)) {
    return numero - 1;
  } else {
    return std::floor(numero);
  }
}

void problema(std::vector<unsigned int> casoDePrueba) {

  if (casoDePrueba.size() != 3) {
    std::cout << "El tamaño del vector debe ser 3\n";
    return;
  }
  std::array<Apuestas, 3> apuestas;
  apuestas[0] = {casoDePrueba[0], Persona::Pilar};
  apuestas[1] = {casoDePrueba[1], Persona::Marco};
  apuestas[2] = {casoDePrueba[2], Persona::Pedro};
  int max = 0;
  int min = 64;
  float intermedio = 0;
  int llamadasPedro = 0;
  for (int i = 0; i < 3; i++) {
    if (casoDePrueba[i] > max) {
      max = casoDePrueba[i];
    }
    if (casoDePrueba[i] < min) {
      min = casoDePrueba[i];
    }
  }
  // Clasificamos según la apuesta de Pedro
  if (apuestas[2].numero == max) {
    // z_i es la mayor apuesta
    if (apuestas[1].numero == min) {
      intermedio = (apuestas[2].numero + apuestas[1].numero) / 2.0;
    } else {
      intermedio = (apuestas[2].numero + apuestas[0].numero) / 2.0;
    }
    // Formula
    llamadasPedro = redondeo_superior(3 * intermedio);

  } else if (apuestas[2].numero == min) {
    // z_i es la menor apuesta
    if (apuestas[1].numero == min) {
      intermedio = (apuestas[2].numero + apuestas[1].numero) / 2.0;

    } else {
      intermedio = (apuestas[2].numero + apuestas[0].numero) / 2.0;
    }
    // Formula
    llamadasPedro = redondeo_inferior(3 * intermedio - 2 * 64);
    if (llamadasPedro < 0) {
      std::cout << "I\n";
      return;
    }
  } else {
    // z_i es la apuesta intermedia
    std::cout << "0\n";
    return;
  }
  std::cout << llamadasPedro << "\n";
}

int main() {
  std::vector<std::vector<unsigned int>> casosDePrueba;
  bool fin = false;
  while (!fin) {
    std::vector<unsigned int> casoDePrueba;
    for (int i = 0; i < 3; i++) {
      int numero;
      std::cin >> numero;
      if (numero < 0) {
        fin = true;
        break;
      }
      std::cout << numero << " ";
      casoDePrueba.push_back(numero);
    }
    if (fin) {
      break;
    }
    casosDePrueba.push_back(casoDePrueba);
  }
  for (auto casoDePrueba : casosDePrueba) {
    problema(casoDePrueba);
  }
}
