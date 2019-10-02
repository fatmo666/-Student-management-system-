#ifndef UPDATE_SUCCESS_H
#define UPDATE_SUCCESS_H

#include "all_headers.h"

namespace Ui {
class update_success;
}

class update_success : public QDialog
{
    Q_OBJECT

public:
    explicit update_success(QWidget *parent = 0);
    ~update_success();

private slots:
    void on_close_button_clicked();

    void on_back_buttom_clicked();

private:
    Ui::update_success *ui;
};

#endif // UPDATE_SUCCESS_H
