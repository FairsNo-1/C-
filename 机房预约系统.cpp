#include<iostream>
#include<string>
#include<fstream>
#include"Identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

// ȫ�ֺ���-���ڹ���Ա�����Լ��Ĵ���
void managerMenu(Identity*& manager) {
	while (true) {
		// �򿪹���Ա����(���ø��๫���ӿڴ�ӡ������Ϣ��������̬)
		manager->operMenu();

		// ��managerת��ΪManager���µĶ��󣬷����޷����������Ա����ͷ���
		Manager* man = (Manager*)manager;

		// ����ѡ�����
		int select = 0;
		cin >> select;

		// ���й���Ա����һ������˺�
		if (select == 1) {
			// cout << "����˺�" << endl;
			man->addPerson();
		}

		// ���й���Ա���������鿴�˺�
		else if (select == 2) {
			// cout << "�鿴�˺�" << endl;
			man->showPerson();

		}

		// ���й���Ա���������鿴����
		else if (select == 3) {
			// cout << "�鿴����" << endl;
			man->showComputer();
		}

		// ���й���Ա�����ģ����ԤԼ
		else if (select == 4) {
			// cout << "���ԤԼ" << endl;
			man->cleanFile();
		}

		// ע����¼
		else {
			// ��LoginIn���������ָ��ָ����������ڶ������ٵ�
			// ע��֮��Ҫ�ͷŶ���
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}


	}
}

// ȫ�ֺ���-����ѧ�������Լ��Ĵ���
void studentMenu(Identity*& student) {
	while (true) {
		// ��ѧ������(���ø��๫���ӿڴ�ӡ������Ϣ��������̬)
		student->operMenu();

		// ��studentת��ΪStudent���µĶ��󣬷����޷����������Ա����ͷ���
		Student* man = (Student*)student;

		// ����ѡ�����
		int select = 0;
		cin >> select;

		// ����ѧ������һ������ԤԼ
		if (select == 1) {
			man->applyOrder();
		}

		// ����ѧ�����������鿴����ԤԼ
		else if (select == 2) {
			man->showMyOrder();

		}

		// ����ѧ�����������鿴����ԤԼ
		else if (select == 3) {
			man->showAllOrder();
		}

		// ����ѧ�������ģ�ȡ��ԤԼ
		else if (select == 4) {
			// cout << "���ԤԼ" << endl;
			man->cancelOrder();
		}

		// ע����¼
		else {
			// ��LoginIn���������ָ��ָ����������ڶ������ٵ�
			// ע��֮��Ҫ�ͷŶ���
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}


	}
}

// ȫ�ֺ���-������ʦ�����Լ��Ĵ���
void teacherMenu(Identity*& teacher) {
	while (true) {
		// ��ѧ������(���ø��๫���ӿڴ�ӡ������Ϣ��������̬)
		teacher->operMenu();

		// ��studentת��ΪStudent���µĶ��󣬷����޷����������Ա����ͷ���
		Teacher* man = (Teacher*)teacher;

		// ����ѡ�����
		int select = 0;
		cin >> select;

		// ������ʦ����һ���鿴����ԤԼ��Ϣ
		if (select == 1) {
			man->showAllOrder();
		}

		// ������ʦ�����������ԤԼ
		else if (select == 2) {
			man->validOrder();

		}

		// ע����¼
		else {
			// ��LoginIn���������ָ��ָ����������ڶ������ٵ�
			// ע��֮��Ҫ�ͷŶ���
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}


	}
}

// ����ȫ�ֺ���LoginIn�����û��ĵ�¼����
void LoginIn(string fileName, int type) {
	// filename:ָ���û���Ӧ��TXT�ļ����Բ�ѯ�û��ǲ��Ǵ���
	// type��ָ���û�����

	// ����һ������ָ�룬��Ϊ�ʼ��֪���û�����
	Identity* person = NULL;

	// ��ȡָ�����ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// �ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	// �������ڴ���û�������Ϣ�ı���
	int id = 0;
	string name;
	string pwd;

	// ���������type���ж����
	if (type == 1) { // ѧ����¼
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) { // ��ʦ���
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	// ����Ա����Ҫ�ж�

	// �û�ʹ���˺������¼
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	// �û������֤
	if (type == 1) { // ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		// ifs������ȡstudent.txt����Ϣ
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				// ȷ���û���Ϣ���ں����û���ָ�봴���û�����
				person = new Student(id, name, pwd);

				// ����ѧ�����Ӳ˵�
				studentMenu(person);

				return;

			}
		}
	}

	else if (type == 2) { // ��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		// ifs������ȡteacher.txt����Ϣ
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				// ȷ���û���Ϣ���ں����û���ָ�봴���û�����
				person = new Teacher(id, name, pwd);

				// �����ʦ���Ӳ˵�
				teacherMenu(person);

				return;

			}
		}
	}

	else if (type == 3) { // ����Ա�����֤
		string fName;
		string fPwd;
		// ifs������ȡadmin.txt����Ϣ
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				// ȷ���û���Ϣ���ں����û���ָ�봴���û�����
				person = new Manager(name, pwd);

				// �������Ա���Ӳ˵�
				managerMenu(person);

				return;

			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}


int main() {
	// �����ж�ѡ��ı���
	int select = 0;
	while (true) {
		// ԤԼϵͳ������
		cout << "========================== ��ӭ�������ԤԼϵͳ ==========================" << endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t-----------------------------------------\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|              1.ѧ������               |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|              2.��    ʦ               |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|              3.�� �� Ա               |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|              0.��    ��               |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t-----------------------------------------\n";
		cout << "��������ѡ��";

		// ��ȡ�û�����
		cin >> select;
		switch (select) {
		case(1): //ѧ����¼
			LoginIn(STUDENT_FILE, 1);
			break;
		case(2): //��ʦ��¼
			LoginIn(TEACHER_FILE, 2);
			break;
		case(3): //����Ա��¼
			LoginIn(ADMIN_FILE, 3);
			break;
		case(0): //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls"); // ��տ���̨��Ļ
			break;
		}

	}
	system("pause");
	return 0;
}