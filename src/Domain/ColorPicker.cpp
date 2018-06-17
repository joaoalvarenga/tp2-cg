#include <Domain/ColorPicker.hpp>
#include <GL/gl.h>
#include <iostream>

/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

ColorPicker::ColorPicker(std::vector<Color> colors, int y, int height) : colors(colors) {
    this->y = y;
    this->height = height - y;
    pickedColor = 0;
}


bool ColorPicker::isColorPicker(int x, int y) {
    int width = (int) (this->height / (double) (this->colors.size() + 1));
    y -= this->y;
    if (x <= width && y >= 0) {
        int picked = (int)(((y)/(float)height)*(this->colors.size()+1));
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
        glVertex2i(0, y + i*size);
        glVertex2i(size,y +  i*size);
        glVertex2i(size, y + (i+1)*size);
        glVertex2i(0, y + (i+1)*size);
        glEnd();
    }

    Color color = colors.at(pickedColor);

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(0, y + colors.size()*size);
    glVertex2i(size, y + colors.size()*size);
    glVertex2i(size, y + (colors.size()+1)*size);
    glVertex2i(0, y + (colors.size()+1)*size);
    glEnd();

    glColor3f(color.getR()/255.0, color.getG()/255.0, color.getB()/255.0);
    glBegin(GL_POLYGON);
    glVertex2i(5, y + colors.size()*size + 5);
    glVertex2i(size - 5, y + colors.size()*size  + 5);
    glVertex2i(size - 5, y + (colors.size()+1)*size - 5);
    glVertex2i(5, y + (colors.size()+1)*size - 5);
    glEnd();
}

int ColorPicker::getSize() {
    return (int) (this->height / (double) (this->colors.size() + 1));
}

