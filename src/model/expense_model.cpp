#include <QList>
#include <vector>

#include "expense_model.h"
#include "../entity/expense.h"
#include "../entity/entity_interface.h"

ExpenseModel::ExpenseModel(QObject *parent) {
    std::shared_ptr<Expense> exp1 = std::make_shared<Expense>(Expense());
    exp1->setData("id", 1);
    exp1->setData("description", "Food");
    exp1->setData("amount", 42.00);

    std::shared_ptr<Expense> exp2 = std::make_shared<Expense>(Expense());
    exp2->setData("id", 2);
    exp2->setData("description", "House");
    exp2->setData("amount", 105.00);

    std::shared_ptr<Expense> exp3 = std::make_shared<Expense>(Expense());
    exp3->setData("id", 3);
    exp3->setData("description", "Heat");
    exp3->setData("amount", 99.50);

    m_expenses.insert(exp1->getId(), exp1);
    m_expenses.insert(exp2->getId(), exp2);
    m_expenses.insert(exp3->getId(), exp3);
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
