#include <Domain/Color.hpp>

/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

Color::Color(int r, int g, int b, double a) {
    this->color = std::make_tuple(r, g, b, 1);
}

int Color::getR() {
    return std::get<0>(this->color);
}

int Color::getG() {
    return std::get<1>(this->color);
}

int Color::getB() {
    return std::get<2>(this->color);
}

float Color::getAlpha() {
    return std::get<3>(this->color);
}