#include<iostream>
using namespace std;
#include<string>

// 类模板
template<class NameType,class AgeType>
class Person {
public:
	NameType Name;
	AgeType Age;
	Person(NameType name, AgeType age) {
		Name = name;
		Age = age;
	}
	void showInfo() {
		cout << this->Name << ":" << this->Age << endl;
	}
};

void p_t() {
	Person<string, int> p1("张三",23);
	p1.showInfo();
}

/*
	类模板与函数模板区别主要有两点
	1.类模板没有自动类型推导的使用方式
	2.类模板在模板参数列表中可以有默认参数
*/

// 2.类模板在模板参数列表中可以有默认参数
template<class NameType, class AgeType=int>
class T_c {
public:
	NameType Name;
	AgeType Age;
	T_c(NameType name, AgeType age) {
		Name = name;
		Age = age;
	}
	void showInfo() {
		cout << this->Name << ":" << this->Age << endl;
	}
};
void t_c_t() {
	// 1.类模板没有自动类型推导的使用方式
	//T_c p("张森纳", 23);
	T_c<string, int> p("张森纳", 23);
	p.showInfo();

	// 2.类模板在模板参数列表中可以有默认参数
	T_c<string> p2("张森纳2", 23);
	p2.showInfo();

}

/*
	类模板成员函数的创建时机
	类模板中的成员函数在调用时才会创建
*/

class p1 {
public:
	void ShowInfo() {
		cout << "show per1" << endl;
	}
};

class p2 {
public:
	void ShowInfo2() {
		cout << "show per2" << endl;
	}
};

template<class T>
class MyP {
public:
	T obj;
	void func1() {
		// 没有调用就不会被创建
		obj.ShowInfo()
	}
	void func2() {
		obj.ShowInfo2()
	}
};

void MyP_t() {
	MyP<p1> p;
	//p.func1();
	//p.func2();
}


int main() {
	// 类模板
	//p_t();
	
	// 区别
	//t_c_t();

	//类模板中的成员函数在调用时才会创建
	MyP_t();
	system("pause");
	return 0;
}