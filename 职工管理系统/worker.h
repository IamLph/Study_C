#pragma once
// ��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
using namespace std;

// ������ ʹ��virtual
class Worker {
public:
	// ְ�����
	int Id;
	// ְ������
	string Name;
	// ���ű��
	int DeptId;

	// ��ʾ������Ϣ
	virtual void showInfo() = 0;
	// ��ȡ��λ����
	virtual string getDeptName() = 0;
};