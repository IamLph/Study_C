#include<iostream>
using namespace std;
#include<string>

// 一、直接包含源文件
// #include"05_person.cpps"

// 二、将.h文件与.cpp文件的内容写道一起 后缀名为.hpp文件 【俗称类模板文件】
#include"05_person.hpp"


// 类模板分文件编写
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
	Person<string, int> p1("张三", 23);
	p1.showPerson();
}
int main() {
	Test();
	system("pause");
	return 0;
}