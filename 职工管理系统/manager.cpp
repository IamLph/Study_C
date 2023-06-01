#include"manager.h"


// 构造函数
Manager::Manager(int id, string name, int did) {
	this->Id = id;
	this->Name = name;
	this->DeptId = did;
};
// 显示个人信息
void Manager::showInfo() {
	cout << "职工编号:" << this->Id
		<< "\t职工姓名:" << this->Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:完成老板的任务，指挥员工" << endl;
};
// 获取岗位名称
string Manager::getDeptName() {
	return string("经理");
};