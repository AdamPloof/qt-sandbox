#include <QList>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>

#include "expense_model.h"
#include "../service/entity_manager.h"
#include "../entity/expense.h"
#include "../entity/entity_interface.h"

ExpenseModel::ExpenseModel(
    std::shared_ptr<EntityManager> em,
    QObject *parent
) : m_entityManger(em) {

}

// ExpenseModel::~ExpenseModel() {
    
// }

void ExpenseModel::load() {
    QSqlQuery q = QSqlQuery("SELECT id, description, amount FROM expense");
    while (q.next()) {
        std::shared_ptr<Expense> exp = std::make_shared<Expense>(Expense());
        exp->setData("id", q.value(0).toInt());
        exp->setData("description", q.value(1).toString());
        exp->setData("amount", q.value(2).toFloat());
        m_expenses.insert(exp->getId(), exp);
    }
}

int ExpenseModel::rowCount(const QModelIndex &parent) const {
    return m_expenses.count();
}

int ExpenseModel::columnCount(const QModelIndex &parent) const {
    return Expense::fields.size();
}

QVariant ExpenseModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole && !m_expenses.isEmpty()) {
        QList keys = m_expenses.keys();
        int id = keys[index.row()];
        QString field = Expense::fields.at(index.column());

        return m_expenses[id]->getData(field);
    }

    return QVariant();
}

QVariant ExpenseModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return Expense::fields[section];
    }

    return QVariant();
}

Qt::ItemFlags ExpenseModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::ItemIsEnabled;
    }

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool ExpenseModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        QList keys = m_expenses.keys();
        int id = keys[index.row()];
        QString field = Expense::fields.at(index.column());
        m_expenses[id]->setData(field, value);
        
        emit dataChanged(index, index, {role});

        return true;
    }

    return false;
}
