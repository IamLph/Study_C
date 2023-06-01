#pragma once
// 防止头文件重复包含
#include<iostream>
#include<string>
using namespace std;

// 抽象类 使用virtual
class Worker {
public:
	// 职工编号
	int Id;
	// 职工姓名
	string Name;
	// 部门编号
	int DeptId;

	// 显示个人信息
	virtual void showInfo() = 0;
	// 获取岗位名称
	virtual string getDeptName() = 0;
};