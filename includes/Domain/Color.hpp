/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#ifndef TP2_CG_COLOR_HPP
#define TP2_CG_COLOR_HPP

#include <tuple>

class Color {
public:

    Color(int r, int g, int b, double a);
    Color(int r, int g, int b) : Color(r, g, b, 1) { };

    int getR();
    int getG();
    int getB();
    float getAlpha();

private:
    std::tuple<int, int, int, int> color;
};

#endif //TP2_CG_COLOR_HPP
