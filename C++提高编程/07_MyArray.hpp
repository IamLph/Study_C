#pragma once
#include<iostream>
#include<string>
using namespace std;

// 通用数组类
template<class T>
class MyArray {
private:
	// 指针指向堆区开辟的真实数组
	T* pAddress;
	// 数组最大容量
	int m_capacity;
	// 数组大小 数组元素个数
	int m_Size;
public:
	// 有参构造 参数为容量
	MyArray(int capacity) {
		cout << "默认有参构造" << endl;
		this->m_capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_capacity];
	}
	// 拷贝构造 深拷贝
	MyArray(const MyArray& arr) {
		cout << "默认拷贝构造" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_Size = arr.m_Size;
		// 根据容量开辟空间
		this->pAddress = new T[arr.m_capacity];
		// 数据拷贝
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	// 重载运算符 防止浅拷贝问题
	MyArray& operator=(const MyArray & arr) {
		cout << "默认operator=构造" << endl;
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
	// 尾插法 传入数据
	void Push_Back(const T& val) {
		// 判断数据是否满了
		if (this->m_capacity == this->m_Size) {
			cout << "数据已满！！" << endl;
			return;
		}
		// 插入数据以及更新数据
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	// 尾删法
	void Pop_Back() {
		// 让用户访问不到即为尾删 逻辑删除
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}
	// 通过下标访问数据
	/*
		引用作函数返回值:
		1.不要返回局部变量的引用
		2.函数的调用可以作为左值
		因为想要作为左值就是要改变这个量，要改变他本身，用引用才能改变本身
	*/
	T& operator[](int index) {
		cout << "operator[]调用" << endl;
		return this->pAddress[index];
	}
	// 返回数组容量
	int getCapacity() {
		return this->m_capacity;
	}
	// 返回数组大小
	int getSize() {
		return this->m_Size;
	}

	// 析构函数
	~MyArray() {
		if (this->pAddress != NULL) {
			cout << "默认析构构造" << endl;
			delete[] this->pAddress;
			// 指针置空，防止野指针
			this->pAddress = NULL;
		}
	}
};