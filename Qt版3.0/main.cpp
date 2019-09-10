#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    // 告诉Qt本地系统字符编码
    QTextCodec::setCodecForLocale(codec);
    // 告诉Qt程序中所使用的字符串的字符编码
    QTextCodec::setCodecForCStrings(codec);
    // 告诉Qt外部的字符编码
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);

    Widget w;
    w.show();
    
    return a.exec();
}
