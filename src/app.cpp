#include "app.h"
#include "ui_app.h"
#include "forms/add_expense_form.h"

App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);
    addExpenseForm = new AddExpenseForm(this);
    addExpenseForm->setWindowFlag(Qt::Window);
}

App::~App()
{
    delete ui;
    delete addExpenseForm;
}

void App::on_addBtn_clicked() {
    addExpenseForm->show();
}

