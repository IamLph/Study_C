#include"speechManager.h"

SpeechManger::SpeechManger() {
	// ��ʼ��
	this->initSpeech();
	// ѡ�ֳ�ʼ��
	this->createSpeaker();
}
SpeechManger::~SpeechManger() {

}
void SpeechManger::show_Menu() {
	cout << "********************************" << endl;
	cout << "******** $.��ӭ�μӱ��� ********" << endl;
	cout << "******** 1.��ʼ�ݽ����� ********" << endl;
	cout << "******** 2.�鿴�����¼ ********" << endl;
	cout << "******** 3.��ձ�����¼ ********" << endl;
	cout << "******** 0.�˳��������� ********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}
void SpeechManger::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManger::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	// ��������
	this->Index = 1;
	// ��ʼ����¼����
	this->m_Record.clear();
}
void SpeechManger::createSpeaker() {
	string NameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < NameSeed.size(); i++) {
		string name = "ѡ��";
		name += NameSeed[i];
		Speaker sp;
		sp.Name = name;
		for (int j = 0; j < 2; j++) {
			sp.Score[j] = 0;
		}
		// 12��ѡ�ֵı��
		this->v1.push_back(i + 10001);

		// ѡ�ֱ���Լ�ѡ�� map���
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManger::speechDraw() {
	cout << "��<< " << this->Index << " >> �ֱ������ڽ��г�ǩ" << endl;
	cout << "--------------" << endl;
	cout << "��ǩ˳������:" << endl;
	if (this->Index == 1) {
		// ������� ϴ���㷨
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;
	system("pause");
	cout << endl;
}
void SpeechManger::speechContest() {
	cout << "��<< " << this->Index << "  >>�ֱ�����ʽ��ʼ:" << endl;
	// ��ʱ�������������ѡ�ֱ�� ���ҽ�������
	multimap<double, int, greater<double>> groupScore;
	// ��¼���� 6��1��
	int num = 0;
	vector<int>v_Src;
	if (this->Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	// ��������ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;

		// ���
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			// 600~1000
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		// ����
		sort(d.begin(), d.end(), greater<double>());
		// ȥ����߷�����ͷ�
		d.pop_front();
		d.pop_back();

		// ��ȡ�ܷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		// ƽ����
		double avg = sum / (double)d.size();
		// ÿ���˵�ƽ����
		this->m_Speaker[*it].Score[this->Index - 1] = avg;
		// ����һ�� ��ʱ�������� *itΪѡ�ֱ��
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С���������:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				// m_Speaker map���� ��ű�� �Լ� ����ѡ��Speaker
				cout << "���: " << it->second <<
					"  ����:" << this->m_Speaker[it->second].Name <<
					"  �ɼ�:" << this->m_Speaker[it->second].Score[this->Index - 1] << endl;
			}
			int count = 0;
			// ȡǰ���� �ŵ�v2�������� ��ŵ��ǳ�Ա���
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); 
				it != groupScore.end() && count < 3; it++,count++) {
				if (this->Index == 1) {
					v2.push_back((*it).second);
				}
				else {
					vVictory.push_back((*it).second);
				}
			}
			// С���������
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "��" << this->Index << "���������" << endl;
	system("pause");

}

void SpeechManger::showScore() {
	cout << "---------------��<<  " << this->Index << "  >>����ѡ����Ϣ����" << endl;
	
	vector<int>v;
	if (this->Index == 1) {
		// ��һ�־͸���v2����Ϣ
		v = v2;
	}
	else {
		// �ڶ��־���ʾʤ������Ϣ
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ��:" << *it <<
			"\t����:" << m_Speaker[*it].Name <<
			"\t�÷�:" << m_Speaker[*it].Score[this->Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}
void SpeechManger::saveRecord() {
	ofstream ofs;
	// ���ļ���ʽ ������׷�ӵķ�ʽ
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	// �ļ�������
	this->fileIsEmpty = false;
}
void SpeechManger::startSpeech() {
	// ��һ�ֱ���
	// 1.��ǩ
	this->speechDraw();
	// 2.����
	this->speechContest();
	// 3.��ʾ�������
	this->showScore();
	// �ڶ��ֱ���
	this->Index++;
	// 1.��ǩ
	this->speechDraw();
	// 2.����
	this->speechContest();
	// 3.��ʾ�������
	this->showScore();
	// 4.����������ļ�
	this->saveRecord();
	// ���ñ���
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "������ϣ�" << endl;
	system("pause");
	system("cls");
};
void SpeechManger::loadRecord() {
	// ������ ��ȡ�ļ�
	ifstream ifs("speech.csv", ios::in);
	// �����ж��Ƿ�򿪳ɹ�
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}else{
		char ch;
		ifs >> ch;
		// �ļ��п�
		if (ifs.eof()) {
			cout << "�ļ�Ϊ��" << endl;
			this->fileIsEmpty = true;
			ifs.close();
			return;
		}
		else {
			this->fileIsEmpty = false;
			// ��ȡ�����ַ��Ż�ȥ
			ifs.putback(ch);
			string data;
			// �ڼ���
			int index = 0;
			while (ifs >> data) {
				//cout << data << endl;
				//10002, 85.6625, 10008, 84.9, 10005, 83.2625,
				vector<string>v;
				int pos = -1;
				int start = 0;
				while (true) {
					pos = data.find(",", start);
					if (pos == -1) {
						// �Ҳ�������
						break;
					}
					else {
						string tmp = data.substr(start, pos - start);
						v.push_back(tmp);
						start = pos + 1;
					}
				}
				this->m_Record.insert(make_pair(index, v));
				index++;
			}
			
		}
	}
	ifs.close();
	this->showRecord();
}
void SpeechManger::showRecord() {
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ����ļ������� ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++) {
			cout << "��" << i + 1 << "��\n" <<
				"�ھ����:" << this->m_Record[i][0] << "\t�÷�" << this->m_Record[i][1] << "\n" <<
				"�Ǿ����:" << this->m_Record[i][2] << "\t�÷�" << this->m_Record[i][3] << "\n" <<
				"�������:" << this->m_Record[i][4] << "\t�÷�" << this->m_Record[i][4] << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void SpeechManger::clearRecord() {
	cout << "ȷ�����" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		// ��ģʽ �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "��ճɹ� !" << endl;
	}
	system("pause");
	system("cls");

}