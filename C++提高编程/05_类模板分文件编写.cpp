#include<iostream>
using namespace std;
#include<string>

// һ��ֱ�Ӱ���Դ�ļ�
// #include"05_person.cpps"

// ������.h�ļ���.cpp�ļ�������д��һ�� ��׺��Ϊ.hpp�ļ� ���׳���ģ���ļ���
#include"05_person.hpp"


// ��ģ����ļ���д
//template<class T1,class T2>
//class Person {
//public:
//	T1 Name;
//	T2 Age;
//
//	Person(T1 name, T2 age);
//	void showPerson();
//};
//
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age) {
//	this->Name = name;
//	this->Age = age;
//}
//template<class T1,class T2>
//void Person<T1, T2>::showPerson() {
//	cout << this->Name << ":" << this->Age << endl;
//}
void Test() {
	Person<string, int> p1("����", 23);
	p1.showPerson();
}
int main() {
	Test();
	system("pause");
	return 0;
}