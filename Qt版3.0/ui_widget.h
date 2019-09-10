/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 10 10:14:16 2019
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
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget_c;
    QGridLayout *gridLayout_2;
    QPushButton *left;
    QPushButton *right;
    QListWidget *listWidget_s;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ip;
    QLabel *label_2;
    QLineEdit *username;
    QLabel *label_3;
    QLineEdit *password;
    QLabel *label_4;
    QLineEdit *port;
    QPushButton *connect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *clientdir;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *serverdir;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1096, 620);
        Widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_5 = new QHBoxLayout(Widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        listWidget_c = new QListWidget(Widget);
        listWidget_c->setObjectName(QString::fromUtf8("listWidget_c"));
        QFont font;
        font.setPointSize(14);
        listWidget_c->setFont(font);
        listWidget_c->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(listWidget_c);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(20, 10, 20, -1);
        left = new QPushButton(Widget);
        left->setObjectName(QString::fromUtf8("left"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(left->sizePolicy().hasHeightForWidth());
        left->setSizePolicy(sizePolicy);
        left->setMinimumSize(QSize(50, 50));
        left->setSizeIncrement(QSize(0, 0));
        left->setFont(font);
        left->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(left, 0, 0, 1, 1);

        right = new QPushButton(Widget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setMinimumSize(QSize(50, 50));
        right->setFont(font);
        right->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(right, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 5);
        gridLayout_2->setRowStretch(1, 5);

        horizontalLayout_4->addLayout(gridLayout_2);

        listWidget_s = new QListWidget(Widget);
        listWidget_s->setObjectName(QString::fromUtf8("listWidget_s"));
        listWidget_s->setFont(font);
        listWidget_s->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(listWidget_s);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(2, 3);

        horizontalLayout_3->addLayout(horizontalLayout_4);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        ip = new QLineEdit(Widget);
        ip->setObjectName(QString::fromUtf8("ip"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ip->sizePolicy().hasHeightForWidth());
        ip->setSizePolicy(sizePolicy2);
        ip->setMinimumSize(QSize(0, 40));
        ip->setFont(font);

        horizontalLayout->addWidget(ip);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        username = new QLineEdit(Widget);
        username->setObjectName(QString::fromUtf8("username"));
        sizePolicy2.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy2);
        username->setMinimumSize(QSize(0, 40));
        username->setFont(font);

        horizontalLayout->addWidget(username);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        password = new QLineEdit(Widget);
        password->setObjectName(QString::fromUtf8("password"));
        sizePolicy2.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy2);
        password->setMinimumSize(QSize(0, 40));
        password->setFont(font);
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(password);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        port = new QLineEdit(Widget);
        port->setObjectName(QString::fromUtf8("port"));
        sizePolicy2.setHeightForWidth(port->sizePolicy().hasHeightForWidth());
        port->setSizePolicy(sizePolicy2);
        port->setMinimumSize(QSize(0, 40));
        port->setFont(font);

        horizontalLayout->addWidget(port);

        connect = new QPushButton(Widget);
        connect->setObjectName(QString::fromUtf8("connect"));
        sizePolicy2.setHeightForWidth(connect->sizePolicy().hasHeightForWidth());
        connect->setSizePolicy(sizePolicy2);
        connect->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setPointSize(15);
        connect->setFont(font2);
        connect->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(connect);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 4);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(5, 4);
        horizontalLayout->setStretch(6, 1);
        horizontalLayout->setStretch(7, 1);
        horizontalLayout->setStretch(8, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        clientdir = new QLineEdit(Widget);
        clientdir->setObjectName(QString::fromUtf8("clientdir"));
        sizePolicy2.setHeightForWidth(clientdir->sizePolicy().hasHeightForWidth());
        clientdir->setSizePolicy(sizePolicy2);
        clientdir->setMinimumSize(QSize(0, 40));
        clientdir->setFont(font);

        horizontalLayout_2->addWidget(clientdir);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        serverdir = new QLineEdit(Widget);
        serverdir->setObjectName(QString::fromUtf8("serverdir"));
        sizePolicy2.setHeightForWidth(serverdir->sizePolicy().hasHeightForWidth());
        serverdir->setSizePolicy(sizePolicy2);
        serverdir->setMinimumSize(QSize(0, 40));
        serverdir->setFont(font);

        horizontalLayout_2->addWidget(serverdir);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 10);

        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 10);

        horizontalLayout_5->addLayout(gridLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "HLXFTP", 0, QApplication::UnicodeUTF8));
        left->setText(QApplication::translate("Widget", "<<", 0, QApplication::UnicodeUTF8));
        right->setText(QApplication::translate("Widget", ">>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "ip\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        ip->setText(QApplication::translate("Widget", "192.168.43.45", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("Widget", "zhizhen", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        password->setText(QApplication::translate("Widget", "327209194", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("Widget", "21", 0, QApplication::UnicodeUTF8));
        connect->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\346\234\254\345\234\260\347\233\256\345\275\225\357\274\232", 0, QApplication::UnicodeUTF8));
        clientdir->setText(QApplication::translate("Widget", "/", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\350\277\234\347\250\213\347\233\256\345\275\225\357\274\232", 0, QApplication::UnicodeUTF8));
        serverdir->setText(QApplication::translate("Widget", "/", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
