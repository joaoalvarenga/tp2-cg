/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#include <Domain/StatusBar.hpp>
#include <GL/gl.h>
#include <GL/glut.h>

StatusBar::StatusBar() : color(200, 200, 200) {
    x = 0;
    y = 0;
    width = 800;
    height = 30;
    text = "MODO VISUALIZACAO";
}

void StatusBar::draw() {
    glColor3f(color.getR()/255.0, color.getG()/255.0, color.getB()/255.0);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + width, y);
    glVertex2i(x + width, y + height);
    glVertex2i(x, y + height);
    glEnd();

    if (text.length() > 0) {
        glColor3f(0, 0, 0);
        glRasterPos2i(12, 22);
        for (char c : text) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
}

void StatusBar::setText(std::string text) {
    this->text = text;
}

APPLICATION_STATUS StatusBar::getStatus() {
    return this->status;
}

void StatusBar::setStatus(APPLICATION_STATUS status) {
    this->status = status;
    switch(this->status) {
        case CREATE:
            this->setText("MODO DE CRIACAO");
            break;
        case SELECT:
            this->setText("MODO DE SELECAO");
            break;
        case TRANSLATE:
            this->setText("MODO DE TRANSLACAO");
            break;
        case ROTATE:
            this->setText("MODO ROTACAO");
            break;
        case NONE:
        default:
            this->setText("MODO DE VISUALIZACAO");
            break;
    }
}

int StatusBar::getMaxY() {
    return y + height;
}
