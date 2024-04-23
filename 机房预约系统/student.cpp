#include"student.h"

// Ĭ�Ϲ��캯��
Student::Student() {

}

// �вι��캯��
Student::Student(int id, string name, string pwd) {
	// ��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ����������-����ԤԼ
	this->initvCom();
}

// ��д�����е�openMenu����-��ѧ����Ӧ�Ĵ���
void Student::operMenu() {
	cout << "��ӭѧ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-----------------------------------------\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             1.����ԤԼ                |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             2.�鿴�ҵ�ԤԼ            |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             3.�鿴����ԤԼ            |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             4.ȡ��ԤԼ                |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|             0.ע����¼                |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t-----------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}

// ѧ������һ������ԤԼ
void Student::applyOrder() {
	int date = 0; // ���������
	int interval = 0; // �����ʱ���
	int room = 0; // ����Ļ���

	// ȷ������ԤԼ������
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "��ѡ����ҪԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "��������������������룡" << endl;
	}

	// ȷ������ԤԼ��ʱ���
	cout << "����������Ҫ�����ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true) {
		cin >> interval;
		if (interval == 1 || interval == 2) {
			break;
		}
		cout << "��������������������룡" << endl;
	}

	//ȷ������ԤԼ�Ļ���
	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "��������������������룡" << endl;
	}

	// ������Ϣ��������ȷ����ʾԤԼ�ɹ�
	cout << "ԤԼ�ɹ�������У�" << endl;

	// ��ԤԼ��Ϣд��order.txt��
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");

}

// ѧ�����ܶ����鿴�ҵ�ԤԼ
void Student::showMyOrder() {
	// ʵ����OrderFile���󣬷����ԤԼ���ݽ��в���
	OrderFile of; 
	if (!of.m_size) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ���������ҵ���thisѧ����idƥ��ļ�¼
	for (int i = 0; i < of.m_size; i++) {
		// .cstr()�������Խ�stringǿתΪconst char*����
		// atoi()�������Խ�char*ǿתΪint����
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id){
			cout << "ԤԼʱ�䣺����" << of.m_orderData[i]["date"] << " ";
			string interval = "����";
			if (of.m_orderData[i]["interval"] == "1") {
				interval = "����";
			}
			cout << "ԤԼʱ��Σ�" << interval << " ";
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
	}
	system("pause");
	system("cls");

}

// ѧ�����������鿴���е�ԤԼ
void Student::showAllOrder() {
	// ʵ����OrderFile���󣬷����ԤԼ���ݽ��в���
	OrderFile of;
	if (!of.m_size) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ���������ҵ���thisѧ����idƥ��ļ�¼
	for (int i = 0; i < of.m_size; i++) {
		cout << i << ".";
		cout << "ԤԼʱ�䣺����" << of.m_orderData[i]["date"] << " ";
		cout << "ԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1"?"����":"����") << " ";
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

// ѧ�������ģ�ȡ��ԤԼ
void Student::cancelOrder() {
	// ʵ����OrderFile���󣬷����ԤԼ���ݽ��в���
	OrderFile of;
	if (!of.m_size) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ���ڼ�¼�ɲ�������Ϣ�������ı���
	int index = 1;
	// ���ڱ���ɲ�����Ϣ��map�е�����������
	vector<int>v;

	cout << "����ȡ����ԤԼ���£�" << endl;
	for (int i = 0; i < of.m_size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				// ��ȡ����Ϣ��map�е�����
				v.push_back(i);

				// ��ʾ�ǵڼ������Բ�������Ϣ
				cout << index++ << ".";
				cout << "ԤԼʱ�䣺����" << of.m_orderData[i]["date"] << " ";
				cout << "ԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "ԤԼ������" << of.m_orderData[i]["roomId"] << " ";
				string status = "״̬��";
				if (of.m_orderData[i]["status"] == "1") {
					status += "����С�����";
				}
				if (of.m_orderData[i]["status"] == "2") {
					status += "���ͨ����ԤԼ�ɹ���";
				}
				cout << status << endl;
			}
		}
	}
	
	// ֻ������к����ͨ����ԤԼ�ǿ���ȡ����
	cout << "������Ҫȡ����ԤԼ������0������" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (!select) break;
			else{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ��" << endl;
				break;
			}
		}
		else {
			cout << "�����������������룺" << endl;
		}
	}
	system("pause");
	system("cls");

}

// ����������ʼ��
void Student::initvCom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in); 

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	ifs.close();
}
