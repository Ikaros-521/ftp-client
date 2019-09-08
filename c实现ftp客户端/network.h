#ifndef NETWORK_H
#define NETWORK_H
#include <netinet/in.h>
#include <stdint.h>

typedef struct sockaddr* SP;

typedef struct NetWork
{
	int fd;			// socket描述符
	int type;		// 协议类型 SOCK_STREAM/SOCK_DGRAM
	socklen_t len; 	// 地址长度
	struct sockaddr_in addr; // 通信地址
}NetWork;

// 创建网络连接
NetWork* open_network(char c_or_s,int type,char* ip,uint16_t port);

// TCP的server专用
NetWork* accept_network(NetWork* nw);

// 发送数据
int nsend(NetWork* nw,void* buf,uint32_t len);

// 接收数据
int nrecv(NetWork* nw,void* buf,uint32_t len);

// 关闭网络连接
void close_network(NetWork* nw);

#endif//NETWORK_H
