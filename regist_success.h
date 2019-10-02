#ifndef REGIST_SUCCESS_H
#define REGIST_SUCCESS_H

#include "all_headers.h"

namespace Ui {
class regist_success;
}

class regist_success : public QDialog
{
    Q_OBJECT

public:
    explicit regist_success(QWidget *parent = 0);
    ~regist_success();

private slots:
    void on_auto_login_button_clicked();

    void on_regist_another_button_clicked();

    void on_close_button_clicked();

private:
    Ui::regist_success *ui;
};

#endif // REGIST_SUCCESS_H
