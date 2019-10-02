#ifndef USER_EXIST_H
#define USER_EXIST_H

#include "all_headers.h"

namespace Ui {
class user_exist;
}

class user_exist : public QDialog
{
    Q_OBJECT

public:
    explicit user_exist(QWidget *parent = 0);
    ~user_exist();

private slots:
    void on_regist_another_button_clicked();

    void on_close_button_clicked();

private:
    Ui::user_exist *ui;
};

#endif // USER_EXIST_H
