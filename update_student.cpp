#include "all_headers.h"

update_student::update_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update_student)
{
    ui->setupUi(this);

    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

update_student::~update_student()
{
    delete ui;
}

void update_student::on_submit_button_clicked()
{
    //获取用户填入的要插入的学生的信息
    QString student_id = ui->student_id_edit->text();
    QString name = ui->name_edit->text();
    QString sex = ui->sex_edit->text();
    QString nation = ui->nation_edit->text();
    QString department = ui->department_edit->text();
    QString native_place = ui->native_place_edit->text();

    //连接数据库
    QString db_name = "student.db";
    sqlite_operator db(db_name);
    db.db_open();
    QString table_name = "students";
    if(!db.is_table_exist(table_name))
    {
        db.create_students_table();
    }
    else
    {
        qDebug()<<"表students已经存在";
    }

    //修改学生信息;
    db.update_student(student_id,name,sex,nation,department,native_place);
}

void update_student::on_quit_button_clicked()
{
    this->close();
}
