#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"


class Manager :public Worker {
public:
	// ���캯��
	Manager(int id, string name, int did);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getDeptName();
};
