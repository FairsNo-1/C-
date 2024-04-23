#pragma once 
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Identity.h"
#include"globalFile.h"
#include"computerRoom.h"
#include"orderFile.h"
using namespace std;

class Student :public Identity {
public:
	// Ĭ�Ϲ��캯��
	Student();

	// �вι��캯��
	Student(int id, string name, string pwd);

	// ��д�����е�openMenu����-��ѧ����Ӧ�Ĵ���
	virtual void operMenu();

	// ѧ������һ������ԤԼ
	void applyOrder();

	// ѧ�����ܶ����鿴�ҵ�ԤԼ
	void showMyOrder();

	// ѧ�����������鿴���е�ԤԼ
	void showAllOrder();

	// ѧ�������ģ�ȡ��ԤԼ
	void cancelOrder();

	// ѧ��ѧ��
	int m_Id;

	// ��������
	vector<ComputerRoom>vCom;

	// ����������ʼ��
	void initvCom();

};