#include "all_headers.h"

delete_success::delete_success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_success)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

delete_success::~delete_success()
{
    delete ui;
}

void delete_success::on_back_button_clicked()
{
    this->close();
}

void delete_success::on_close_button_clicked()
{
    this->close();
}
