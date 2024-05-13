#include <QApplication>
#include <QString>
#include <QVariant>
#include <QHash>
#include <QHashIterator>
#include <QDebug>
#include <iostream>
#include <memory>

#include "app.h"
#include "entity/expense.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    App app = App();
    app.run();
    app.show();

    return a.exec();
}
