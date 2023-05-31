#include<iostream>
#include<string>
using namespace std;


// 抽象类无法被实例化
class Base {
public:
	// 纯虚函数
	// 主要有纯虚函数 该类就称为抽象类
	// 特点 无法实例化对象
	// 子类必须重写
	virtual void func() = 0;
};
class Son :public Base {
public:
	void func() {
		cout << "已经重写了 " << endl;
	}
};
void test() {
	//Base b;
	Son s;
	s.func();
	// 子类重写才可实例化
	Base *b = new Son;
	b->func();
}

int main() {
	test();
	system("pause");
	return 0;
}