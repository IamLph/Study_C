#include<iostream>
#include<string>
using namespace std;

// 类的声明
template<class T1, class T2>
class Person;

// 全局函数 类外实现
template<class T1, class T2>
void showPerson2(Person<T1, T2> p) {
	cout << p.Name << ":" << p.Age << endl;
};

template<class T1, class T2>
class Person {
	// 全局函数 类内实现
	friend void showPerson(Person<T1, T2> p) {
		cout << p.Name << ":" << p.Age << endl;
	};
	// 全局函数 类外实现
	// 加空模板参数列表才可使用
	friend void showPerson2<>(Person<T1, T2> p);
public:
	T1 Name;
	T2 Age;

	Person(T1 name, T2 age) {
		this->Name = name;
		this->Age = age;
	};
};
// 全局函数 类内实现
void test01() {
	Person<string,int> p("张三",23);
	showPerson(p);
}

void test02() {
	Person<string,int> p("张12三", 23);
	showPerson2(p);
}
int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}