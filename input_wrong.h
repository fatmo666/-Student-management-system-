#ifndef INPUT_WRONG_H
#define INPUT_WRONG_H

#include "all_headers.h"

namespace Ui {
class input_wrong;
}

class input_wrong : public QDialog
{
    Q_OBJECT

public:
    explicit input_wrong(QWidget *parent = 0);
    ~input_wrong();

private slots:
    void on_close_button_clicked();

    void on_regist_another_button_clicked();

private:
    Ui::input_wrong *ui;
};

#endif // INPUT_WRONG_H
