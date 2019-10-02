#include "all_headers.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_submit_button_clicked()
{
    //获取用户输入数据
    QString user_name = ui->username_edit->text();
    QString password = ui->password_edit->text();

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


    /*
    //遍历散列表
    QHash<QString,QString>::const_iterator iter = user_map.constBegin();
    while(iter != user_map.constEnd())
    {
        qDebug()<<iter.key()<<":"<<iter.value();
        ++iter;
    }
    */

    //判断用户输入的用户名密码是否正确
    QHash<QString, QString>::iterator user;
    user = user_map.find(user_name);
    if(user != user_map.end())
    {
        if(user.value() == password)
        {
            qDebug()<<"登陆成功";
            //弹出主窗口
            manage_window w;
            w.showFullScreen();
            w.exec();
        }
        else
        {
            //弹出输入错误提示窗口
            input_wrong i;
            i.exec();
        }
    }
    else
    {
        //弹出提示窗口
        no_this_user n;
        n.exec();
    }
}


void login::on_quit_button_clicked()
{
    //退出窗体
    this->close();
}


void login::on_regist_button_clicked()
{
    //创建注册窗体
    regist regist_windows;
    //使用模态视图
    regist_windows.exec();
}
