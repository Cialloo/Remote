#include "stdafx.h"
#include "function.h"
//ͷ�ļ�
#include <WinSock2.h>
#include <windows.h>

//���ļ�
#pragma comment(lib,"ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

SOCKET s;
int InitSocket() {
	//windows�����⣬��Ҫ��������api����������ĳ�ʼ���ͷ���ʼ��
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//��ʼ������
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}
	//1.socket  ����һ���׽��֣��׽��ֿ������Ϊ�ܵ���pipe��������ں��������ݴ���ӿڣ�
	s = socket(
		AF_INET,//INETЭ���
		SOCK_STREAM,//��ʾʹ�õ���TCPЭ��      SOCK_DGRAM  ��ʾʹ�õ���UDPЭ��
		0
		);//����ֵ�������ǵľ��

	if (s == INVALID_SOCKET)//ʧ��
	{
		return 0;
	}

	//2.bind/listen  ��/��������
	//IP��ַ�������������еļ�ͥ��ַ���ܶ�����Ӧ�ã�
	//�˿ڣ�������������һ��Ӧ�õ����ݣ�ֻ��һ�����0-65535        3389�˿� RDP��Զ�����棩    80�˿� ��ҳ����� http
	//һ��Ӧ���������ʹ�ö��ٸ��˿ڣ�
	//�������ж��ٸ�tcp����
	//ԴIP��Դ�˿�            ��������������������       Ŀ��IP��Ŀ��˿�

	//��ѡһ�������������û��ʹ�õĶ˿���ʹ��
	//sockaddr s;//��������IP�Ͷ˿ڵĽṹ�壬�����ã���Ϊ�ڲ���һ������
	sockaddr_in addr;//�����滻sockaddr�ṹ�壬���ߴ�Сһ��
	int nLength = sizeof(sockaddr_in);
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//�̶���·����д����IP�򱾵�IP
	//                                  "192.168.1.2" ����д����IP��ַ����ʾֻ�ܽ��ܵ���������
	//                                   "127.0.0.1" ֻ���ڱ���ʹ�ã��ͻ��˺ͷ������һ̨�����ϣ����ڱ��ز���
	addr.sin_port = htons(20088);//�˿ں�  �ӣ������ֽ���(��β��ʽ)�ͱ����ֽ���(Сβ��ʽ)  h:host n:network short (����ת����)
	
	return 1;


};