#include "all_headers.h"

no_this_user::no_this_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::no_this_user)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

no_this_user::~no_this_user()
{
    delete ui;
}

void no_this_user::on_close_button_clicked()
{
    this->close();
}

void no_this_user::on_try_again_button_clicked()
{
    this->close();
}
