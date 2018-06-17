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
    this->formingPolygon = nullptr;
    std::vector<Color> colors;
    colors.push_back(Color(255,0,0));
    colors.push_back(Color(0,255,0));
    colors.push_back(Color(0,0,255));
    colors.push_back(Color(255,255,0));
    colors.push_back(Color(255,0,255));
    colors.push_back(Color(0,255,255));
    colors.push_back(Color(0,0,0));
    this->colorPicker = new ColorPicker(colors, 30, 600);
    this->statusBar = new StatusBar();
    this->statusBar->setStatus(NONE);

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


    if (this->statusBar->getStatus() == CREATE) {
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
    else if(this->statusBar->getStatus() == SELECT || this->statusBar->getStatus() == TRANSLATE || this->statusBar->getStatus() == ROTATE) {
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

    statusBar->draw();

    glFlush();

}

void MainApplication::menuCallback(int option) {
    switch(option) {
        case CREATE_POLYGON:
            selectedPolygon = nullptr;
            createNewPolygon();
            break;
        case SELECT_POLYGON:
            selectedPolygon = nullptr;
            this->statusBar->setStatus(SELECT);
            break;
        case TRANSLATE_POLYGON:
            if (selectedPolygon == nullptr) {
                this->statusBar->setStatus(NONE);
                this->statusBar->setText("Selecione um poligono primeiro");
            } else {
                this->statusBar->setStatus(TRANSLATE);
            }
            break;
        case ROTATE_POLYGON_PLUS_90:
            if (selectedPolygon == nullptr) {
                this->statusBar->setStatus(NONE);
                this->statusBar->setText("Selecione um poligono primeiro");
            }
            else {
                rotateAngle = 90;
                this->statusBar->setStatus(ROTATE);
            }
            break;
        case ROTATE_POLYGON_MINUS_90:
            if (selectedPolygon == nullptr) {
                this->statusBar->setStatus(NONE);
                this->statusBar->setText("Selecione um poligono primeiro");
            }
            else {
                rotateAngle = -90;
                this->statusBar->setStatus(ROTATE);
            }
            break;
        case GET_AREA_MEASUREMENT:
            if (selectedPolygon == nullptr) {
                this->statusBar->setStatus(NONE);
                this->statusBar->setText("Selecione um poligono primeiro");
            } else {
                this->statusBar->setStatus(NONE);
                this->statusBar->setText("Poligono de orientacao " + getPolygonOrientationText(*selectedPolygon));
            }
            break;

        case GET_ORIENTATION:
            if (selectedPolygon == nullptr) {
                this->statusBar->setStatus(NONE);
                this->statusBar->setText("Selecione um poligono primeiro");
            } else {
                this->statusBar->setStatus(NONE);
                this->statusBar->setText("Poligono de orientacao " + getPolygonOrientationText(*selectedPolygon));
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
                APPLICATION_STATUS status = this->statusBar->getStatus();
                if (status == CREATE) {
                    addVertexToNewPolygon(x, y);
                }
                else if(status == SELECT) {
                    for(int i = polygons.size() - 1; i >= 0; i--) {
                        if(polygons.at(i).isIntersecting(std::pair<int, int>(x, y))) {
                            selectedPolygon = &polygons.at(i);
                            return;
                        }
                    }
                }
                else if(status == TRANSLATE) {
                    std::pair<int,int> center = selectedPolygon->getCenter();
                    startPosition.first = center.first;
                    startPosition.second = center.second;
                }
                else if(status == ROTATE) {
                    selectedPolygon->rotateTo(rotateAngle, x, y);
                    this->statusBar->setStatus(NONE);
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
    this->statusBar->setStatus(CREATE);
}

void MainApplication::addVertexToNewPolygon(int x, int y) {
    if (formingPolygon->getVertices().size() > 0) {
        std::pair<int, int> initialVertex = *formingPolygon->getVertices().at(0);
        if(distance2d(initialVertex.first, initialVertex.second, x, y) < 5) {
            polygons.push_back(*formingPolygon);
            this->statusBar->setStatus(NONE);
        }
    }
    formingPolygon->addVertex(x, y);
    std::cout << "Adding vertex (" << x << "," << y << ")" << std::endl;

}

void MainApplication::mouseMoveCallback(int x, int y) {
    if (this->statusBar->getStatus() == TRANSLATE) {
        selectedPolygon->translateTo(x,  y, std::pair<int, int>(colorPicker->getSize(), 800), std::pair<int, int>(statusBar->getMaxY(), 600));
    }
}

std::string MainApplication::getPolygonOrientationText(Polygon pol) {
    if(pol.getOrientation() == CLOCKWISE) {
        return "HORARIO";
    }
    return "ANTI-HORARIO";

}

