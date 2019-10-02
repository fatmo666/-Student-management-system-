#include "all_headers.h"

password_not_match::password_not_match(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password_not_match)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

password_not_match::~password_not_match()
{
    delete ui;
}

void password_not_match::on_close_button_clicked()
{
    this->close();
}

void password_not_match::on_try_agin_button_clicked()
{
    this->close();
}
