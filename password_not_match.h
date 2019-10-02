#ifndef PASSWORD_NOT_MATCH_H
#define PASSWORD_NOT_MATCH_H

# include "all_headers.h"

namespace Ui {
class password_not_match;
}

class password_not_match : public QDialog
{
    Q_OBJECT

public:
    explicit password_not_match(QWidget *parent = 0);
    ~password_not_match();

private slots:
    void on_close_button_clicked();

    void on_try_agin_button_clicked();

private:
    Ui::password_not_match *ui;
};

#endif // PASSWORD_NOT_MATCH_H
