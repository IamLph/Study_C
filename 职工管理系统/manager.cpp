#include"manager.h"


// ���캯��
Manager::Manager(int id, string name, int did) {
	this->Id = id;
	this->Name = name;
	this->DeptId = did;
};
// ��ʾ������Ϣ
void Manager::showInfo() {
	cout << "ְ�����:" << this->Id
		<< "\tְ������:" << this->Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:����ϰ������ָ��Ա��" << endl;
};
// ��ȡ��λ����
string Manager::getDeptName() {
	return string("����");
};