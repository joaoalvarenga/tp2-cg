/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#ifndef TP2_CG_STATUSBAR_HPP
#define TP2_CG_STATUSBAR_HPP

#include <Utils/Commons.hpp>
#include <string>
#include <Domain/Color.hpp>

using namespace commons;

class StatusBar {
public:
    StatusBar(int);
    void draw();
    void setText(std::string text);
    APPLICATION_STATUS getStatus();
    void setStatus(APPLICATION_STATUS status);
    int getMaxY();
    void setWidth(int width);
private:
    int x, y, width, height;
    Color color;
    std::string text;
    APPLICATION_STATUS status;

};

#endif //TP2_CG_STATUSBAR_HPP
