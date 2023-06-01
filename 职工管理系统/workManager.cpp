#include"workManager.h"
// 1.����������
WorkManager::WorkManager() {
	// ��ʼ�����������
	
	// �ļ������� bool fileIsEmpty();

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "ְ���ļ�������" << endl;
		// ��ʼ������
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�����ļ� ����Ϊ��" << endl;
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	// �ļ��� ������
	int num = this->getEmpNum();
	cout << "��ǰְ������Ϊ:" << num << endl;
	this->EmpNum = num;
	// �������鳤�� ���ٿռ�
	this->EmpArray = new Worker * [this->EmpNum];
	// ��ʼ������
	this->init_emp();
	//for (int i = 0; i < this->EmpNum; i++) {
	//	cout << this->EmpArray[i]->Id << ":"
	//		<< this->EmpArray[i]->Name << ":"
	//		<< this->EmpArray[i]->DeptId << endl;
	//}


}
WorkManager::~WorkManager() {
	if (this->EmpArray != NULL) {
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}
void WorkManager::showMenu() {
	cout << "*********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ  ************" << endl;
	cout << "*********    0.�˳�����ϵͳ      ************" << endl;
	cout << "*********    1.����ְ����Ϣ      ************" << endl;
	cout << "*********    2.��ʾְ����Ϣ      ************" << endl;
	cout << "*********    3.ɾ��ְ����Ϣ      ************" << endl;
	cout << "*********    4.�޸�ְ����Ϣ      ************" << endl;
	cout << "*********    5.����ְ����Ϣ      ************" << endl;
	cout << "*********    6.���ձ������      ************" << endl;
	cout << "*********    7.��������ĵ�      ************" << endl;
	cout << "*********************************************" << endl;

}

void WorkManager::ExitSystem() {
	cout << "��ӭ�´�ʹ�� " << endl;
	system("pause");
	exit(0);
}
void WorkManager::AddEmp() {
	cout << "������Ҫ���ְ��������:" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// ��������µĿռ��С
		int newSize = this->EmpNum + addNum;
		Worker ** newSpace = new Worker* [newSize];
		// ��ԭ���ռ��µ����� �������µĿռ���
		if (this->EmpArray != NULL) {
			for (int i = 0; i < this->EmpNum; i++) {
				newSpace[i] = this->EmpArray[i];
			}
		}
		// ���������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ���ı��:" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������:" << endl;
			cin >> name;
			cout << "��ѡ���" << i + 1 << "����ְ���ĸ�λ:" << endl;
			cout << "1����ְͨ��   2������   3��Boss" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			// ���浽������
			newSpace[this->EmpNum + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->EmpArray;
		// �޸��¿ռ��ָ��
		this->EmpArray = newSpace;
		// �����µ�ְ������
		this->EmpNum = newSize;
		// ְ����Ϊ��
		this->fileIsEmpty = false;
		cout << "�ɹ����:" << addNum << "��" << endl;
		// ��������
		this->save();
	}
	else {
		cout << "�������󣡣�" << endl;
	}
	system("pause");
	system("cls");
};
void WorkManager::save() {
	ofstream ofs;
	// ������ķ�ʽ���ļ� -- д�ļ�
	ofs.open(FILENAME, ios::out); 
	for (int i = 0; i < this->EmpNum; i++) {
		ofs << this->EmpArray[i]->Id << " "
			<< this->EmpArray[i]->Name << " "
			<< this->EmpArray[i]->DeptId << endl;
	}
	ofs.close();
};
// ͳ���ļ�����
int WorkManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	return num;
};

void WorkManager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}else if (dId == 3) {
			worker = new Boss(id, name, dId);
		}
		this->EmpArray[index] = worker;
		index++;
	}
	ifs.close();
};
void WorkManager::showEmp() {
	if (this->fileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�� ����" << endl;
	}
	else {
		for (int i = 0; i < EmpNum; i++) {
			// ���ö�̬���ó���ӿ�
			this->EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");

};

// �ж�ְ���Ƿ����
int WorkManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++) {
		if (this->EmpArray[i]->Id == id) {
			index = i;
			break;
		}
	}
	return index;
};
// ɾ��ְ��
void WorkManager::del_emp() {
	if (this->fileIsEmpty) {
		cout << "�ļ�������|��¼Ϊ��!" << endl;
	}
	else {
		cout << "������Ҫɾ����ְ��:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			// ɾ����Ϊ����ǰ��
			for (int i = index;i<this->EmpNum-1; i++) {
				this->EmpArray[i] = this->EmpArray[i + 1];
			}
			this->EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "δ���ָ�ְ�� ����" << endl;
		}
	}
	system("pause");
	system("cls");
};
void WorkManager::Mod_emp() {
	if (this->fileIsEmpty) {
		cout << "�ļ�������|��¼Ϊ��!" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�ְ��:" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1) {
			cout << "δ���ָ�ְ�� ����" << endl;
		}
		else {
			delete this->EmpArray[index];
			int newId = 0;
			string newName = "";
			int newDselect = 0;
			cout << "�鵽:" << id << "��ְ�����������µ�ְ����" << endl;
			cin >> newId;
			cout << "������:" << endl;
			cin >> newName;
			cout << "�¸�λ:" << endl;
			cout << "1����ְͨ��   2������   3��Boss" << endl;
			cin >> newDselect;

			Worker* worker = NULL;
			switch (newDselect)
			{
			case 1:
				worker = new Employee(newId, newName, newDselect);
				break;
			case 2:
				worker = new Manager(newId, newName, newDselect);
				break;
			case 3:
				worker = new Boss(newId, newName, newDselect);
				break;
			default:
				break;
			}
			this->EmpArray[index] = worker;
			cout << "�޸ĳɹ� ��" << endl;
			// ����
			this->save();
		}
	}
	system("pause");
	system("cls");
};

void WorkManager::find_emp() {
	if (this->fileIsEmpty) {
		cout << "�ļ�������|��¼Ϊ��!" << endl;
	}
	else {
		cout << "�������������[1����� 2������]:" << endl;
		int type;
		cin >> type;
		if (type == 1) {
			int id;
			cout << "������Ҫ���ҵı��:" << endl;
			cin >> id;
			// ���ж��Ƿ����
			int index = this->IsExist(id);
			if (index == -1) {
				cout << "��ְ�������� !! " << endl;
			}
			else {
				cout << "��Ϣ���� :" << endl;
				this->EmpArray[index]->showInfo();
			}
		}
		else if (type == 2) {
			string name;
			cout << "������Ҫ���ҵ�����:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < EmpNum; i++) {
				if (EmpArray[i]->Name == name) {
					cout << "���ҽ������:" << endl;
					flag = true;
					this->EmpArray[i]->showInfo();
			
				}
			}
			if (flag == false) {
				cout << "û�д��ˣ�" << endl;
			}
		}
	}
	system("pause");
	system("cls");
};

void WorkManager::sort_emp() {
	if (this->fileIsEmpty) {
		cout << "�ļ�������|��¼Ϊ��!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ʽ[1������2������]:" << endl;
		int type;
		cin >> type;
		// ѡ�������㷨
		for (int i = 0; i < EmpNum; i++) {
			int minOrMax = i;
			for (int j = i + 1; j < EmpNum; j++) {
				if (type == 1) {
					if (EmpArray[minOrMax]->Id > EmpArray[j]->Id) {
						minOrMax = j;
					}
				}
				else {
					if (EmpArray[minOrMax]->Id < EmpArray[j]->Id) {
						minOrMax = j;
					}
				}
			}
			// ���ǲ��Ⱦͽ���
			if (i != minOrMax) {
				Worker* temp = EmpArray[i];
				EmpArray[i] = EmpArray[minOrMax];
				EmpArray[minOrMax] = temp;
			}
		}
		cout << "�������" << endl;
		this->save();
		this->showEmp();
	}
};


void WorkManager::clean_file() {
	cout << "ȷ�����?[1���� 2����]" << endl;
	int type;
	cin >> type;
	if (type == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->EmpArray != NULL) {
			// ɾ������
			for (int i = 0; i < this->EmpNum; i++) {
				delete this->EmpArray[i];
				this->EmpArray[i] = NULL;
			}
			// ɾ������ָ��
			delete[] this->EmpArray;
			this->EmpArray = NULL;
			this->EmpNum = 0;
			this->fileIsEmpty = true;
		}
		cout << "�����!" << endl;
	}
	system("pause");
	system("cls");
};