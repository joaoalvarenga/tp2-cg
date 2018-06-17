/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/
#ifndef TP2_CG_MAINAPPLICATION_HPP
#define TP2_CG_MAINAPPLICATION_HPP

#include <Interfaces/Application.hpp>
#include <Utils/Commons.hpp>
#include <Domain/Polygon.hpp>
#include <Domain/ColorPicker.hpp>
#include <Domain/StatusBar.hpp>

using namespace commons;

class MainApplication : public Application {
public:
    MainApplication(int, int);

    void draw() override;
    void mouseCallback(int button, int state, int x, int y) override ;
    void menuCallback(int option) override ;
    void mouseMoveCallback(int x, int y);
    void reshapeCallback(int width, int height);
    void keyboardCallback(unsigned char key, int x, int y);

    std::string getPolygonOrientationText(Polygon pol);
    std::string getPolygonAreaText(Polygon pol);

    void createNewPolygon();
    void addVertexToNewPolygon(int x, int y);

private:
    std::vector<Polygon> polygons;

    Polygon * formingPolygon;
    Polygon * selectedPolygon;
    ColorPicker* colorPicker;
    StatusBar* statusBar;
    int rotateAngle;
    int selectedIndex;

    int windowWidth, windowHeight;

    std::pair<int, int> startPosition;
};

#endif //TP2_CG_MAINAPPLICATION_HPP
