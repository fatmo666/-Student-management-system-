#include "all_headers.h"

input_wrong::input_wrong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input_wrong)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

input_wrong::~input_wrong()
{
    delete ui;
}

void input_wrong::on_close_button_clicked()
{
    this->close();
}

void input_wrong::on_regist_another_button_clicked()
{
    this->close();
}
