#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <memory>

class AddExpenseForm;
class DAO;

namespace Ui {
    class App;
}

class App : public QMainWindow
{
    Q_OBJECT

public:
    explicit App(std::shared_ptr<DAO> dao, QWidget *parent = nullptr);
    ~App();
    void run();

private slots:
    void on_addBtn_clicked();

private:
    Ui::App *ui;
    std::shared_ptr<DAO> m_dao;
    AddExpenseForm *m_addExpenseForm;
};

#endif // APP_H
