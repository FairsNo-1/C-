#pragma once // ��ֹͷ�ļ��ظ�
#include<iostream>
#include<string>
using namespace std;

// ������-Identity�����-������Ϊ������ݵĻ���-����������Ĺ���
class Identity {
public:

	// ÿ����ݶ��и��Ե���ݲ˵�
	virtual void operMenu() = 0;

	// ÿ����ݶ����Լ����û���������
	string m_Name;
	string m_Pwd;
};