#include "student_data.h"

student_data::student_data(QString& in_student_id,QString& in_name,QString& in_sex,QString& in_nation,QString& in_department,QString& in_native_place)
{
    this->student_id = in_student_id;
    this->name = in_name;
    this->sex = in_sex;
    this->nation = in_nation;
    this->department = in_department;
    this->native_place = in_native_place;
}

QString student_data::return_data()
{
    //用“|”分隔学生信息，后续可以直接切开以此保存
    QString data = QString("%1|%2|%3|%4|%5|%6").arg(student_id).arg(name).arg(sex).arg(nation).arg(department).arg(native_place);
    return data;
}

