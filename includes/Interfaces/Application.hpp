/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#ifndef TP2_CG_APPLICATION_HPP
#define TP2_CG_APPLICATION_HPP

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux
#include <GL/glut.h>
#endif


class Application {
public:
    virtual void draw() = 0;
    virtual void mouseCallback(int, int, int, int) = 0;
    virtual void menuCallback(int) = 0;
    virtual void mouseMoveCallback(int, int) = 0;
    virtual void reshapeCallback(int width, int height) = 0;
    virtual void keyboardCallback(unsigned char, int, int) = 0;
};

#endif //TP2_CG_APPLICATION_HPP
