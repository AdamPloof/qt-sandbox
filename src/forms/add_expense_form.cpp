#include "ui_add_expense_form.h"
#include "add_expense_form.h"

AddExpenseForm::AddExpenseForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddExpenseForm)
{
    ui->setupUi(this);
}

AddExpenseForm::~AddExpenseForm()
{
    delete ui;
}

void AddExpenseForm::on_cancelBtn_clicked() {
    this->close();
}
