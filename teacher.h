#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include"Identity.h"
#include"orderFile.h"
using namespace std;

class Teacher :public Identity {
public:
	// Ĭ�Ϲ��캯��
	Teacher();

	// �вι��캯��
	Teacher(int empId, string name, string pwd);

	// ��д�����openMenu����-��ȡ��ʦ��Ӧ�Ĵ���
	virtual void operMenu();

	// ��ʦ����һ���鿴����ԤԼ
	void showAllOrder();

	// ��ʦ���ܶ������ԤԼ
	void validOrder();

	// ��ʦ���
	int m_EmpId;

};