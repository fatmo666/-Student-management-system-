#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H

#include "all_headers.h"

class student_data
{
private:
    QString student_id;
    QString name;
    QString sex;
    QString nation;
    QString department;
    QString native_place;

public:
    student_data(QString& in_student_id,QString& in_name,QString& in_sex,QString& in_nation,QString& in_department,QString& in_native_place);

    //返回固定格式的学生数据信息
    QString return_data();
};

#endif // STUDENT_DATA_H
