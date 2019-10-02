#include "all_headers.h"

user_exist::user_exist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_exist)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

user_exist::~user_exist()
{
    delete ui;
}

void user_exist::on_regist_another_button_clicked()
{
    //关闭当前窗口
    this->close();
    //弹出注册窗口
    regist r;
    r.exec();
}

void user_exist::on_close_button_clicked()
{
    this->close();
}
