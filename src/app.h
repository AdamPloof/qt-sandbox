#ifndef APP_H
#define APP_H

#include <QMainWindow>

class AddExpenseForm;

namespace Ui {
    class App;
}

class App : public QMainWindow
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = nullptr);
    ~App();

private slots:
    void on_addBtn_clicked();

private:
    Ui::App *ui;
    AddExpenseForm *addExpenseForm;
};

#endif // APP_H
