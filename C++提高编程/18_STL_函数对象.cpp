#include<iostream>
#include<string>
using namespace std;
/*
		重载函数调用操作符的类，其对象常称为函数对象
		函数对象使用重载的()时，行为类似函数调用，也叫仿函数
		函数对象(仿函数)是一个类，不是一个函数
	特点:
		函数对象在使用时，可以像普通函数那样调用,可以有参数，可以有返回值
		函数对象超出普通函数的概念，函数对象可以有自己的状态.
		函数对象可以作为参数传递
*/

class MyAdd {
public:
	int operator()(int v1,int v2) {
		return v1 + v2;
	}
};

void test01() {
	MyAdd myadd;
	cout << myadd(10, 12) << endl;
}

class MyPrint {
public:
	// 内部自己的状态
	int count;
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}
	MyPrint() {
		this->count = 0;
	}
};

void test02() {
	MyPrint mp;
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	cout << "调用次数:" << mp.count << endl;
}
void DoPrint(MyPrint &mp,string test) {
	mp(test);
}
void test03() {
	MyPrint mp;
	DoPrint(mp, "你好!");
}
int main() {
	// 函数对象在使用时，可以像普通函数那样调用,可以有参数，可以有返回值
	test01();

	// 函数对象超出普通函数的概念，函数对象可以有自己的状态.
	test02();

	// 函数对象可以作为参数传递
	test03();
	system("pause");
	return 0;
}