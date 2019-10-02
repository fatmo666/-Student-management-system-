#include "all_headers.h"

update_success::update_success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update_success)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

update_success::~update_success()
{
    delete ui;
}

void update_success::on_close_button_clicked()
{
    //关闭窗口
    this->close();
}

void update_success::on_back_buttom_clicked()
{
    //关闭窗口
    this->close();
}
