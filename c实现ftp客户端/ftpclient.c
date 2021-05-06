#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "network.h"

NetWork* nw;
NetWork* data_nw;
int list_len = 0;
char buf[256] = {};

typedef struct List
{
	char filename[40];
}List;

void ex(void);
void must(void);
void ls(void);
void cd_to(char* cd);
void download(char* get);
void upload(char* put);

int main(int argc,char* argv[])
{	

	char c_ip[40] = {};
	strcpy(c_ip,argv[1]);

	nw = open_network('c',SOCK_STREAM,c_ip,21);
	if(NULL == nw)
	{
		printf("open network socket null!\n");
		return -1;
	}

	printf("Connected to %s.\n",c_ip);

	nrecv(nw,buf,sizeof(buf));
	printf("%s",buf);//220

	for(;;)
	{
		char user[20] = {};
		printf("Name (%s:zhizhen):",c_ip);
		gets(user);

		sprintf(buf,"USER %s\n",user);
		nsend(nw,buf,strlen(buf));

		bzero(buf,sizeof(buf));
		nrecv(nw,buf,sizeof(buf));
		printf("%s",buf);//331

		char pw[20] = {};
		printf("Password:");
		struct termios old, new; 
		tcgetattr(0, &old);  // 获取终端属性
		new = old;	
		new.c_lflag &= ~(ECHO | ICANON);// 不使用标准的输出，不显示字符。 
 		tcsetattr(0, TCSANOW, &new);// 设置终端新的属性
		gets(pw);								
		tcsetattr(0, TCSANOW, &old);

		sprintf(buf,"PASS %s\n",pw);
		nsend(nw,buf,strlen(buf));//pw

		bzero(buf,sizeof(buf));
		nrecv(nw,buf,sizeof(buf));
		printf("\n%s",buf);//230
		if(strstr(buf,"530") == NULL)
		{
			break;
		}
	}

	printf("Remote system type is UNIX.\n");
	printf("Using binary mode to transfer files.\n");
	
	ex();
	must();
	char cmd[40] = {};
	while(1)
	{

		printf("ftp> ");
		gets(cmd);
		if(strcmp(cmd,"bye")==0)
		{
			break;
		}
		if(strcmp(cmd,"ls")==0)
		{
			ls();
		}

		char *cmd1 = malloc(20);
		char *path = malloc(100);
		sscanf(cmd,"%s %s",cmd1,path);
		if(strcmp(cmd1,"cd") == 0)
		{
			cd_to(path);
		}

		if(strcmp(cmd1,"get") == 0)
		{
			download(path);
		}

		if(strcmp(cmd1,"put") == 0)
		{
			upload(path);
		}
		
		//must();
	}

	printf("221 Goodbye.\n");//221


}

void ex(void)
{
	sprintf(buf,"SYST\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//puts(buf);

	sprintf(buf,"OPTS UTF8 ON\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//puts(buf);
	
}

void must(void)
{
	sprintf(buf,"PWD\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//puts(buf);//257

	sprintf(buf,"PASV\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//puts(buf);//227

	unsigned char ip1,ip2,ip3,ip4,port1,port2;
	sscanf(strchr(buf,'(')+1,"%hhu,%hhu,%hhu,%hhu,%hhu,%hhu",&ip1,&ip2,&ip3,&ip4,&port1,&port2);
	sprintf(buf,"%hhu.%hhu.%hhu.%hhu",ip1,ip2,ip3,ip4);
	

	NetWork* data_nw = open_network('c',SOCK_STREAM,buf,port1*256+port2);
	//printf("connect success fd = %d\n",data_nw->fd);
	
	sprintf(buf,"LIST -al\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//printf("%s",buf);//150
	
	int ret = 0;
	bzero(buf,sizeof(buf));
	while(ret = nrecv(data_nw,buf,sizeof(buf)))
	{
		//printf("%s",buf);
		bzero(buf,sizeof(buf));
	}
	close_network(data_nw);

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//printf("%s",buf);//226
}

void ls(void)
{
	sprintf(buf,"PWD\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//puts(buf);//257

	sprintf(buf,"PASV\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	//puts(buf);//227

	unsigned char ip1,ip2,ip3,ip4,port1,port2;
	sscanf(strchr(buf,'(')+1,"%hhu,%hhu,%hhu,%hhu,%hhu,%hhu",&ip1,&ip2,&ip3,&ip4,&port1,&port2);
	sprintf(buf,"%hhu.%hhu.%hhu.%hhu",ip1,ip2,ip3,ip4);
	

	NetWork* data_nw = open_network('c',SOCK_STREAM,buf,port1*256+port2);
	//printf("connect success fd = %d\n",data_nw->fd);
	
	sprintf(buf,"LIST -al\n");
	nsend(nw,buf,strlen(buf));

	printf("200 PORT command successful. Consider using PASV.\n");

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	printf("%s",buf);//150
	
	int ret = 0;
	bzero(buf,sizeof(buf));
	while(ret = nrecv(data_nw,buf,sizeof(buf)))
	{
		printf("%s",buf);
		bzero(buf,sizeof(buf));
	}
	close_network(data_nw);

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	printf("%s",buf);//226
}

void cd_to(char* cd)
{
	char *dir = cd;
	if(strcmp(dir,"..")==0)
	{
		sprintf(buf,"CDUP %s\n",dir);
	}
	else
	{
		sprintf(buf,"CWD %s\n",dir);
	}
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	printf("%s",buf);//250
}

void download(char* get)
{
	char *filename = get;
	sprintf(buf,"TYPE A\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

	sprintf(buf,"SIZE %s\n",filename);
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

	sprintf(buf,"MDTM %s\n",filename);
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

	sprintf(buf,"PASV\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);
	
	unsigned char ip1,ip2,ip3,ip4,port1,port2;
	sscanf(strchr(buf,'(')+1,"%hhu,%hhu,%hhu,%hhu,%hhu,%hhu",&ip1,&ip2,&ip3,&ip4,&port1,&port2);
	sprintf(buf,"%hhu.%hhu.%hhu.%hhu",ip1,ip2,ip3,ip4);

	data_nw = open_network('c',SOCK_STREAM,buf,port1*256+port2);
	printf("connect success fd = %d\n",data_nw->fd);

	sprintf(buf,"RETR %s\n",filename);
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

	int fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(0 > fd)
	{
		perror("open");
		return;
	}
	int ret = 0;
	while(ret = nrecv(data_nw,buf,sizeof(buf)))
	{
		write(fd,buf,ret);
	}
	close(fd);
}

void upload(char* put)
{
	char *filename = put;

	sprintf(buf,"TYPE A\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

	sprintf(buf,"SIZE %s\n",filename);
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

	sprintf(buf,"PASV\n");
	nsend(nw,buf,strlen(buf));

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

	unsigned char ip1,ip2,ip3,ip4,port1,port2;
	sscanf(strchr(buf,'(')+1,"%hhu,%hhu,%hhu,%hhu,%hhu,%hhu",&ip1,&ip2,&ip3,&ip4,&port1,&port2);
	sprintf(buf,"%hhu.%hhu.%hhu.%hhu",ip1,ip2,ip3,ip4);

	data_nw = open_network('c',SOCK_STREAM,buf,port1*256+port2);
	printf("connect success fd = %d\n",data_nw->fd);

	sprintf(buf,"STOR %s\n",filename);
	nsend(nw,buf,strlen(buf));

	int fd = open(filename,O_RDONLY,0644);
	if(0 > fd)
	{
		perror("open");
		return;
	}
	int ret = 0;
	bzero(buf,sizeof(buf));
	while(read(fd,buf,1))
	{
		nsend(data_nw,buf,strlen(buf));
		bzero(buf,sizeof(buf));
	}

	close_network(data_nw);

	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	printf("%s",buf);// 150-226
	
	sprintf(buf,"MDTM %s\n",filename);
	nsend(nw,buf,strlen(buf));


	bzero(buf,sizeof(buf));
	nrecv(nw,buf,sizeof(buf));
	puts(buf);

}
