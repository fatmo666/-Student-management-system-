#ifndef UPDATE_STUDENT_H
#define UPDATE_STUDENT_H

#include"all_headers.h"

namespace Ui {
class update_student;
}

class update_student : public QDialog
{
    Q_OBJECT

public:
    explicit update_student(QWidget *parent = 0);
    ~update_student();

private slots:
    void on_quit_button_clicked();
    void on_submit_button_clicked();

private:
    Ui::update_student *ui;
};

#endif // UPDATE_STUDENT_H
