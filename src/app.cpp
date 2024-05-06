#include <QTableView>

#include "app.h"
#include "ui_app.h"
#include "forms/add_expense_form.h"
#include "service/dao.h"
#include "model/expense_model.h"

App::App(QWidget *parent)
    : QMainWindow(parent),
    // m_dao(dao),
    ui(new Ui::App)
{
    ui->setupUi(this);
    m_addExpenseForm = new AddExpenseForm(this);
    m_addExpenseForm->setWindowFlag(Qt::Window);
    m_expenseModel = new ExpenseModel();
}

App::~App()
{
    delete ui;
    delete m_addExpenseForm;
}

void App::run() {
    ui->expenseTbl->setModel(m_expenseModel);
    formatTable(ui->expenseTbl);
    // m_dao->openDb();
}

void App::formatTable(QTableView* tbl) {
    tbl->verticalHeader()->setVisible(false);
    tbl->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

// ## SLOTS ##

void App::on_addBtn_clicked() {
    m_addExpenseForm->show();
}

