#pragma once
#include<iostream>
#include<string>
using namespace std;

// ͨ��������
template<class T>
class MyArray {
private:
	// ָ��ָ��������ٵ���ʵ����
	T* pAddress;
	// �����������
	int m_capacity;
	// �����С ����Ԫ�ظ���
	int m_Size;
public:
	// �вι��� ����Ϊ����
	MyArray(int capacity) {
		cout << "Ĭ���вι���" << endl;
		this->m_capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_capacity];
	}
	// �������� ���
	MyArray(const MyArray& arr) {
		cout << "Ĭ�Ͽ�������" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_Size = arr.m_Size;
		// �����������ٿռ�
		this->pAddress = new T[arr.m_capacity];
		// ���ݿ���
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	// ��������� ��ֹǳ��������
	MyArray& operator=(const MyArray & arr) {
		cout << "Ĭ��operator=����" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_Size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	// β�巨 ��������
	void Push_Back(const T& val) {
		// �ж������Ƿ�����
		if (this->m_capacity == this->m_Size) {
			cout << "������������" << endl;
			return;
		}
		// ���������Լ���������
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	// βɾ��
	void Pop_Back() {
		// ���û����ʲ�����Ϊβɾ �߼�ɾ��
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}
	// ͨ���±��������
	/*
		��������������ֵ:
		1.��Ҫ���ؾֲ�����������
		2.�����ĵ��ÿ�����Ϊ��ֵ
		��Ϊ��Ҫ��Ϊ��ֵ����Ҫ�ı��������Ҫ�ı������������ò��ܸı䱾��
	*/
	T& operator[](int index) {
		cout << "operator[]����" << endl;
		return this->pAddress[index];
	}
	// ������������
	int getCapacity() {
		return this->m_capacity;
	}
	// ���������С
	int getSize() {
		return this->m_Size;
	}

	// ��������
	~MyArray() {
		if (this->pAddress != NULL) {
			cout << "Ĭ����������" << endl;
			delete[] this->pAddress;
			// ָ���ÿգ���ֹҰָ��
			this->pAddress = NULL;
		}
	}
};