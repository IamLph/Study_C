#include"boss.h"

// ���캯��
Boss::Boss(int id, string name, int did) {
	this->Id = id;
	this->Name = name;
	this->DeptId = did;
};
// ��ʾ������Ϣ
void Boss::showInfo() {
	cout << "ְ�����:" << this->Id
		<< "\tְ������:" << this->Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:������������" << endl;
};
// ��ȡ��λ����
string Boss::getDeptName() {
	return string("Boss");
};