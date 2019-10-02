#ifndef SQLITE_OPRATOR_H
#define SQLITE_OPRATOR_H

#include "all_headers.h"


//此类实现对数据库的操作
class sqlite_operator
{
    private:
        QSqlDatabase db;
    public:
        sqlite_operator(QString db_name);
        ~sqlite_operator();
    public:
        //连接数据库
        bool db_open();
        //判断表是否存在
        bool is_table_exist(QString& table_name);
        //创建users表
        void create_users_table();
        //插入表users的单行数据
        void insert_users_data(QString &user_name,QString &password);
        //获取，展示表user所有数据
        QHash<QString,QString> show_users_data();
        //获得最大id
        int get_max_id(QString& table_name);
        //创建students表
        void create_students_table();
        //获取，展示表students所有数据
        QHash<QString,QString> show_students_data();
        //插入表students的单行数据
        void insert_students_data(QString& in_student_id,QString& in_name,QString& in_sex,QString& in_nation,QString& in_department,QString& in_native_place);
        //通过student_id的方式查询数据
        QHash<QString,QString> search_students_data_student_id(QString search_text);
        //通过name的方式查询数据
        QHash<QString,QString> search_students_data_name(QString search_text);
        //通过department的方式查询数据
        QHash<QString,QString> search_students_data_department(QString search_text);
        //通过sex的方式查询数据
        QHash<QString,QString> search_students_data_sex(QString search_text);
        //通过nation的方式查询数据
        QHash<QString,QString> search_students_data_nation(QString search_text);
        //通过native_palce的方式查询数据
        QHash<QString,QString> search_students_data_native_place(QString search_text);
        //通过student_id查询并删除学生信息
        void delete_student(QString in_student_id);
        //通过student_id查询并修改学生信息
        void update_student(QString& in_student_id,QString& in_name,QString& in_sex,QString& in_nation,QString& in_department,QString& in_native_place);
};

#endif // SQLITE_OPRATOR_H
