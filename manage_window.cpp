#include "all_headers.h"

manage_window::manage_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage_window)
{
    ui->setupUi(this);

    //构造函数中调用set_table方法，使表格展示
    model = new QStandardItemModel;
    this->set_table();
}

manage_window::~manage_window()
{
    delete ui;
    delete model;
}

void manage_window::set_table()
{
    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("民族"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("籍贯"));
    this->ui->student_table->setAlternatingRowColors(1);

    //绑定模型
    this->ui->student_table->setModel(model);

    //设置表头宽度
    this->ui->student_table->setColumnWidth(0,150);
    this->ui->student_table->setColumnWidth(1,150);
    this->ui->student_table->setColumnWidth(2,108);
    this->ui->student_table->setColumnWidth(3,150);
    this->ui->student_table->setColumnWidth(4,150);
    this->ui->student_table->setColumnWidth(5,150);

    //隐藏左边表头
    ui->student_table->verticalHeader()->hide();
    //自动拉伸最后一列
    ui->student_table->horizontalHeader()->setStretchLastSection(true);
    //使表格中的文字左对齐
    //ui->student_table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //this->model->setItem(1,2, QStandardItem("text"));

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

    //获取存储所有学生信息的哈希表
    QHash<QString,QString> student_map = db.show_students_data();
    //定义表格的行数，列数
    int row = 0;
    int column = 0;
    QStringList temp;
    //遍历哈希表
    QHash<QString,QString>::const_iterator iter = student_map.constBegin();
    while(iter != student_map.constEnd())
    {
        qDebug()<<iter.key()<<":"<<iter.value();
        //切开固定格式的学生数据，以此绑定在表格上
        temp = QStringList(iter.value().split("|"));
        for(column = 0;column < 6;column++)
        {
            //绑定学生信息
            QString temp_item = temp[column];
            this->model->setItem(row ,column,new QStandardItem(temp_item));
        }
        ++iter;
        ++row;
    }

}

void manage_window::set_search_tabel(int type,QString search_text)
{
    //清楚表格信息
    this->model->clear();

    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("民族"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("籍贯"));

    //绑定模型
    this->ui->student_table->setModel(model);

    //设置表头宽度
    this->ui->student_table->setColumnWidth(0,150);
    this->ui->student_table->setColumnWidth(1,150);
    this->ui->student_table->setColumnWidth(2,108);
    this->ui->student_table->setColumnWidth(3,150);
    this->ui->student_table->setColumnWidth(4,150);
    this->ui->student_table->setColumnWidth(5,150);

    //隐藏左边表头
    ui->student_table->verticalHeader()->hide();
    //自动拉伸最后一列
    ui->student_table->horizontalHeader()->setStretchLastSection(true);
    //使表格中的文字左对齐
    //ui->student_table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //this->model->setItem(1,2, QStandardItem("text"));

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

    //如果type==0，表示用户按照学号查询
    if(type == 0)
    {
        QHash<QString,QString> student_map = db.search_students_data_student_id(search_text);
        //定义表格的行数，列数
        int row = 0;
        int column = 0;
        QStringList temp;
        //遍历哈希表
        QHash<QString,QString>::const_iterator iter = student_map.constBegin();
        while(iter != student_map.constEnd())
        {
            qDebug()<<iter.key()<<":"<<iter.value();
            //切开固定格式的学生信息
            temp = QStringList(iter.value().split("|"));
            for(column = 0;column < 6;column++)
            {
                //依次绑定学生信息在表格上
                QString temp_item = temp[column];
                this->model->setItem(row ,column,new QStandardItem(temp_item));
            }
            ++iter;
            ++row;
        }
    }
    //如果type == 1，表示用户按照名字查询
    else if(type == 1)
    {
        QHash<QString,QString> student_map = db.search_students_data_name(search_text);
        //定义表格的行数，列数
        int row = 0;
        int column = 0;
        QStringList temp;
        //遍历散列表
        QHash<QString,QString>::const_iterator iter = student_map.constBegin();
        while(iter != student_map.constEnd())
        {
            qDebug()<<iter.key()<<":"<<iter.value();
            //切开固定格式的学生信息
            temp = QStringList(iter.value().split("|"));
            for(column = 0;column < 6;column++)
            {
                //将学生信息依次绑定在表格上
                QString temp_item = temp[column];
                this->model->setItem(row ,column,new QStandardItem(temp_item));
            }
            ++iter;
            ++row;
        }
    }
    //如果type == 2，表示用户按照学院查询
    else if(type == 2)
    {
        QHash<QString,QString> student_map = db.search_students_data_department(search_text);
        //定义表格的行数，列数
        int row = 0;
        int column = 0;
        QStringList temp;
        //遍历散列表
        QHash<QString,QString>::const_iterator iter = student_map.constBegin();
        while(iter != student_map.constEnd())
        {
            qDebug()<<iter.key()<<":"<<iter.value();
            //切开固定格式的学生信息
            temp = QStringList(iter.value().split("|"));
            for(column = 0;column < 6;column++)
            {
                //将学生信息依次绑定在表格上
                QString temp_item = temp[column];
                this->model->setItem(row ,column,new QStandardItem(temp_item));
            }
            ++iter;
            ++row;
        }
    }

    //如果type == 3，表示用户按照性别查询
    else if(type == 3)
    {
        QHash<QString,QString> student_map = db.search_students_data_sex(search_text);
        //定义表格的行数，列数
        int row = 0;
        int column = 0;
        QStringList temp;
        //遍历散列表
        QHash<QString,QString>::const_iterator iter = student_map.constBegin();
        while(iter != student_map.constEnd())
        {
            qDebug()<<iter.key()<<":"<<iter.value();
            //切开固定格式的学生信息
            temp = QStringList(iter.value().split("|"));
            for(column = 0;column < 6;column++)
            {
                //将学生信息依次绑定在表格上
                QString temp_item = temp[column];
                this->model->setItem(row ,column,new QStandardItem(temp_item));
            }
            ++iter;
            ++row;
        }
    }

    //如果type == 4，表示用户按照民族查询
    else if(type == 4)
    {
        QHash<QString,QString> student_map = db.search_students_data_nation(search_text);
        //定义表格的行数，列数
        int row = 0;
        int column = 0;
        QStringList temp;
        //遍历散列表
        QHash<QString,QString>::const_iterator iter = student_map.constBegin();
        while(iter != student_map.constEnd())
        {
            qDebug()<<iter.key()<<":"<<iter.value();
            //切开固定格式的学生信息
            temp = QStringList(iter.value().split("|"));
            for(column = 0;column < 6;column++)
            {
                //将学生信息依次绑定在表格上
                QString temp_item = temp[column];
                this->model->setItem(row ,column,new QStandardItem(temp_item));
            }
            ++iter;
            ++row;
        }
    }

    //如果type == 5，表示用户按照户籍查询
    else if(type == 5)
    {
        QHash<QString,QString> student_map = db.search_students_data_native_place(search_text);
        //定义表格的行数，列数
        int row = 0;
        int column = 0;
        QStringList temp;
        //遍历散列表
        QHash<QString,QString>::const_iterator iter = student_map.constBegin();
        while(iter != student_map.constEnd())
        {
            qDebug()<<iter.key()<<":"<<iter.value();
            //切开固定格式的学生信息
            temp = QStringList(iter.value().split("|"));
            for(column = 0;column < 6;column++)
            {
                //将学生信息依次绑定在表格上
                QString temp_item = temp[column];
                this->model->setItem(row ,column,new QStandardItem(temp_item));
            }
            ++iter;
            ++row;
        }
    }
}

void manage_window::on_submit_button_clicked()
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

    //执行插入数据库操作
    db.insert_students_data(student_id,name,sex,nation,department,native_place);
    //刷新表格
    this->set_table();
}

void manage_window::on_search_button_clicked()
{
    //获取用户操作方式
    int operate_type = ui->operate_comboBox->currentIndex();
    //获取用户输入的查询信息
    QString search_text = ui->search_edit->text();
    //获取用户选择的查询方式
    int search_type = ui->search_type->currentIndex();

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
    if(operate_type == 0)
    {
        //重新构建表格
        this->set_search_tabel(search_type,search_text);
    }

    else if(operate_type == 1)
    {
        //修改学生信息
        update_student u;
        u.exec();
    }

    else if(operate_type == 2)
    {
        //删除学生信息
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

        db.delete_student(search_text);
    }


}

void manage_window::on_quit_button_clicked()
{
    this->close();
}
