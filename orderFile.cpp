#include"orderFile.h"

// �ȶ���һ��ȫ�ַָ��-����Ĭ�Ϲ��캯���ڽ�ȡԤԼ��Ϣʱ��
pair<string,string> segData(string & data) {
	// �����ݴ����ֵ�ı���
	string key;
	string val;

	// ��ð��Ϊ��־����Ϣ����ñ�������
	// �磺date:1	�ָ�Ϊkey=date,val=1
	int pos = data.find(":");
	key = data.substr(0, pos);
	val = data.substr(pos + 1, data.size() - pos - 1);
	return make_pair(key, val);
}

// Ĭ�Ϲ��캯��
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	// �ݴ�ԤԼ��Ϣ�ı���
	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	// ��ʼ����Ϣ����Ϊ0
	this->m_size = 0;

	// ��ȡԤԼ��Ϣ
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl; 
		//cout << status << endl;

		// ������ȡ���ַ���
		//(�����date��ȡ����ϢΪdate��1��������Ҫ��1�ָ����)
		// �����õ���Ϣ��map��������
		map<string, string>m;
		// ��ȡ����
		m.insert(segData(date));
		// ��ȡʱ���
		m.insert(segData(interval));
		// ��ȡѧ��id
		m.insert(segData(stuId));
		// ��ȡѧ������
		m.insert(segData(stuName));
		// ��ȡ������
		m.insert(segData(roomId));
		// ��ȡԤԼ״̬
		m.insert(segData(status));

		// ��С��map����m������map����m_orderData��
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
		
	}
	ifs.close();

	// ����map����m_orderData
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++) {
	//	cout << "��" << it->first <<"��ԤԼ��Ϣ����Ϊ��" << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
	//		cout << " key:" << mit->first << " value:" << mit->second << endl;
	//	}
	//}
}

// ����ԤԼ��¼�ĺ���
void OrderFile::updateOrder() {
	// һ����¼��û�У�������
	if (!this->m_size) return;
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++) {
		// �������ж�ȡ���µ�ԤԼ����
		ofs << "date:" << m_orderData[i]["date"] << " ";
		ofs << "interval:" << m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << m_orderData[i]["roomId"] << " ";
		ofs << "status:" << m_orderData[i]["status"] << endl;
	}
	ofs.close();
}