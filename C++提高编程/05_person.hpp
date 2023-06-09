#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person {
public:
	T1 Name;
	T2 Age;

	Person(T1 name, T2 age);
	void showPerson();
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->Name = name;
	this->Age = age;
}
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << this->Name << ":" << this->Age << endl;
}