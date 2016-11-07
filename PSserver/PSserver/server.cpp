#include <WINSOCK2.H>
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib,"ws2_32.lib")
#define bufSize 1024

int main()
{

    //创建套接字
    WORD myVersionRequest;
    WSADATA wsaData;
    myVersionRequest=MAKEWORD(1,1);
	WSAStartup(myVersionRequest,&wsaData);
    //进一步绑定套接字
    SOCKET serSocket=socket(AF_INET,SOCK_STREAM,0);//创建了可识别套接字
	
    //需要绑定的参数
    SOCKADDR_IN addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//ip地址
    addr.sin_port=htons(715);//绑定端口

    bind(serSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR));//绑定完成
    listen(serSocket,10);//其中第二个参数代表能够接收的最多的连接数

    SOCKADDR_IN clientsocket;
    int len=sizeof(SOCKADDR);
	SOCKET serConn=accept(serSocket,(SOCKADDR*)&clientsocket,&len);//如果这里不是accept而是conection的话。。就会不断的监听
	char receiveBuf[bufSize];//接收

	while (1)
    {
        recv(serConn,receiveBuf,sizeof(receiveBuf),0);

        printf("recv:%s\n",receiveBuf);

    }
	closesocket(serConn);//关闭
	closesocket(serSocket);
	WSACleanup();//释放资源的操作
    return 1;
}
