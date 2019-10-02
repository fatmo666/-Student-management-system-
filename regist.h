#ifndef REGIST_H
#define REGIST_H

#include "all_headers.h"

namespace Ui {
class regist;
}

class regist : public QDialog
{
    Q_OBJECT

public:
    explicit regist(QWidget *parent = 0);
    ~regist();

private slots:
    //按下退出按钮
    void on_quit_button_clicked();

    //按下提交按钮(注册页面)
    void on_submit_button_clicked();

private:
    Ui::regist *ui;
};

#endif // REGIST_H
