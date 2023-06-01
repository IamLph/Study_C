#pragma once
// 防止头文件重复包含
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

// 1.创建管理类
class WorkManager {
public:
	WorkManager();
	~WorkManager();
	// 展示菜单
	void showMenu();
	// 0.退出系统
	void ExitSystem();
	// 记录职工人数
	int EmpNum;
	// 职工数组指针
	Worker** EmpArray;
	// 添加职工
	void AddEmp();
	// 保存文件
	void save();
	// 判断文件是否为空
	bool fileIsEmpty;
	// 文件存在初始化数据
	int getEmpNum();
	// 初始化职工函数
	void init_emp();
	//显示员工
	void showEmp();
	// 判断职工是否存在
	int IsExist(int id);
	// 删除职工
	void del_emp();
	// 修改职工
	void Mod_emp();
	// 查找职工
	void find_emp();
	// 职工排序
	void sort_emp();
	// 清空文件
	void clean_file();
};