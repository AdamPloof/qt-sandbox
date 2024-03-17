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

void testExpense() {
    Expense expense;
    expense.setData("id", 42);
    expense.setData("description", "Forty two");
    expense.setData("amount", 4.2);

    QHash<QString, QVariant> data = expense.getData();
    QHashIterator<QString, QVariant> i(data);

    while (i.hasNext()) {
        i.next();

        qDebug() << i.key() << ": " << i.value();
    }
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    std::shared_ptr<DAO> dao = std::make_shared<DAO>();
    App app = App(dao);
    testExpense();
    app.run();
    app.show();

    return a.exec();
}
