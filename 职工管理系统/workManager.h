#pragma once
// ��ֹͷ�ļ��ظ�����
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

// 1.����������
class WorkManager {
public:
	WorkManager();
	~WorkManager();
	// չʾ�˵�
	void showMenu();
	// 0.�˳�ϵͳ
	void ExitSystem();
	// ��¼ְ������
	int EmpNum;
	// ְ������ָ��
	Worker** EmpArray;
	// ���ְ��
	void AddEmp();
	// �����ļ�
	void save();
	// �ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	// �ļ����ڳ�ʼ������
	int getEmpNum();
	// ��ʼ��ְ������
	void init_emp();
	//��ʾԱ��
	void showEmp();
	// �ж�ְ���Ƿ����
	int IsExist(int id);
	// ɾ��ְ��
	void del_emp();
	// �޸�ְ��
	void Mod_emp();
	// ����ְ��
	void find_emp();
	// ְ������
	void sort_emp();
	// ����ļ�
	void clean_file();
};