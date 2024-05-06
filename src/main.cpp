#include <QApplication>
#include <QString>
#include <QVariant>
#include <QHash>
#include <QHashIterator>
#include <QDebug>
#include <iostream>
#include <memory>

#include "app.h"
#include "service/dao.h"
#include "entity/expense.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    // std::shared_ptr<DAO> dao = std::make_shared<DAO>();
    App app = App();
    app.run();
    app.show();

    return a.exec();
}
