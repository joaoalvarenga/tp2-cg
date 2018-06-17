/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#ifndef TP2_CG_COLORPICKER_HPP
#define TP2_CG_COLORPICKER_HPP

#include <vector>
#include "Color.hpp"

class ColorPicker {
public:
    ColorPicker() = default;
    ColorPicker(std::vector<Color> colors, int y, int height);

    void draw();

    bool isColorPicker(int x, int y);
    Color getPickedColor();
    int getSize();

private:
    std::vector<Color> colors;
    int y;
    int height;
    int pickedColor;
};

#endif //TP2_CG_COLORPICKER_HPP
