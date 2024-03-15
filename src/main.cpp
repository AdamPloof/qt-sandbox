#include <QApplication>
#include <iostream>

#include "app.h"


int main(int argc, char* argv[]) {
    std::cout << "testing..." << std::endl;

    QApplication a(argc, argv);
    App w = App();
    w.show();

    return a.exec();
}
