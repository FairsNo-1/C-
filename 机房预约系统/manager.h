#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;

class Manager:public Identity {
public:
	// Ĭ�Ϲ��캯��
	Manager();

	// �вι��캯��
	Manager(string name, string pwd);

	// ��д�����openMenu����-�򿪹���Ա��Ӧ�Ĵ���
	virtual void operMenu();

	// ����Ա����һ������˺�
	void addPerson();

	// ����Ա���ܶ����鿴�˺�
	void showPerson();

	// ����Ա���������鿴������Ϣ
	void showComputer();

	// ����Ա�����ģ����ԤԼ
	void cleanFile();

	// ��ʼ������
	void initVector();

	// ѧ������(���ڱ���ѧ����Ϣ-��ֹ����Ա���ѧ���˺�ʱ����ѧ������ظ�)
	vector<Student>vStu;

	// ��ʦ����(���ڱ����ʦ��Ϣ-��ֹ����Ա���ѧ���˺�ʱ����ѧ������ظ�)
	vector<Teacher>vTea;

	// ����checkRepeat���ڼ���Ƿ����ظ�id���û���Ϣ
	bool checkRepeat(int id,int type);

	// ��������(���ڱ��������Ϣ)
	vector<ComputerRoom>vCom;

	// ��ȡ������Ϣ����
	void initComputerRoom();
};