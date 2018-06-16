#include <Domain/ColorPicker.hpp>
#include <GL/gl.h>
#include <iostream>

/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

ColorPicker::ColorPicker(std::vector<Color> colors, int height) : colors(colors), height(height) {
    pickedColor = 0;
}


bool ColorPicker::isColorPicker(int x, int y) {
    int width = (int) (this->height / (double) (this->colors.size() + 1));
    if (x <= width) {
        std::cout << "here" << std::endl;
        int picked = (int)((y/(float)height)*(this->colors.size()+1));
        std::cout << picked << std::endl;
        if (picked < this->colors.size()) {
            this->pickedColor = picked;
        }
        return true;
    }

    return false;
}

Color ColorPicker::getPickedColor() {
    if (pickedColor < colors.size()) {
        return colors.at(pickedColor);
    }
    return Color(0,0,0);
}

void ColorPicker::draw() {
    int size = (int) (this->height / (double) (this->colors.size()+1));

    for(int i = 0; i < colors.size(); i++) {
        Color color = colors.at(i);
        glColor3f(color.getR()/255.0, color.getG()/255.0, color.getB()/255.0);
        glBegin(GL_POLYGON);
        glVertex2i(0, i*size);
        glVertex2i(size, i*size);
        glVertex2i(size, (i+1)*size);
        glVertex2i(0, (i+1)*size);
        glEnd();
    }

    Color color = colors.at(pickedColor);

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(0, colors.size()*size);
    glVertex2i(size, colors.size()*size);
    glVertex2i(size, (colors.size()+1)*size);
    glVertex2i(0, (colors.size()+1)*size);
    glEnd();

    glColor3f(color.getR()/255.0, color.getG()/255.0, color.getB()/255.0);
    glBegin(GL_POLYGON);
    glVertex2i(5, colors.size()*size + 5);
    glVertex2i(size - 5, colors.size()*size  + 5);
    glVertex2i(size - 5, (colors.size()+1)*size - 5);
    glVertex2i(5, (colors.size()+1)*size - 5);
    glEnd();
}

int ColorPicker::getSize() {
    return (int) (this->height / (double) (this->colors.size() + 1));
}

