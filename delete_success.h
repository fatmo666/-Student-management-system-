#ifndef DELETE_SUCCESS_H
#define DELETE_SUCCESS_H

#include "all_headers.h"

namespace Ui {
class delete_success;
}

class delete_success : public QDialog
{
    Q_OBJECT

public:
    explicit delete_success(QWidget *parent = 0);
    ~delete_success();

private slots:
    void on_back_button_clicked();

    void on_close_button_clicked();

private:
    Ui::delete_success *ui;
};

#endif // DELETE_SUCCESS_H
