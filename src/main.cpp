#include <iostream>
#include <Interfaces/Window.hpp>
#include <Windows/MainWindow.hpp>

int main(int argc, char** argv) {
    Window* window = new MainWindow();
    window->display(argc, argv);
    return 0;
}