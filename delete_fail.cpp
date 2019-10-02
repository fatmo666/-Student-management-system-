#include "all_headers.h"

delete_fail::delete_fail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_fail)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

delete_fail::~delete_fail()
{
    delete ui;
}

void delete_fail::on_back_button_clicked()
{
    this->close();
}

void delete_fail::on_close_button_clicked()
{
    this->close();
}
