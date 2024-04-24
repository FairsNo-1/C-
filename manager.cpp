#include<algorithm>
#include"manager.h"
#include"globalFile.h"

// Ĭ�Ϲ��캯��
Manager::Manager() {

}

// �вι��캯��
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ������
	this->initVector();

	// ��ʼ��������Ϣ
	this->initComputerRoom();
}

// ��д�����openMenu����-�򿪹���Ա��Ӧ�Ĵ���
void Manager::operMenu() {
	cout << "��ӭ����Ա" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-----------------------------------------\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              1.����˺�               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              2.�鿴�˺�               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              3.�鿴����               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              4.���ԤԼ               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              0.ע����¼               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t-----------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";

}

// ����Ա����һ������˺�
void Manager::addPerson() {
	// ��ʾ��Ϣ
	cout << "��������Ҫ��ӵ��˺ŵ����ͣ�" << endl;
	cout << "1.���ѧ���˺�" << endl;
	cout << "2.�����ʦ�˺�" << endl;

	string tip; // ��ʾ��Ϣ
	string errorTip;
	string filename;  // �����������ѡ���ļ�
	ofstream ofs; 

	int select = 0;
	cin >> select;
	if (select == 1) {
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
		filename = STUDENT_FILE;
	}
	else if (select == 2) {
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룡";
		filename = TEACHER_FILE;
	}
	else {
		cout << "�����������������������룺" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ���ļ���׷��(append)�ķ�ʽд(out)�ļ�
	ofs.open(filename, ios::out | ios::app);

	// ��������ݴ���Ҫ��ӵ��˺�
	int id;
	string name;
	string pwd;

	cout << tip;


	// ���id�Ƿ��Ѿ��ظ�
	while (true) {
		cin >> id;
		if (this->checkRepeat(id, select)) {
			cout << errorTip << endl;
			cout << tip << endl;
		}
		else {
			break;
		}
	}

	cout << "�������û�����";
	cin >> name;

	cout << "���������룺";
	cin >> pwd;

	// ��Ӳ���
	ofs << id << " " << name << " " << pwd << " " << endl; 
	cout << "����˺ųɹ���";

	system("pause");
	system("cls");

	ofs.close();

	// ��ֹһ������Ӷ���û���Ϣʱ��ⲻ���ظ�-ÿ���һ���û���Ϣ��ˢ��һ������
	this->initVector();
}

// ����Ա���ܶ����鿴�˺�

// ��ӡѧ����Ϣ-ΪshowPerson����
void printStudent(Student& s) {
	cout << "ѧ�ţ�" << s.m_Id << "������" << s.m_Name << "���룺" << s.m_Pwd << endl;
}
// ��ӡ��ʦ��Ϣ-ΪshowPerson����
void printTeacher(Teacher& t) {
	cout << "ְ���ţ�" << t.m_EmpId << "������" << t.m_Name << "���룺" << t.m_Pwd << endl;
}

void Manager::showPerson() {
	cout << "��ѡ��鿴����" << endl;
	cout << "1.�鿴ѧ����Ϣ" << endl;
	cout << "2.�鿴��ʦ��Ϣ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "ѧ������Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2) {
		cout << "��ʦ����Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	else {
		cout << "���������Ҫ�������������룡" << endl;
	}
	system("pause");
	system("cls");
}


// ����Ա���������鿴������Ϣ
void Manager::showComputer() {
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "����id��" << it->m_ComId << "�������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

// ����Ա�����ģ����ԤԼ
void Manager::cleanFile() {
	ofstream ofs;
	// trunc�ķ�ʽ��-�ļ�������������´���
	ofs.open(ORDER_FILE, ios::trunc);

	cout << "����ɹ���" << endl;
	ofs.close();
	system("pause");
	system("cls");
}

// ��ʼ������
void Manager::initVector() {
	// ���ѧ���ͽ�ʦ����
	vStu.clear();
	vTea.clear();

	// ��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "���ļ�ʧ��!" << endl;
		return;
	}

	// ��ȡ�ļ��е�ѧ����Ϣ��д������
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << vStu.size() << endl;
	ifs.close();

	// ��ȡ��ʦ�ļ��е���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "���ļ�ʧ��!" << endl;
		return;
	}

	// ��ȡ�ļ��е���ʦ��Ϣ��д������
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ��" << vTea.size() << endl;
	ifs.close();

}

// ����checkRepeat���ڼ���Ƿ����ظ�id���û���Ϣ
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else if (type == 2) {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}

// ��ʼ��������Ϣ����
void Manager::initComputerRoom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	ifs.close();
	cout << "����������Ϊ��" << vCom.size() << endl;
}