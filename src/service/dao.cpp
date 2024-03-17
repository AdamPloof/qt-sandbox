#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <sstream>
#include <cstddef>

#include "dao.h"

DAO::DAO() {}

DAO::~DAO() {
    closeDb();
}

QSqlDatabase& DAO::openDb() {
    static QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if (!db.open()) {
        qDebug() << "DB error: " << db.lastError().text() << "\n";
    }

    return db;
}

void DAO::closeDb() {
    QSqlDatabase::database().close();
}
