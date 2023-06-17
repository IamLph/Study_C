#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<ctime>
using namespace std;
/*
	��˾������Ƹ��10��Ա�� (ABCDEFGHI)��10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź�����
	Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ: �߻����������з�
	�����10��Ա�����䲿�ź͹���
	ͨ��multimap������Ϣ�Ĳ��� kev(���ű��)value(Ա��
	�ֲ�����ʾԱ����Ϣ
*/
// ����Ա��+
class Worker {
public:
	string Name;
	int Salary;
	Worker(string name, int salary) {
		this->Name = name;
		this->Salary = salary;
	}
};
void createWorker(vector<Worker>&v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		string name = "Ա��" ;
		name += nameSeed[i];
		int salary = rand() % 10000 + 10000; 
		// 10000~19999
		Worker w(name, salary);
		v.push_back(w);
	}
}
void setGroup(vector<Worker>&v, multimap<int, Worker>&mm) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		// ����������ű��
		int deptId = rand() % 3;
		// ��Ա�����뵽������
		mm.insert(make_pair(deptId, *it));
	}
}
void showWorker(vector<Worker> &w) {
	for (vector<Worker>::iterator it = w.begin(); it != w.end(); it++) {
		cout << "����:" << it->Name << "  нˮ:" << it->Salary << endl;
	}
	cout << endl;
}
void showMmWorker(multimap<int, Worker>& mm) {
	map<int, string> m;
	m.insert(make_pair(0, "�߻�����"));
	m.insert(make_pair(1, "��������"));
	m.insert(make_pair(2, "�߻�����"));
	cout << m[0] << endl;
	for (multimap<int, Worker>::iterator it = mm.begin(); it != mm.end(); it++) {
		cout << "����:" << m[it->first] << "  ����:" << it->second.Name << "  н��:" << it->second.Salary << endl;
	}
}
int main() {
	// ����ϵͳʱ��ʵ����ʵ���
	srand((unsigned int)time(NULL));
	// 1.����Ա��
	vector<Worker> v;
	createWorker(v);
	//showWorker(v);

	// 2.Ա������
	multimap<int, Worker>mm;
	setGroup(v,mm);

	// 3.������ʾԱ��
	showMmWorker(mm);

	system("pause");
	return 0;
}