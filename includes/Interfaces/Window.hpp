/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/



#ifndef TP2_CG_WINDOW_HPP
#define TP2_CG_WINDOW_HPP

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux
#include <GL/glut.h>
#endif

class Window {

public:
    virtual void display(int argc, char** argv) = 0;
};

#endif //TP2_CG_WINDOW_HPP
