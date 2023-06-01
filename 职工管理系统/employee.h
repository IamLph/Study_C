#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;
// 普通员工
class Employee :public Worker {
public:
	// 构造函数
	Employee(int id, string name, int did);
	// 显示个人信息
	virtual void showInfo();
	// 获取岗位名称
	virtual string getDeptName();
};