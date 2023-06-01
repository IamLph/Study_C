#include"employee.h"

// 构造函数
Employee::Employee(int id, string name,int did) {
	this->Id = id;
	this->Name = name;
	this->DeptId = did;
};
// 显示个人信息
void Employee::showInfo() {
	cout << "职工编号:" << this->Id
		<< "\t职工姓名:" << this->Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:完成经理的任务" << endl;
};
// 获取岗位名称
string Employee::getDeptName() {
	return string("员工");
};