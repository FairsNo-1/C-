#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include"globalFile.h"
using namespace std;

class OrderFile {
public:
	// Ĭ�Ϲ��캯��
	OrderFile();

	// ����ԤԼ��¼�ĺ���
	void updateOrder();

	// ��¼ԤԼ����
	int m_size;

	// ��¼ԤԼ��Ϣ������
	// (����ʹ��map��������Ƕ��-�ڲ�map�������ڱ����ض�һ��ԤԼ��Ϣ�����map����������֯���е�ԤԼ��Ϣ)
	map<int, map<string, string>>m_orderData;
	//   |          |       |
	//   |          |       |
	//��¼����  ÿ���о���ļ�ֵ��Ϣ(��stuName,����)
};