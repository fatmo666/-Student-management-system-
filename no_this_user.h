#ifndef NO_THIS_USER_H
#define NO_THIS_USER_H

#include "all_headers.h"

namespace Ui {
class no_this_user;
}

class no_this_user : public QDialog
{
    Q_OBJECT

public:
    explicit no_this_user(QWidget *parent = 0);
    ~no_this_user();

private slots:
    void on_close_button_clicked();

    void on_try_again_button_clicked();

private:
    Ui::no_this_user *ui;
};

#endif // NO_THIS_USER_H
