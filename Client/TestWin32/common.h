#pragma once

//����һЩ�����Ľṹ���

//����һЩ�꣬����ʾ���ľ��崦������
///cmd��������
#define PACKET_REQ_CMD 10001//REQ requset���� CMD ��ʾcmd������������ �ͻ��ˡ���>�����
#define PACKET_PLY_CMD 10002//RLY relpy�ظ�   CMD ��ʾcmd���ͻظ����� ����ˡ���>�ͻ���
///������������
#define PACKET_REQ_KEYBOARD 20001//REQ requset���� ���� ��ʾ���������������� �ͻ��ˡ���>�����
#define PACKET_PLY_KEYBOARD 20002//RLY relpy�ظ�   ���� ��ʾ�������ͻظ����� ����ˡ���>�ͻ���

//����  ��1�ֽڶ���
#pragma pack(push)//��ʾԭ�еĽṹ�� ����ֵ ѹջ
#pragma pack(1)
struct MyPacket{
	unsigned int Type;//��ʾ������
	unsigned int lengt;//��ʾ����
	char data[1];//����һ��1�ֽڵ�����   ��������
};
#pragma pack(pop)//��ʾԭ�еĽṹ�� ����ֵ ��ջ