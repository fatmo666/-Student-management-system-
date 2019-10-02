#ifndef LOGIN_H
#define LOGIN_H

#include "all_headers.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    //按下提交按钮
    void on_submit_button_clicked();

    //按下退出按钮
    void on_quit_button_clicked();

    //按下注册按钮
    void on_regist_button_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
