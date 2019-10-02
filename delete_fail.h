#ifndef DELETE_FAIL_H
#define DELETE_FAIL_H

#include "all_headers.h"

namespace Ui {
class delete_fail;
}

class delete_fail : public QDialog
{
    Q_OBJECT

public:
    explicit delete_fail(QWidget *parent = 0);
    ~delete_fail();

private slots:
    void on_back_button_clicked();

    void on_close_button_clicked();

private:
    Ui::delete_fail *ui;
};

#endif // DELETE_FAIL_H
