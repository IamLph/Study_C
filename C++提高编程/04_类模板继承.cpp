#include<iostream>
#include<string>
using namespace std;
/*
	当类模板碰到继承时，需要注意一下几点
	当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
	如果不指定，编译器无法给子类分配内存
	如果想灵活指定出父类中T的类型，子类也需变为类模板
*/
template<class T>
class Base {
	T m;
};
// 错误继承 必须要知道父类中T类型才可以 
//class Son :public Base{};

// 正确继承
class Son:public Base<int>{};
void Test() {
	Son s1;
}

// 如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1,class T2>
class Son2 :public Base<T2> {
public:
	Son2() {
		cout << "T1数据类型" << typeid(T1).name() << endl;
		cout << "T2数据类型" << typeid(T2).name() << endl;
	}
	T1 obj; 
};
void Test2() {
	// 父类变为char类型
	Son2<int,char> s2;
}


/*
	类模板成员函数类外实现
*/

template<class T1,class T2>
class Person {
public:
	T1 Name;
	T2 Age;
	// 类内实现
	/*Person(T1 name, T2 age) {
		this->Name = name;
		this->Age = age;
	}
	void showPerson() {
		cout << this->Name << ":" << this->Age << endl;
	}*/

	// 类外实现
	Person(T1 name, T2 age);
	void showPerson();
};
// 类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age) {
	this->Name = name;
	this->Age = age;
}
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << this->Name << ":" << this->Age << endl;
}
void Test3() {
	Person<string,int> p1("张三",23);
	p1.showPerson();
}

int main() {
	/*Test();
	Test2();*/

	Test3();
	system("pause");
	return 0;
}