#ifndef EXPENSE_MODEL_H
#define EXPENSE_MODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QHash>
#include <memory>

class EntityInterface;

class ExpenseModel : public QAbstractTableModel {
    Q_OBJECT

    public:
        explicit ExpenseModel(QObject *parent = nullptr);
        // ~ExpenseModel();

        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
        Qt::ItemFlags flags(const QModelIndex &index) const override;
        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
        // void addRow(std::shared_ptr<ModelInterface> row) override;

    private:
        QHash<int, std::shared_ptr<EntityInterface>> m_expenses;
};

#endif // EXPENSE_MODEL_H