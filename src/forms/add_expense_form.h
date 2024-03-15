#ifndef ADD_EXPENSE_FORM_H
#define ADD_EXPENSE_FORM_H

#include <QWidget>

namespace Ui {
    class AddExpenseForm;
}

class AddExpenseForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddExpenseForm(QWidget *parent = nullptr);
    ~AddExpenseForm();

private slots:
    void on_cancelBtn_clicked();

private:
    Ui::AddExpenseForm *ui;
};

#endif // ADD_EXPENSE_FORM_H
