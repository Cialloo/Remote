#include "stdafx.h"
#include "function.h"
//头文件
#include <WinSock2.h>
#include <windows.h>

//库文件
#pragma comment(lib,"ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

SOCKET s;
int InitSocket() {
	//windows很特殊，需要单独调用api来进行网络的初始化和反初始化
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//初始化操作
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}
	//1.socket  创建一个套接字（套接字可以理解为管道的pipe句柄，用于后续的数据传输接口）
	s = socket(
		AF_INET,//INET协议簇
		SOCK_STREAM,//表示使用的是TCP协议      SOCK_DGRAM  表示使用的是UDP协议
		0
		);//返回值就是我们的句柄

	if (s == INVALID_SOCKET)//失败
	{
		return 0;
	}

	//2.bind/listen  绑定/监听窗口
	//IP地址：类似于网络中的家庭地址（很多网络应用）
	//端口：用于区分是哪一个应用的数据，只是一个编号0-65535        3389端口 RDP（远程桌面）    80端口 网页浏览器 http
	//一个应用软件可以使用多少个端口？
	//看这里有多少个tcp连接
	//源IP：源端口            ——————————       目标IP：目标端口

	//挑选一个本机其他软件没有使用的端口来使用
	//sockaddr s;//用于描述IP和端口的结构体，不好用，因为内部是一个数组
	sockaddr_in addr;//用于替换sockaddr结构体，两者大小一致
	int nLength = sizeof(sockaddr_in);
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//固定套路，填写外网IP或本地IP
	//                                  "192.168.1.2" 这里写本机IP地址，表示只能接受到它的请求
	//                                   "127.0.0.1" 只能在本机使用，客户端和服务端在一台电脑上，用于本地测试
	addr.sin_port = htons(20088);//端口号  坑：网络字节序(大尾方式)和本地字节序(小尾方式)  h:host n:network short (本地转网络)
	
	return 1;


};