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