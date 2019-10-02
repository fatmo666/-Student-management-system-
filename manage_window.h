#ifndef MANAGE_WINDOW_H
#define MANAGE_WINDOW_H

#include "all_headers.h"

namespace Ui {
class manage_window;
}

class manage_window : public QDialog
{
    Q_OBJECT

public:
    explicit manage_window(QWidget *parent = 0);
    //设置,展示表格
    void set_table();
    //设置，展示查询得到的表格
    void set_search_tabel(int type,QString search_text);
    ~manage_window();

private slots:
    //按下提交按钮(新增学生数据时)
    void on_submit_button_clicked();

    //按下提交按钮(搜索学生数据时)
    void on_search_button_clicked();

    void on_quit_button_clicked();

private:
    Ui::manage_window *ui;
    QStandardItemModel *model;
};

#endif // MANAGE_WINDOW_H
