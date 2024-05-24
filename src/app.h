#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <memory>

class ExpenseModel;
class QTableView;
class AddExpenseForm;
class EntityManager;

namespace Ui {
    class App;
}

class App : public QMainWindow
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = nullptr);
    ~App();
    void run();

private slots:
    void on_addBtn_clicked();

private:
    Ui::App *ui;
    // std::shared_ptr<DAO> m_dao;
    AddExpenseForm *m_addExpenseForm;
    void formatTable(QTableView* tbl);
    void connectForms();

    ExpenseModel* m_expenseModel;
    std::shared_ptr<EntityManager> m_entityManager;
};

#endif // APP_H
