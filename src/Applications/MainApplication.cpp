/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

#include <Applications/MainApplication.hpp>
#include <cstdlib>
#include <iostream>
#include <Utils/Utils.hpp>

MainApplication::MainApplication() {
    this->status = NONE;
    this->formingPolygon = nullptr;
    std::vector<Color> colors;
    colors.push_back(Color(255,0,0));
    colors.push_back(Color(0,255,0));
    colors.push_back(Color(0,0,255));
    colors.push_back(Color(255,255,0));
    colors.push_back(Color(255,0,255));
    colors.push_back(Color(0,255,255));
    colors.push_back(Color(0,0,0));
    this->colorPicker = new ColorPicker(colors, 600);

}

void MainApplication::run() {
}


void MainApplication::draw() {
    run();

    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    colorPicker->draw();
    if(formingPolygon != nullptr) {
        formingPolygon->setFillColor(colorPicker->getPickedColor());
    }

    for(auto polygon : polygons) {
        glColor3f(polygon.getFillColor().getR()/255.0, polygon.getFillColor().getB()/255.0, polygon.getFillColor().getG()/255.0);
        glBegin(GL_POLYGON);
        for(auto vertex : polygon.getVertices()) {
            glVertex2i(vertex->first, vertex->second);
        }
        glEnd();
    }


    if (this->status == CREATE) {
        glColor3f(formingPolygon->getFillColor().getR()/255.0, formingPolygon->getFillColor().getG()/255.0, formingPolygon->getFillColor().getB()/255.0);
        glBegin(GL_LINE_STRIP);
        for(auto vertex : formingPolygon->getVertices()) {
            glVertex2i(vertex->first, vertex->second);
        }
        glEnd();

        glPointSize(3);
        glColor3f(0,0,0);
        glBegin(GL_POINTS);
        for(auto vertex : formingPolygon->getVertices()) {
            glVertex2i(vertex->first, vertex->second);
        }
        glEnd();
    }
    else if(this->status == SELECT || this->status == TRANSLATE) {
        if (selectedPolygon != nullptr) {
            glColor3f(0,0,0);
            glBegin(GL_LINE_STRIP);
            for(auto vertex : selectedPolygon->getVertices()) {
                glVertex2i(vertex->first, vertex->second);
            }
            glVertex2i(selectedPolygon->getVertices().at(0)->first,
                       selectedPolygon->getVertices().at(0)->second);
            glEnd();

            glPointSize(3);
            glColor3f(0,0,0);
            glBegin(GL_POINTS);
            for(auto vertex : selectedPolygon->getVertices()) {
                glVertex2i(vertex->first, vertex->second);
            }
            glEnd();
        }
    }


    glFlush();

}

void MainApplication::menuCallback(int option) {
    switch(option) {
        case CREATE_POLYGON:
            std::cout << "Creating polygon" << std::endl;
            createNewPolygon();
            break;
        case SELECT_POLYGON:
            selectedPolygon = nullptr;
            this->status = SELECT;
            break;
        case TRANSLATE_POLYGON:
            if (selectedPolygon == nullptr) {
                this->status = NONE;
            } else {
                this->status = TRANSLATE;
            }
            break;

        case QUIT:
            exit(0);
    }
}

void MainApplication::mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            if (!this->colorPicker->isColorPicker(x, y)) {
                if (this->status == CREATE) {
                    addVertexToNewPolygon(x, y);
                }
                else if(this->status == SELECT) {
                    for(int i = polygons.size() - 1; i >= 0; i--) {
                        if(polygons.at(i).isIntersecting(std::pair<int, int>(x, y))) {
                            selectedPolygon = &polygons.at(i);
                            return;
                        }
                    }
                }
                else if(this->status == TRANSLATE) {
                    std::pair<int,int> center = selectedPolygon->getCenter();
                    startPosition.first = center.first;
                    startPosition.second = center.second;
                }
            }
        }
    }
}

void MainApplication::createNewPolygon() {
    if (this->formingPolygon != nullptr) {
        delete this->formingPolygon;
    }
    this->formingPolygon = new Polygon();
    this->status = CREATE;
}

void MainApplication::addVertexToNewPolygon(int x, int y) {
    if (formingPolygon->getVertices().size() > 0) {
        std::pair<int, int> initialVertex = *formingPolygon->getVertices().at(0);
        if(distance2d(initialVertex.first, initialVertex.second, x, y) < 5) {
            polygons.push_back(*formingPolygon);
            this->status = NONE;
        }
    }
    formingPolygon->addVertex(x, y);
    std::cout << "Adding vertex (" << x << "," << y << ")" << std::endl;

}

void MainApplication::mouseMoveCallback(int x, int y) {
    if (this->status == TRANSLATE) {
        selectedPolygon->translateTo(x,  y, std::pair<int, int>(colorPicker->getSize(), 800), std::pair<int, int>(0, 600));
    }
}
