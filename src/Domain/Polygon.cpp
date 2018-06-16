/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

#include <Domain/Polygon.hpp>
#include <tuple>
#include <iostream>

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

bool Polygon::isOutlimits(int xmin, int ymin, int xmax, int ymax) {
    for(auto vertex : this->getVertices()) {

    }
    return false;
}
