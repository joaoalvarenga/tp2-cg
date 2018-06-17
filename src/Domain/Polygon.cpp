/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

#include <Domain/Polygon.hpp>
#include <tuple>
#include <iostream>
#include <math.h>

Polygon::Polygon() : Polygon(0,0,0) {
}

Polygon::Polygon(int r, int g, int b) : fillColor(r,g,b) {
    min.first = -1;
    min.second = -1;
    max.first = -1;
    max.second = -1;
}

bool Polygon::addVertex(int x, int y) {
    if (x < min.first || min.first == -1) {
        min.first = x;
    }
    else if(x > max.first || max.first == -1) {
        max.first = x;
    }

    if (y < min.second || min.second == -1) {
        min.second = y;
    }
    else if(y > max.second || max.second == -1) {
        max.second = y;
    }


    this->vertices.push_back(new std::pair<int, int>(x, y));
    return true;
}

std::vector<std::pair<int, int>*> Polygon::getVertices() {
    return this->vertices;
}

Color Polygon::getFillColor() {
    return fillColor;
}

void Polygon::setFillColor(Color color) {
    this->fillColor = color;
}

bool Polygon::isIntersecting(std::pair<int, int> point) {
    std::pair<int, int>* vi;
    std::pair<int, int>* vj;
    bool c = false;
    for(int i = 0, j = this->getVertices().size() - 1; i < this->getVertices().size(); j = i++) {
        vi = this->getVertices()[i];
        vj = this->getVertices()[j];
        if ( ((vi->second>point.second) != (vj->second>point.second)) &&
             (point.first < (vj->first-vi->first) * (point.second-vi->second) / (vj->second-vi->second) + vi->first)) {
            c = !c;
        }
    }
    return c;
}

void Polygon::translateTo(int x, int y, std::pair<int, int> limitX, std::pair<int, int> limitY) {
    std::pair<int, int> center = this->getCenter();
    int dx = x - center.first;
    int dy = y - center.second;
    if ((min.first + dx) < limitX.first) {
        dx = limitX.first - min.first;
    }
    else if(max.first + dx > limitX.second) {
        dx = limitX.second - max.first;
    }

    if ((min.second + dy) < limitY.first) {
        dy = limitY.first - min.second;
    }
    else if(max.second + dy > limitY.second) {
        dy = limitY.second - max.second;
    }
    for (auto vertex : this->getVertices()) {
        vertex->first += dx;
        vertex->second += dy;
    }
    min.first += dx;
    min.second += dy;
    max.first += dx;
    max.second += dy;

}

std::pair<int, int> Polygon::getCenter() {

    int meanX = 0;
    int meanY = 0;

    for (auto vertex : this->getVertices()) {
        meanX += vertex->first;
        meanY += vertex->second;
    }

    meanX = (int)(meanX/(float)this->getVertices().size());
    meanY = (int)(meanY/(float)this->getVertices().size());

    return std::pair<int, int>(meanX, meanY);
}

void Polygon::rotateTo(int angle, int x, int y) {
    min.first = -1;
    min.second = -1;
    max.first = -1;
    max.second = -1;
    double radAngle = angle*M_PI/180.0;
    for (auto vertex : this->getVertices()) {
        std::pair<int, int> origin(*vertex);
        std::pair<int, int> translated(origin.first - x, origin.second - y);
        vertex->first = x + (translated.first * cos(radAngle) - translated.second * sin(radAngle));
        vertex->second = y + (translated.first * sin(radAngle) + translated.second * cos(radAngle));

        if (vertex->first < min.first || min.first == -1) {
            min.first = vertex->first;
        }
        else if(vertex->first > max.first || max.first == -1) {
            max.first = vertex->first;
        }

        if (vertex->second < min.second || min.second == -1) {
            min.second = vertex->second;
        }
        else if(vertex->second > max.second || max.second == -1) {
            max.second = vertex->second;
        }
    }
}

ORIENTATION Polygon::getOrientation() {
    /*int i = 0;
    int det = (vertices[i+1]->first - vertices[i]->first)*(vertices[i+2]->second - vertices[i]->second) - (vertices[i+2]->first - vertices[i]->first) * (vertices[i+1]->second - vertices[i]->second);
    while (det == 0) {
        i++;
        det = (vertices[i+1]->first - vertices[i]->first)*(vertices[i+2]->second - vertices[i]->second) - (vertices[i+2]->first - vertices[i]->first) * (vertices[i+1]->second - vertices[i]->second);
    }
    std::cout << std::endl;
    std::cout << vertices[i]->first << "," << vertices[i]->second << std::endl;
    std::cout << vertices[i+1]->first << "," << vertices[i+1]->second << std::endl;
    std::cout << vertices[i+2]->first << "," << vertices[i+2]->second << std::endl;
    std::cout << det << std::endl;
    this->orientation = det > 0 ? COUNTERCLOCKWISE : CLOCKWISE;
    return orientation;*/

    if (this->vertices.size() <= 4) {
        int x = vertices[0]->first;
        for(int i = 1; i < vertices.size(); i++) {
            if (x != vertices[i]->first) {
                this->orientation = vertices[i]->first > x ? CLOCKWISE : COUNTERCLOCKWISE;
                return this->orientation;
            }
            x = vertices[i]->first;
        }
    }

    orientation = getArea() < 0 ? CLOCKWISE : COUNTERCLOCKWISE;
    return orientation;
}

double Polygon::getArea() {
    double area = 0;
    int j;
    for(int i = 0; i < vertices.size(); i++) {
        j = (i + 1) % vertices.size();
        area += (vertices[j]->first - vertices[i]->first) * (vertices[j]->first + vertices[i]->second);
    }
    return area/2.0;
}