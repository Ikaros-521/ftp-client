# FTP客户端（有无界面2版本）
FTP客户端（有无界面2版本）,分别用Qt和C++、C语言实现。

Qt使用的是Qt4，Qt Creator Documentation 2.4.1。


#### 使用说明

Qt版（有界面）,2.0增加了目录回车跳转功能，3.0优化了整体代码。但有大文件传输问题

可以直接运行ftp，或导入Qt Creator编译运行

—————————————————————————————————————————————

C语言无界面版

终端执行gcc ftpclient.c network.c -o ftp编译

终端输入 ./ftp 你的ip地址

## 效果图

#### Qt版3.0
![在这里插入图片描述](https://images.gitee.com/uploads/images/2020/0108/152524_0d0f55ed_5140590.png)

#### 无界面版
![在这里插入图片描述](https://images.gitee.com/uploads/images/2020/0108/154954_51b1999f_5140590.png)
