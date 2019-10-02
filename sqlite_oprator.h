#ifndef SQLITE_OPRATOR_H
#define SQLITE_OPRATOR_H
#include <qdebug.h>
#include <QString>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QHash>


//此类实现对数据库的操作
class sqlite_operator
{
    private:
        QSqlDatabase db;
    public:
        sqlite_operator();
        ~sqlite_operator();
    public:
        //连接数据库
        bool db_open();
        //判断表users是否存在
        bool is_table_exist(QString& table_name);
        //创建users表
        void create_table();
        //插入单行数据
        void insert_data(QString &user_name,QString &password);
        //展示所有数据
        QHash<QString,QString> show_data();
        //获得最大id
        int get_max_id();
};

//如果数据库不存在，则创建数据库
sqlite_operator::sqlite_operator()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
}

//析构函数，断开数据库
sqlite_operator::~sqlite_operator()
{
    db.close();
}

bool sqlite_operator::db_open()
{
    if(!db.open())
    {
        qDebug() << "连接数据库失败!" ;
        return false;
    }
    else
    {
        qDebug()<< "连接数据库成功" ;
        return true;
    }
}

bool sqlite_operator::is_table_exist(QString& table_name)
{
    if(db.tables().contains(table_name))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sqlite_operator::create_table()
{
    QSqlQuery query = QSqlQuery(db);
    QString str = QString("CREATE TABLE users (\
                          id INT PRIMARY KEY NOT NULL,\
                          user_name TEXT NOT NULL,\
                          password TEXT NOT NULL)");
    query.exec(str);
}


void sqlite_operator::insert_data(QString &user_name,QString &password)
{
    QSqlQuery query;
    //待绑定的数据库插入语句
    query.prepare("INSERT INTO users VALUES (:ID,:Type,:ProduceTime)");
    //绑定数据
    //自动获取表中最大ID
    query.bindValue(":ID", this->get_max_id() + 1);
    query.bindValue(":Type", user_name);
    query.bindValue(":ProduceTime",password);
    //执行查询语句
    query.exec();

}

QHash<QString,QString> sqlite_operator::show_data()
{
    QHash<QString,QString> user_map;

    QSqlQuery sql_query;
    //查询所有的数据
    QString select_sql = "select id, user_name, password from users";
    if(!sql_query.exec(select_sql))
    {
        qDebug()<< "数据查询失败" <<sql_query.lastError();
    }
    else
    {
        //如果可以检索下一条数据，则返回真
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString name = sql_query.value(1).toString();
            QString password = sql_query.value(2).toString();
            user_map.insert(name,password);
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }
    return user_map;
}

int sqlite_operator::get_max_id()
{
    QSqlQuery sql_query;
    //获取最大ID语句
    QString select_max_sql = "select max(id) from users";
    int max_id = 0;
    sql_query.prepare(select_max_sql);
    if(!sql_query.exec())
    {
        qDebug() << "error";
    }
    else
    {
        while(sql_query.next())
        {
            max_id = sql_query.value(0).toInt();
            return max_id;
        }
    }
}

#endif // SQLITE_OPRATOR_H

