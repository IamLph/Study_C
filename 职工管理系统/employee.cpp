#include"employee.h"

// ���캯��
Employee::Employee(int id, string name,int did) {
	this->Id = id;
	this->Name = name;
	this->DeptId = did;
};
// ��ʾ������Ϣ
void Employee::showInfo() {
	cout << "ְ�����:" << this->Id
		<< "\tְ������:" << this->Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:��ɾ��������" << endl;
};
// ��ȡ��λ����
string Employee::getDeptName() {
	return string("Ա��");
};