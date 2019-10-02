#include "all_headers.h"

//如果数据库不存在，则创建数据库
sqlite_operator::sqlite_operator(QString db_name)
{
    QString name = QString("%1").arg(db_name);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(db_name);
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

void sqlite_operator::create_users_table()
{
    QSqlQuery query = QSqlQuery(db);
    QString str = QString("CREATE TABLE users (\
                          id INT PRIMARY KEY NOT NULL,\
                          user_name TEXT NOT NULL,\
                          password TEXT NOT NULL)");

    if(!query.exec(str))
    {
            qDebug()<<"表users创建失败";
    }
    {
            qDebug()<<"表users创建成功";
    }
}


void sqlite_operator::insert_users_data(QString &user_name,QString &password)
{
    QSqlQuery query;
    //待绑定的数据库插入语句
    query.prepare("INSERT INTO users VALUES (:ID,:Type,:ProduceTime)");
    //绑定数据
    //自动获取表中最大ID
    QString table_name = "users";
    query.bindValue(":ID", this->get_max_id(table_name) + 1);
    query.bindValue(":Type", user_name);
    query.bindValue(":ProduceTime",password);
    //执行查询语句
    query.exec();

}

QHash<QString,QString> sqlite_operator::show_users_data()
{
    //定义存储所有学生数据的散列表
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
            //将学生数据插入散列表中
            user_map.insert(name,password);
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }
    return user_map;
}

int sqlite_operator::get_max_id(QString& table_name)
{
    QSqlQuery sql_query;
    //获取最大ID语句
    QString query = QString("select max(id) from %1").arg(table_name);
    sql_query.prepare(query);
    int max_id = 0;
    if(!sql_query.exec())
    {
        qDebug() << "获取最大ID失败";
    }
    else
    {
        while(sql_query.next())
        {
            //获取最大ID，返回其值
            max_id = sql_query.value(0).toInt();
            return max_id;
        }
    }
    return 0;
}

void sqlite_operator::create_students_table()
{
    QSqlQuery query = QSqlQuery(db);
    QString str = QString("CREATE TABLE students (\
                          id INT PRIMARY KEY NOT NULL,\
                          student_id TEXT NOT NULL,\
                          name TEXT NOT NULL,\
                          sex TEXT NOT NULL,\
                          nation TEXT NOT NULL,\
                          department TEXT NOT NULL,\
                          native_place TEXT NOT NULL\
                          )");

    if(!query.exec(str))
    {
        qDebug()<<"表students创建失败";
    }
    else
    {
        qDebug()<<"表students创建成功";
    }
}

QHash<QString,QString> sqlite_operator::show_students_data()
{
    QHash<QString,QString> student_map;

    QSqlQuery sql_query;
    //查询所有的数据
    QString select_sql = "select id, student_id, name, sex, nation, department, native_place from students";
    if(!sql_query.exec(select_sql))
    {
        qDebug()<< "数据查询失败" <<sql_query.lastError();
    }
    else
    {
        //如果可以检索下一条数据，则返回真
        while(sql_query.next())
        {
            //获取查询到的数据
            int id = sql_query.value(0).toInt();
            QString student_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString nation = sql_query.value(4).toString();
            QString department = sql_query.value(5).toString();
            QString native_place = sql_query.value(6).toString();
            //new一个student_data对象，用于存储单个学生信息
            student_data *temp = new student_data(student_id,name,sex,nation,department,native_place);
            //调用return_data方法，得到固定格式的学生信息
            student_map.insert(student_id,temp->return_data());
            //及时删除学生信息，防止内存浪费
            delete temp;
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }

    return student_map;
}

void sqlite_operator::insert_students_data(QString& in_student_id,QString& in_name,QString& in_sex,QString& in_nation,QString& in_department,QString& in_native_place)
{
    QSqlQuery query;
    //待绑定的数据库插入语句
    query.prepare("INSERT INTO students VALUES (:id,:student_id,:name,:sex,:nation,:department,:native_place)");
    //绑定数据
    //自动获取表中最大ID
    QString table_name = "students";
    query.bindValue(":id", this->get_max_id(table_name) + 1);
    query.bindValue(":student_id", in_student_id);
    query.bindValue(":name",in_name);
    query.bindValue(":sex", in_sex);
    query.bindValue(":nation", in_nation);
    query.bindValue(":department", in_department);
    query.bindValue(":native_place", in_native_place);
    //执行插入语句
    if(!query.exec())
    {
        qDebug()<<"数据插入失败";
    }
    else
    {
        qDebug()<<"数据插入成功";
    }

}

QHash<QString,QString> sqlite_operator::search_students_data_student_id(QString search_text)
{
    QHash<QString,QString> student_map;

    QSqlQuery sql_query;
    QString sql_select = QString("select id, student_id, name, sex, nation, department, native_place from students where student_id = \"%1\"").arg(search_text);
    if(!sql_query.exec(sql_select))
    {
        qDebug()<<"学生数据查询失败";
    }
    else
    {
        while(sql_query.next())
        {
            //获取查询到的学生信息
            int id = sql_query.value(0).toInt();
            QString student_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString nation = sql_query.value(4).toString();
            QString department = sql_query.value(5).toString();
            QString native_place = sql_query.value(6).toString();
            //new一个student_data对象，用于存储单个学生信息
            student_data *temp = new student_data(student_id,name,sex,nation,department,native_place);
            //调用return_data方法，得到固定格式的学生信息
            student_map.insert(student_id,temp->return_data());
            //及时删除学生信息，防止内存浪费
            delete temp;
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }

    return student_map;
}

QHash<QString,QString> sqlite_operator::search_students_data_name(QString search_text)
{
    QHash<QString,QString> student_map;

    QSqlQuery sql_query;
    QString sql_select = QString("select id, student_id, name, sex, nation, department, native_place from students where name = \"%1\"").arg(search_text);
    if(!sql_query.exec(sql_select))
    {
        qDebug()<<"学生数据查询失败";
    }
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString student_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString nation = sql_query.value(4).toString();
            QString department = sql_query.value(5).toString();
            QString native_place = sql_query.value(6).toString();
            //new一个student_data对象，用于存储单个学生信息
            student_data *temp = new student_data(student_id,name,sex,nation,department,native_place);
            //调用return_data方法，得到固定格式的学生信息
            student_map.insert(student_id,temp->return_data());
            //及时删除学生信息，防止内存浪费
            delete temp;
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }

    return student_map;
}

QHash<QString,QString> sqlite_operator::search_students_data_department(QString search_text)
{
    QHash<QString,QString> student_map;

    QSqlQuery sql_query;
    QString sql_select = QString("select id, student_id, name, sex, nation, department, native_place from students where department = \"%1\"").arg(search_text);
    if(!sql_query.exec(sql_select))
    {
        qDebug()<<"学生数据查询失败";
    }
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString student_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString nation = sql_query.value(4).toString();
            QString department = sql_query.value(5).toString();
            QString native_place = sql_query.value(6).toString();
            //new一个student_data对象，用于存储单个学生信息
            student_data *temp = new student_data(student_id,name,sex,nation,department,native_place);
            //调用return_data方法，得到固定格式的学生信息
            student_map.insert(student_id,temp->return_data());
            //及时删除学生信息，防止内存浪费
            delete temp;
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }

    return student_map;
}

QHash<QString,QString> sqlite_operator::search_students_data_sex(QString search_text)
{
    QHash<QString,QString> student_map;

    QSqlQuery sql_query;
    QString sql_select = QString("select id, student_id, name, sex, nation, department, native_place from students where sex = \"%1\"").arg(search_text);
    if(!sql_query.exec(sql_select))
    {
        qDebug()<<"学生数据查询失败";
    }
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString student_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString nation = sql_query.value(4).toString();
            QString department = sql_query.value(5).toString();
            QString native_place = sql_query.value(6).toString();
            //new一个student_data对象，用于存储单个学生信息
            student_data *temp = new student_data(student_id,name,sex,nation,department,native_place);
            //调用return_data方法，得到固定格式的学生信息
            student_map.insert(student_id,temp->return_data());
            //及时删除学生信息，防止内存浪费
            delete temp;
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }

    return student_map;
}

QHash<QString,QString> sqlite_operator::search_students_data_nation(QString search_text)
{
    QHash<QString,QString> student_map;

    QSqlQuery sql_query;
    QString sql_select = QString("select id, student_id, name, sex, nation, department, native_place from students where nation = \"%1\"").arg(search_text);
    if(!sql_query.exec(sql_select))
    {
        qDebug()<<"学生数据查询失败";
    }
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString student_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString nation = sql_query.value(4).toString();
            QString department = sql_query.value(5).toString();
            QString native_place = sql_query.value(6).toString();
            //new一个student_data对象，用于存储单个学生信息
            student_data *temp = new student_data(student_id,name,sex,nation,department,native_place);
            //调用return_data方法，得到固定格式的学生信息
            student_map.insert(student_id,temp->return_data());
            //及时删除学生信息，防止内存浪费
            delete temp;
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }

    return student_map;
}

QHash<QString,QString> sqlite_operator::search_students_data_native_place(QString search_text)
{
    QHash<QString,QString> student_map;

    QSqlQuery sql_query;
    QString sql_select = QString("select id, student_id, name, sex, nation, department, native_place from students where native_place = \"%1\"").arg(search_text);
    if(!sql_query.exec(sql_select))
    {
        qDebug()<<"学生数据查询失败";
    }
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString student_id = sql_query.value(1).toString();
            QString name = sql_query.value(2).toString();
            QString sex = sql_query.value(3).toString();
            QString nation = sql_query.value(4).toString();
            QString department = sql_query.value(5).toString();
            QString native_place = sql_query.value(6).toString();
            //new一个student_data对象，用于存储单个学生信息
            student_data *temp = new student_data(student_id,name,sex,nation,department,native_place);
            //调用return_data方法，得到固定格式的学生信息
            student_map.insert(student_id,temp->return_data());
            //及时删除学生信息，防止内存浪费
            delete temp;
            qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
        }
    }

    return student_map;
}

void sqlite_operator::delete_student(QString in_student_id)
{
    QSqlQuery query;
    QString str = QString("delete from students where student_id = %1").arg(in_student_id);
    if(!query.exec(str))
    {
        qDebug()<<"学生数据删除失败";
        delete_fail d;
        d.exec();
    }
    else
    {
        qDebug()<<"删除成功";
        delete_success d;
        d.exec();

    }
}

void sqlite_operator::update_student(QString& in_student_id,QString& in_name,QString& in_sex,QString& in_nation,QString& in_department,QString& in_native_place)
{
    QSqlQuery query;
    QString str = QString("update students set student_id = \"%1\", name = \"%2\" ,sex = \"%3\" ,nation = \"%4\", department = \"%5\"\
                          , native_place = \"%6\" where student_id = %7 ").arg(in_student_id,in_name,in_sex,in_nation,in_department,in_native_place,in_student_id);
    if(!query.exec(str))
    {
        qDebug()<<"学生数据修改失败";
        qDebug()<<query.lastError();
    }
    else
    {
        qDebug()<<"修改成功";

    }
}
