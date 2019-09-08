/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sun Sep 8 22:15:07 2019
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *ip;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *port;
    QPushButton *connect;
    QLineEdit *clientdir;
    QLineEdit *serverdir;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *left;
    QPushButton *right;
    QListWidget *listWidget_c;
    QListWidget *listWidget_s;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1096, 620);
        Widget->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 81, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ip = new QLineEdit(Widget);
        ip->setObjectName(QString::fromUtf8("ip"));
        ip->setGeometry(QRect(100, 30, 191, 31));
        username = new QLineEdit(Widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(410, 30, 151, 31));
        password = new QLineEdit(Widget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(672, 30, 151, 31));
        password->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 30, 101, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(570, 30, 111, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(840, 30, 51, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        port = new QLineEdit(Widget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(890, 30, 51, 31));
        connect = new QPushButton(Widget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(970, 30, 81, 31));
        QFont font1;
        font1.setPointSize(15);
        connect->setFont(font1);
        connect->setStyleSheet(QString::fromUtf8(""));
        clientdir = new QLineEdit(Widget);
        clientdir->setObjectName(QString::fromUtf8("clientdir"));
        clientdir->setGeometry(QRect(140, 90, 331, 27));
        serverdir = new QLineEdit(Widget);
        serverdir->setObjectName(QString::fromUtf8("serverdir"));
        serverdir->setGeometry(QRect(720, 90, 331, 27));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 90, 101, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(630, 90, 91, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        left = new QPushButton(Widget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(520, 460, 61, 41));
        left->setStyleSheet(QString::fromUtf8(""));
        right = new QPushButton(Widget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(520, 550, 61, 41));
        right->setStyleSheet(QString::fromUtf8(""));
        listWidget_c = new QListWidget(Widget);
        listWidget_c->setObjectName(QString::fromUtf8("listWidget_c"));
        listWidget_c->setGeometry(QRect(50, 140, 420, 450));
        listWidget_c->setStyleSheet(QString::fromUtf8(""));
        listWidget_s = new QListWidget(Widget);
        listWidget_s->setObjectName(QString::fromUtf8("listWidget_s"));
        listWidget_s->setGeometry(QRect(630, 140, 420, 450));
        listWidget_s->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "HLXFTP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "serverip", 0, QApplication::UnicodeUTF8));
        ip->setText(QApplication::translate("Widget", "192.168.43.45", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("Widget", "zhizhen", 0, QApplication::UnicodeUTF8));
        password->setText(QApplication::translate("Widget", "327209194", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "username", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "password", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "port", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("Widget", "21", 0, QApplication::UnicodeUTF8));
        connect->setText(QApplication::translate("Widget", "connect", 0, QApplication::UnicodeUTF8));
        clientdir->setText(QApplication::translate("Widget", "/", 0, QApplication::UnicodeUTF8));
        serverdir->setText(QApplication::translate("Widget", "/", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "clientdir", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "serverdir", 0, QApplication::UnicodeUTF8));
        left->setText(QApplication::translate("Widget", "<<", 0, QApplication::UnicodeUTF8));
        right->setText(QApplication::translate("Widget", ">>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
