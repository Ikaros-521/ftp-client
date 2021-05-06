#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPalette pal = this->palette(); // 设置背景图片
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/icon/bg.png")));
    setPalette(pal);

    download = false;
    upload = false;

    tcpSocket = new QTcpSocket;
    tcpSocket2 = new QTcpSocket;
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connect_success())); // 关联接收连接信号与槽函数
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recv_msg()));
    connect(tcpSocket2,SIGNAL(connected()),this,SLOT(connect_success2()));
    connect(tcpSocket2,SIGNAL(readyRead()),this,SLOT(recv_msg2()));


    strcpy(clientdir,".");
    strcpy(serverdir,".");
    show_clientdir();   // 刚开始就显示客户端目录
}

Widget::~Widget()
{
    delete ui;
}


// 显示客户端的所有文件
void Widget::show_clientdir()
{
    ui->clientdir->clear(); // 清空clientdir
    char cur_dir[1024];
    char* temp = getcwd(cur_dir, sizeof(cur_dir)-1); // 获取当前路径
    if(temp == NULL)
    {
        qDebug("获取当前路径失败");
    }

    qDebug("%s",cur_dir);
    ui->clientdir->setText(cur_dir);    // 设置clientdir的text


    int i = 0;
    DIR* dp = opendir(clientdir);
    for(struct dirent* file = readdir(dp); file!=NULL; file = readdir(dp))
    {
        client_filename[i++] = file->d_name;

        char img[256] = {};

        strcpy(img,":/icon/");
        if(file->d_type == DT_DIR)  // 判断是否是目录文件
        {
            strcat(img,"dir.png");
            //qDebug("dir");
        }
        else
        {
            strcat(img,"file.png");
        }
        QIcon icon(img);
        QListWidgetItem* item = new QListWidgetItem(icon,file->d_name);
        ui->listWidget_c->addItem(item);    // 添加字段
    }
}

// 显示服务端的所有文件
void Widget::show_serverdir()
{
    char list[20] = {};
    sprintf(list,"LIST -al\n");
    tcpSocket->write(list,strlen(list));
    tcpSocket->waitForBytesWritten();
}



// 点击connect按钮
void Widget::on_connect_clicked()
{
    QString _connect = ui->connect->text();
    if(_connect != "连接")
    {
        tcpSocket->close();
        ui->connect->setText("连接");
        ui->serverdir->clear();
        ui->listWidget_s->clear();
        return;
    }

    QString _ip = ui->ip->text();   // 获取控件的text
    QString _port = ui->port->text();

    const char* ip = _ip.toStdString().c_str();
    short port = _port.toShort();

    tcpSocket->connectToHost(ip,port);  // 连接

    char username[60] = {};
    sprintf(username,"USER %s\n",ui->username->text().toStdString().c_str());
    tcpSocket->write(username,strlen(username));    // 发送命令
    tcpSocket->waitForBytesWritten();

    //std::cout << "--" <<username <<"--" << endl;

    char password[60] = {};
    sprintf(password,"PASS %s\n",ui->password->text().toStdString().c_str());
    tcpSocket->write(password,strlen(password));
    tcpSocket->waitForBytesWritten();

    char syst[20] = {};
    sprintf(syst,"SYST\n");
    tcpSocket->write(syst,strlen(syst));
    tcpSocket->waitForBytesWritten();

    char opts[20] = {};
    sprintf(opts,"OPTS UTF8 ON\n");
    tcpSocket->write(opts,strlen(opts));
    tcpSocket->waitForBytesWritten();

    char pwd[20] = {};
    sprintf(pwd,"PWD\n");
    tcpSocket->write(pwd,strlen(pwd));
    tcpSocket->waitForBytesWritten();

    char pasv[20] = {};
    sprintf(pasv,"PASV\n");
    tcpSocket->write(pasv,strlen(pasv));
    tcpSocket->waitForBytesWritten();


    char list[20] = {};
    sprintf(list,"LIST -al\n");
    tcpSocket->write(list,strlen(list));
    tcpSocket->waitForBytesWritten();

    ui->connect->setText("断开");
}

// 初始端口
void Widget::recv_msg()
{
    char buf1[1024] = {};
    tcpSocket->read(buf1,sizeof(buf1));   // 接收数据
    qDebug("%s",buf1);
    bzero(buf,sizeof(buf));
    strcpy(buf,buf1);
    //qDebug("%s",buf);

    // PASV 227
    if(strstr(buf1,"227") != NULL)
    {
        int ip1,ip2,ip3,ip4,port1,port2;    // 解析第二个端口号
        sscanf(strchr(buf,'(')+1,"%d,%d,%d,%d,%d,%d",&ip1,&ip2,&ip3,&ip4,&port1,&port2);

        //std::cout << "port1:" << port1 << ",port2:"<< port2 << endl;

        int port3 = port1*256+port2;
        QString _ip = ui->ip->text();
        const char* ip = _ip.toStdString().c_str();

        tcpSocket2->connectToHost(ip,port3);    // 连接
        //std::cout << "port:"<<port3<<",socket2 connect" << endl;
    }

    // PWD 257
    if(strstr(buf1,"257") != NULL)
    {
        char* str_pwd = (strpbrk(buf1,"\"")+1);  // 获取最后的字符串

        char* str1 = (strchr(str_pwd,'"'));  // 获取最后的字符串
        str1[0] = '\0';

        str_pwd[strlen(str_pwd)] = '\0';  // 用\0替换\n
        QByteArray byte(str_pwd);   // 解决中文乱码问题
        QString dir(byte);
        ui->serverdir->setText(dir);
    }


    // 150 down
    if(strstr(buf1,"150 Opening BINARY mode data connection for") != NULL)
    {
        download = true;
    }
    // 150 up
    if(strstr(buf1,"150 Ok to send data.") != NULL)
    {
        qDebug("收到150");
        upload = true;

        int fd = open(file_name,O_RDONLY);

        qDebug("开始上传");
        char buf3[10] = {};
        while(read(fd,buf3,1) != 0) // 一次上传1字节
        {
            //qDebug("%s",buf3);
            tcpSocket2->write(buf3,strlen(buf3));
            bzero(buf3,sizeof(buf3));
        }

        ::close(fd);

        qDebug("上传完毕");
        upload = false;
        tcpSocket2->close();
    }
    // 226
    if(strstr(buf1,"226 Transfer complete.") != NULL)
    {
        download = false;
        upload = false;
        ui->listWidget_c->clear();  // 清空listWidget_c
        show_clientdir();
    }

    bzero(buf1,sizeof(buf1));

}

// socket1连接成功
void Widget::connect_success()
{
    qDebug("connected()");
}

// tcpSocket2接收到消息
void Widget::recv_msg2()
{
    ui->listWidget_s->clear();  // 清空listWidget_s
    int i = 0, ret = 0, ret2 = 0, num = 0;
    char buf2[10240] = {};
    while(1)
    {
        bzero(buf2, sizeof(buf2));

        ret = tcpSocket2->readLine(buf2, sizeof(buf2));   // 接收数据
        // qDebug("buf2:%s", buf2);
        // qDebug("ret:%d", ret);

        if(ret <= 0)
        {
            if(download == true)
            {
                qDebug("写入完毕");
            }

            qDebug("tcpSocket2->readLine ret:%d", ret);
            break;
        }

        qDebug("len:%d", strlen(buf2));

        // 读取命令LIST -al返回的信息
        if(buf2[1] == 'r' && (buf2[0] == '-' || buf2[0] == 'd') && download == false)
        {
            // qDebug("读取命令LIST -al返回的信息");

            char img[256] = {};

            strcpy(img,":/icon/");
            if(buf2[0] == 'd')  // 判断是否是目录文件
            {
                strcat(img,"dir.png");
                //qDebug("dir");
            }
            else
            {
                strcat(img,"file.png");
            }
            QIcon icon(img);

            char* str = (strrchr(buf2,' ')+1);  // 获取最后的字符串
            str[strlen(str)-2] = '\0';  // 用\0替换\n
            QByteArray byte(str);   // 解决中文乱码问题
            QString filename(byte);
            server_filename[i++] = filename;
            QListWidgetItem* item = new QListWidgetItem(icon,filename);
            ui->listWidget_s->addItem(item);    // 添加字段
        }

        if(download == true)
        {
            // 读取下载的信息,写入文件
            int fd = open(file_name, O_WRONLY|O_CREAT|O_APPEND, 0666);
            // qDebug("fd:%d", fd);
            ret2 = write(fd, buf2, ret);
            if(ret2 == 0)
            {
                // qDebug("ret:%d", ret);
            }

            ::close(fd);
        }

        num++;
        qDebug("num:%d", num);
    }
    tcpSocket2->close();
}

// socket2连接成功
void Widget::connect_success2()
{
    qDebug("connected()");
}

// client的listWidget双击
void Widget::on_listWidget_c_doubleClicked(const QModelIndex &index)
{
    qDebug("%d",index.row());   // 双击的index

    DIR* dp = opendir(".");
    struct dirent* file = readdir(dp);
    QString str;    // 存储文件名
    if(index.row() == 0)
    {
        str = file->d_name;
    }
    for(int i=0; i<index.row(); i++)
    {
        file = readdir(dp);
        if(i == index.row()-1)
        {
            str = file->d_name;
        }
    }

    QByteArray byte = str.toAscii();
    char* filename =  byte.data();   // 文件名
    qDebug("%s",filename);

    int ret = chdir(filename);    // 修改工作目录
    if(ret == -1)
    {
        qDebug("chdir失败");
    }

    ui->listWidget_c->clear();  // 清空
    show_clientdir();

}

// server的listWidget双击
void Widget::on_listWidget_s_doubleClicked(const QModelIndex &index)
{
    qDebug("%d",index.row());   // 双击的index

    QString str;    // 存储文件名
    str = server_filename[index.row()];
    QByteArray byte = str.toAscii();
    char* filename = byte.data();   // 文件名
    qDebug("%s",filename);

    char cwd[40] = {};
    sprintf(cwd,"CWD %s\n",filename);
    tcpSocket->write(cwd,strlen(cwd));
    tcpSocket->waitForBytesWritten();

    char pwd[20] = {};
    sprintf(pwd,"PWD\n");
    tcpSocket->write(pwd,strlen(pwd));
    tcpSocket->waitForBytesWritten();


    char pasv[20] = {};
    sprintf(pasv,"PASV\n");
    tcpSocket->write(pasv,strlen(pasv));
    tcpSocket->waitForBytesWritten();

    char list[20] = {};
    sprintf(list,"LIST -al\n");
    tcpSocket->write(list,strlen(list));
    tcpSocket->waitForBytesWritten();

}

// 点击 << 下载按钮
void Widget::on_left_clicked()
{
    download = true;

    QString str1 = server_filename[ui->listWidget_s->currentRow()]; // 获取选中的文件名
    QByteArray byte = str1.toAscii();
    char* temp = byte.data();
    char filename[60] = {};
    strcpy(file_name,temp); // 复制给全局变量
    strcpy(filename,temp);
    qDebug("%s",filename);

    char typea[40] = {};
    sprintf(typea,"TYPE I\n");
    tcpSocket->write(typea,strlen(typea));
    tcpSocket->waitForBytesWritten();

    char size[60] = {};
    sprintf(size,"SIZE %s\n",filename);
    tcpSocket->write(size,strlen(size));
    tcpSocket->waitForBytesWritten();

    char mdtm[60] = {};
    sprintf(mdtm,"MDTM %s\n",filename);
    tcpSocket->write(mdtm,strlen(mdtm));
    tcpSocket->waitForBytesWritten();

    char pasv[20] = {};
    sprintf(pasv,"PASV\n");
    tcpSocket->write(pasv,strlen(pasv));
    tcpSocket->waitForBytesWritten();


    char retr[60] = {};
    sprintf(retr,"RETR %s\n",filename);
    tcpSocket->write(retr,strlen(retr));
    tcpSocket->waitForBytesWritten();

    char pwd[20] = {};
    sprintf(pwd,"PWD\n");
    tcpSocket->write(pwd,strlen(pwd));
    tcpSocket->waitForBytesWritten();

    char pasv1[20] = {};
    sprintf(pasv1,"PASV\n");
    tcpSocket->write(pasv1,strlen(pasv1));
    tcpSocket->waitForBytesWritten();

    char list[20] = {};
    sprintf(list,"LIST -al\n");
    tcpSocket->write(list,strlen(list));
    tcpSocket->waitForBytesWritten();

}

// 点击 >> 上传按钮
void Widget::on_right_clicked()
{
    QString str1 = client_filename[ui->listWidget_c->currentRow()]; // 获取选中的文件名
    QByteArray byte = str1.toAscii();
    char* temp = byte.data();
    char filename[60] = {};
    strcpy(file_name,temp); // 复制给全局变量
    strcpy(filename,temp);
    qDebug("%s",filename);

    int fd = open(filename,O_RDONLY,0666);
    if(fd < 0)
    {
        qDebug("不是文件，上传失败");
        upload = false;
        return;
    }

    char typea[60] = {};
    sprintf(typea,"TYPE I\n");
    tcpSocket->write(typea,strlen(typea));
    tcpSocket->waitForBytesWritten();

    char size[60] = {};
    sprintf(size,"SIZE %s\n",filename);
    tcpSocket->write(size,strlen(size));
    tcpSocket->waitForBytesWritten();

    char pasv[20] = {};
    sprintf(pasv,"PASV\n");
    tcpSocket->write(pasv,strlen(pasv));
    tcpSocket->waitForBytesWritten();

    char stor[60] = {};
    sprintf(stor,"STOR %s\n",filename);
    tcpSocket->write(stor,strlen(stor));
    tcpSocket->waitForBytesWritten();

    while(upload == true)
    {
        usleep(1000);
        qDebug("while...");
    }

    char mdtm[60] = {};
    sprintf(mdtm,"MDTM %s\n",filename);
    tcpSocket->write(mdtm,strlen(mdtm));
    tcpSocket->waitForBytesWritten();

    char pwd[20] = {};
    sprintf(pwd,"PWD\n");
    tcpSocket->write(pwd,strlen(pwd));
    tcpSocket->waitForBytesWritten();

    char pasv1[20] = {};
    sprintf(pasv1,"PASV\n");
    tcpSocket->write(pasv1,strlen(pasv1));
    tcpSocket->waitForBytesWritten();

    char list[20] = {};
    sprintf(list,"LIST -al\n");
    tcpSocket->write(list,strlen(list));
    tcpSocket->waitForBytesWritten();

    ::close(fd);
}


// 客户端目录回车
void Widget::on_clientdir_returnPressed()
{
    QString str = ui->clientdir->text();    // 存储文件名
    QByteArray byte = str.toAscii();
    char* filename =  byte.data();   // 文件名
    qDebug("%s",filename);

    int ret = chdir(filename);    // 修改工作目录
    if(ret == -1)
    {
        qDebug("chdir失败");
    }

    ui->listWidget_c->clear();  // 清空
    show_clientdir();
}

// 服务端目录回车
void Widget::on_serverdir_returnPressed()
{
    QString str = ui->serverdir->text();    // 存储文件名
    QByteArray byte = str.toAscii();
    char* filename = byte.data();   // 文件名
    qDebug("%s",filename);

    char cwd[40] = {};
    sprintf(cwd,"CWD %s\n",filename);
    tcpSocket->write(cwd,strlen(cwd));
    tcpSocket->waitForBytesWritten();

    char pwd[20] = {};
    sprintf(pwd,"PWD\n");
    tcpSocket->write(pwd,strlen(pwd));
    tcpSocket->waitForBytesWritten();


    char pasv[20] = {};
    sprintf(pasv,"PASV\n");
    tcpSocket->write(pasv,strlen(pasv));
    tcpSocket->waitForBytesWritten();

    char list[20] = {};
    sprintf(list,"LIST -al\n");
    tcpSocket->write(list,strlen(list));
    tcpSocket->waitForBytesWritten();
}
