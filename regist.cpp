#include "all_headers.h"

regist::regist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);
    //去除窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
}

regist::~regist()
{
    delete ui;
}

void regist::on_quit_button_clicked()
{
    this->close();
}

void regist::on_submit_button_clicked()
{
    //获取用户输入数据
    QString user_name = ui->username_edit->text();
    QString password = ui->password_edit->text();
    QString repeat_password = ui->repeat_password_edit->text();

    //连接数据库
    QString db_name = "user.db";
    sqlite_operator db(db_name);
    db.db_open();

    //判断数据库中是否有users表，没有则创建
    QString table_name = "users";
    if(!db.is_table_exist(table_name))
    {
        db.create_users_table();
    }

    //初始化散列表
    QHash<QString,QString> user_map =  db.show_users_data();

    //判断用户输入的用户名密码是否正确
    QHash<QString, QString>::iterator user;
    user = user_map.find(user_name);
    if(user != user_map.end())
    {
        qDebug()<<"该用户已经存在";
        //关闭当前窗口
        this->close();
        //弹出用于已存在提升窗口
        user_exist u;
        u.exec();
    }
    else
    {
        //插入新注册的用户信息
        if(password == repeat_password)
        {
            db.insert_users_data(user_name,password);
            qDebug()<<"用户注册成功";
            //关闭当前窗口
            this->close();
            //弹出注册成功窗口
            regist_success r;
            r.exec();
        }
        else
        {
            password_not_match p;
            qDebug()<<"前后密码输入不一致";
            p.exec();
        }
    }
}
