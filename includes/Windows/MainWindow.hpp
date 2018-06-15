/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/


#ifndef TP2_CG_MAINWINDOW_HPP
#define TP2_CG_MAINWINDOW_HPP

#include <iostream>
#include <GL/glut.h>

#include <Interfaces/Window.hpp>
#include <Utils/Commons.hpp>

using namespace std;
using namespace commons;

class MainWindow : public Window {

public:

    MainWindow() = default;
    void display(int argc, char** argv) override;

protected:

    // static variables
    static MainWindow* instance;

    MENU_OPTIONS option;

    // utils methods
    void setInstance();
    void initGl(int argc, char** argv);

    // Callback wrappers
    static void drawCallbackWrapper();
    static void mouseCallbackWrapper(int button, int state, int x, int y);
    static void menuCallbackWrapper(int option);

    void menuCallBack(int option);

};

#endif //TP2_CG_MAINWINDOW_HPP
