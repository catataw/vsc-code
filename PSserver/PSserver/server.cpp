#include <WINSOCK2.H>
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib,"ws2_32.lib")
#define bufSize 1024

int main()
{

    //�����׽���
    WORD myVersionRequest;
    WSADATA wsaData;
    myVersionRequest=MAKEWORD(1,1);
	WSAStartup(myVersionRequest,&wsaData);
    //��һ�����׽���
    SOCKET serSocket=socket(AF_INET,SOCK_STREAM,0);//�����˿�ʶ���׽���
	
    //��Ҫ�󶨵Ĳ���
    SOCKADDR_IN addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//ip��ַ
    addr.sin_port=htons(715);//�󶨶˿�

    bind(serSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR));//�����
    listen(serSocket,10);//���еڶ������������ܹ����յ�����������

    SOCKADDR_IN clientsocket;
    int len=sizeof(SOCKADDR);
	SOCKET serConn=accept(serSocket,(SOCKADDR*)&clientsocket,&len);//������ﲻ��accept����conection�Ļ������ͻ᲻�ϵļ���
	char receiveBuf[bufSize];//����

	while (1)
    {
        recv(serConn,receiveBuf,sizeof(receiveBuf),0);

        printf("recv:%s\n",receiveBuf);

    }
	closesocket(serConn);//�ر�
	closesocket(serSocket);
	WSACleanup();//�ͷ���Դ�Ĳ���
    return 1;
}
