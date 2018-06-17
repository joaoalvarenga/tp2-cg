/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#ifndef TP2_CG_UTILS_HPP
#define TP2_CG_UTILS_HPP


#include <cmath>

float distance2d(int x0, int y0, int x1, int y1) {
    return sqrt(pow(x0-x1,2) + pow(y0-y1, 2));
}



#endif //TP2_CG_UTILS_HPP
