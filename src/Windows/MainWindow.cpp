/*
 * Trabalho Pratico 2 - Computacao Grafica
 * Joao Paulo Reis Alvarenga
 * Manoel Stilpen
*/

#include <Windows/MainWindow.hpp>


MainWindow *MainWindow::instance = nullptr;
Application *MainWindow::application = nullptr;

void MainWindow::initGl(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(800, 600);
    glutCreateWindow("Menu");

    glutDisplayFunc(drawCallbackWrapper);
    glutMouseFunc(mouseCallbackWrapper);
    glutMotionFunc(mouseMoveCallback);

    int rotateMenu = glutCreateMenu(menuCallbackWrapper);
    glutAddMenuEntry("+90", ROTATE_POLYGON_PLUS_90);
    glutAddMenuEntry("-90", ROTATE_POLYGON_MINUS_90);

    glutCreateMenu(menuCallbackWrapper);
    glutAddMenuEntry("Criar poligono", CREATE_POLYGON);
    glutAddMenuEntry("Selecionar poligono", SELECT_POLYGON);
    glutAddMenuEntry("Transladar poligono", TRANSLATE_POLYGON);
    glutAddSubMenu("Rotacionar poligono", rotateMenu);
    glutAddMenuEntry("Calcular area", GET_AREA_MEASUREMENT);
    glutAddMenuEntry("Definir orientacao", GET_ORIENTATION);
    glutAddMenuEntry("Eliminar", DELETE);
    glutAddMenuEntry("Limpar", CLEAR);
    glutAddMenuEntry("Sair", QUIT);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 800, 600, 0.0f, 0.0f, 1.0f);

}

void MainWindow::setInstance() {
    MainWindow::instance = this;
}

void MainWindow::display(int argc, char **argv) {
    setInstance();

    MainWindow::application = new MainApplication();

    initGl(argc, argv);     // Our own OpenGL initialization
    glutMainLoop();         // Enter the event-processing loop
}

void MainWindow::drawCallbackWrapper() {
    MainWindow::application->draw();

    glutPostRedisplay();
}

void MainWindow::mouseCallbackWrapper(int button, int state, int x, int y) {
    MainWindow::application->mouseCallback(button, state, x, y);
}

void MainWindow::menuCallbackWrapper(int option) {
    MainWindow::application->menuCallback(option);
}

void MainWindow::menuCallBack(int option) {
}

void MainWindow::mouseMoveCallback(int x, int y) {
    MainWindow::application->mouseMoveCallback(x, y);
}