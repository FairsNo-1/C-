#include"teacher.h"

// Ĭ�Ϲ��캯��
Teacher::Teacher() {

}

// �вι��캯��
Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// ��д�����openMenu����-��ȡ��ʦ��Ӧ�Ĵ���
void Teacher::operMenu() {
	cout << "��ӭ��ʦ" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-----------------------------------------\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             1.�鿴����ԤԼ            |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             2.���ԤԼ                |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             0.ע����¼                |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t-----------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}

// ��ʦ����һ���鿴����ԤԼ
void Teacher::showAllOrder() {
	OrderFile of;
	if (!of.m_size) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++) {
		cout << i + 1 << ".";
		cout << "ԤԼʱ�䣺����" << of.m_orderData[i]["date"] << " ";
		cout << "ԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ԤԼѧ��ѧ�ţ�" << of.m_orderData[i]["stuId"] << " ";
		cout << "ԤԼѧ��������" << of.m_orderData[i]["stuName"] << " ";
		cout << "ԤԼ������" << of.m_orderData[i]["roomId"] << "�Ż��� ";
		string status = "״̬��";

		// 1-�����	2-���ͨ��	-1-��˲�ͨ��	0-�û���ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1") {
			status += "����С�����";
		}
		if (of.m_orderData[i]["status"] == "2") {
			status += "���ͨ����ԤԼ�ɹ���";
		}
		if (of.m_orderData[i]["status"] == "-1") {
			status += "���δͨ����ԤԼʧ�ܣ�";
		}
		if (of.m_orderData[i]["status"] == "0") {
			status += "�û���ȡ��ԤԼ";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

// ��ʦ���ܶ������ԤԼ
void Teacher::validOrder() {
	// ʵ����OrderFile���󣬷����ԤԼ���ݽ��в���
	OrderFile of;
	if (!of.m_size) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ���ڼ�¼�ɲ�������Ϣ�������ı���
	int index = 0;
	// ���ڱ���ɲ�����Ϣ��map�е�����������
	vector<int>v;

	cout << "������˵�ԤԼ���£�" << endl;
	for (int i = 0; i < of.m_size; i++) {
		if (of.m_orderData[i]["status"]=="1") {
			v.push_back(i);
			cout << ++index << ".";
			cout << "ԤԼʱ�䣺����" << of.m_orderData[i]["date"] << " ";
			cout << "ԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ��ѧ�ţ�" << of.m_orderData[i]["stuId"] << " ";
			cout << "ѧ��������" << of.m_orderData[i]["stuName"] << " ";
			cout << "ԤԼ������" << of.m_orderData[i]["roomId"] << " ";
			cout << "״̬�������" << endl;
		}
	}

	cout << "��ѡ��Ҫ��˵�ԤԼ��¼������0������" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) break;
			else {
				cout << "��������˽����" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else if (ret == 2) {
					of.m_orderData[v[select-1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		else {
			cout << "�����������������룡" << endl;
		}
	}
	system("pause");
	system("cls");

}