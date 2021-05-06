#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "network.h"

// 创建网络连接
NetWork* open_network(char c_or_s,int type,char* ip,uint16_t port)
{
	// 在堆上创建NetWork结构
	NetWork* nw = malloc(sizeof(NetWork));
	if(NULL == nw)
	{
		perror("network malloc");
		return NULL;
	}

	// 创建socket对象
	nw->fd = socket(AF_INET,type,0);
	if(0 > nw->fd)
	{
		perror("network socket");
		free(nw);
		return NULL;
	}

	// 准备通信地址
	nw->addr.sin_family = AF_INET;
	nw->addr.sin_port = htons(port);
	nw->addr.sin_addr.s_addr = inet_addr(ip);
	nw->len = sizeof(nw->addr);
	nw->type = type;

	if('s' == c_or_s)
	{
		if(bind(nw->fd,(SP)&nw->addr,nw->len))
		{
			perror("network bind");
			free(nw);
			return NULL;
		}

		if(SOCK_STREAM == type && listen(nw->fd,50))
		{
			perror("network listen");
			free(nw);
			return NULL;
		}
	}
	else if(SOCK_STREAM == type)
	{
		if(connect(nw->fd,(SP)&nw->addr,nw->len))
		{
			perror("network connect");
			free(nw);
			return NULL;
		}	
	}

	return nw;
}

// TCP的server专用
NetWork* accept_network(NetWork* nw)
{
	if(SOCK_STREAM != nw->type)
	{
		printf("network accept socket type error!\n");
		return NULL;
	}

	NetWork* clinw = malloc(sizeof(NetWork));
	if(NULL == clinw)
	{
		perror("network accept malloc");
		return NULL;
	}
	
	clinw->type = nw->type;
	clinw->len = sizeof(clinw->addr);
	clinw->fd = accept(nw->fd,(SP)&clinw->addr,&clinw->len);
	if(0 > clinw->fd)
	{
		perror("network accept");
		free(clinw);
		return NULL;
	}

	return clinw;
}

// 发送数据
int nsend(NetWork* nw,void* buf,uint32_t len)
{
	if(SOCK_STREAM == nw->type)
	{
		return send(nw->fd,buf,len,0);
	}
	else if(SOCK_DGRAM == nw->type)
	{
		return sendto(nw->fd,buf,len,0,(SP)&nw->addr,nw->len);
	}
	return -1;
}

// 接收数据
int nrecv(NetWork* nw,void* buf,uint32_t len)
{
	if(SOCK_STREAM == nw->type)
	{
		return recv(nw->fd,buf,len,0);
	}
	else if(SOCK_DGRAM == nw->type)
	{
		return recvfrom(nw->fd,buf,len,0,(SP)&nw->addr,&nw->len);
	}
	return -1;
}

// 关闭网络连接
void close_network(NetWork* nw)
{
	if(close(nw->fd))
	{
		perror("network close");
	}
	free(nw);
}
