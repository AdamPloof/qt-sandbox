#ifndef DAO_H
#define DAO_H

#include <QSqlQuery>
#include <QVariantList>
#include <vector>
#include <memory>

class QSqlDatabase;
class QString;
class ModelInterface;

class DAO {

public:
    DAO();
    ~DAO();

    static QSqlDatabase& openDb();
    static void closeDb();
};

#endif // DAO_H
