#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QModelIndex>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    char clientdir[256];    // 客户端路径
    char serverdir[256];    // 服务端路径
    char buf[256];  // 临时字符串
    QTcpSocket* tcpSocket;  // socket1
    QTcpSocket* tcpSocket2; // socket2
    bool download;  // 下载标记
    bool upload;    // 上传标记
    char file_name[256];    // 文件名
    QString client_filename[1024];  // 客户端获取到的文件名
    QString server_filename[1024];  // 服务端获取到的文件名
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void show_clientdir();  // 显示客户端目录
    void show_serverdir();  // 显示服务端目录
private slots:
    void connect_success(); // 连接成功
    void recv_msg();    // 接收消息
    void connect_success2();
    void recv_msg2();

    void on_listWidget_c_doubleClicked(const QModelIndex &index);   // 双击
    void on_connect_clicked();  // 单击connect

    void on_listWidget_s_doubleClicked(const QModelIndex &index);   // 双击

    void on_left_clicked(); // 下载

    void on_right_clicked(); // 上传

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
