#include <QTableView>
#include <QSqlDatabase>

#include "app.h"
#include "ui_app.h"
#include "forms/add_expense_form.h"
#include "service/entity_manager.h"
#include "model/expense_model.h"

App::App(QWidget *parent)
    : QMainWindow(parent),
    // m_dao(dao),
    ui(new Ui::App)
{
    ui->setupUi(this);
    m_addExpenseForm = new AddExpenseForm(this);
    m_addExpenseForm->setWindowFlag(Qt::Window);
    m_entityManager = std::make_shared<EntityManager>(EntityManager());
    m_expenseModel = new ExpenseModel(m_entityManager);
}

App::~App()
{
    delete ui;
    delete m_addExpenseForm;
}

void App::run() {
    QSqlDatabase db = m_entityManager->openDb();
    if (!db.isOpen()) {
        // TODO: exit early with error
    }

    m_expenseModel->load();
    ui->expenseTbl->setModel(m_expenseModel);
    formatTable(ui->expenseTbl);
}

void App::formatTable(QTableView* tbl) {
    tbl->verticalHeader()->setVisible(false);
    tbl->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tbl->setColumnHidden(0, true); // hide index col
}

// ## SLOTS ##

void App::on_addBtn_clicked() {
    m_addExpenseForm->show();
}

