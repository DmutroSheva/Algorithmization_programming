#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // повідомлення у statusbar
    ui->statusbar->showMessage("Готово до роботи");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// кнопка "Обчислити"
void MainWindow::on_pushButton_clicked()
{
    // декларація змінних
    float a, V, S;
    bool ok;

    // введення даних
    a = ui->le_a->text().toFloat(&ok);

    // перевірка правильності введення
    if (!ok || a <= 0)
    {
        QMessageBox::warning(
            0,
            "Помилка",
            "Невірно введено число!");

        // очищення полів
        clear_data_fields();

        // повідомлення у statusbar
        ui->statusbar->showMessage("Помилка!");

    }
    else
    {
        // обчислення
        V = a * a * a;
        S = 6 * a * a;

        // виведення результатів
        output_data(V, S);

        // повідомлення у statusbar
        ui->statusbar->showMessage("OK!");
    }
}

// очищення полів
void MainWindow::clear_data_fields()
{
    ui->le_a->clear();

    ui->l_v->setText("0");
    ui->l_s->setText("0");

    ui->le_a->setFocus();
}

// виведення результатів
void MainWindow::output_data(float V, float S)
{
    ui->l_v->setText(QString::number(V));
    ui->l_s->setText(QString::number(S));
}
