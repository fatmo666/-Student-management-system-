#-------------------------------------------------
#
# Project created by QtCreator 2019-05-02T20:45:03
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student_management_
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    regist.cpp \
    sqlite_operator.cpp \
    manage_window.cpp \
    student_data.cpp \
    regist_success.cpp \
    user_exist.cpp \
    input_wrong.cpp \
    update_student.cpp \
    update_success.cpp \
    password_not_match.cpp \
    no_this_user.cpp \
    delete_success.cpp \
    delete_fail.cpp

HEADERS  += login.h \
    regist.h \
    sqlite_operator.h \
    all_headers.h \
    manage_window.h \
    student_data.h \
    regist_success.h \
    user_exist.h \
    input_wrong.h \
    update_student.h \
    update_success.h \
    password_not_match.h \
    no_this_user.h \
    delete_success.h \
    delete_fail.h

FORMS    += login.ui \
    regist.ui \
    manage_window.ui \
    regist_success.ui \
    user_exist.ui \
    input_wrong.ui \
    update_student.ui \
    update_success.ui \
    password_not_match.ui \
    no_this_user.ui \
    delete_success.ui \
    delete_fail.ui

RESOURCES += \
    picture.qrc
