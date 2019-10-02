#include "all_headers.h"

regist_success::regist_success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regist_success)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

regist_success::~regist_success()
{
    delete ui;
}

void regist_success::on_auto_login_button_clicked()
{
    //关闭当前窗口
    this->close();
    //弹出主窗口
    manage_window w;
    w.exec();
}

void regist_success::on_regist_another_button_clicked()
{
    //关闭当前窗口
    this->close();
    //弹出注册窗口
    regist r;
    r.exec();
}

void regist_success::on_close_button_clicked()
{
    //关闭当前窗口
    this->close();
}
