#ifndef DAO_H
#define DAO_H

#include <QSqlQuery>
#include <QVariantList>
#include <vector>
#include <memory>

class QSqlDatabase;
class QString;
class ModelInterface;

class EntityManager {

public:
    EntityManager();
    ~EntityManager();

    static QSqlDatabase& openDb();
    static void closeDb();

    bool isReady();
};

#endif // DAO_H
