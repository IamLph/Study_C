#include<iostream>
#include<string>
using namespace std;


class Base {
public:
	Base() {
		cout << "Base 构造" << endl;
	}
	// 利用虚析构 子类对象释放
	/*virtual ~Base() {
		cout << "Base 析构" << endl;
	}*/
	// 纯虚析构 需要声明 亦需要实现
	virtual ~Base() = 0;
	virtual void func() = 0;
};
Base::~Base() {
	cout << "纯虚析构" << endl;
}
class Son :public Base {
public:
	string * Name;
	Son(string name) {
		cout << "Son 构造" << endl;
		Name = new string(name);
	}
	void func() {
		cout << *Name <<"Son在说话" << endl;
	}
	~Son() {
		if (Name != NULL) {
			cout << "开始释放" << endl;
			delete Name;
			Name = NULL;
		}
	}
};
void test() {
	Base* b = new Son("Tom");
	b->func();
	// 父类的指针在析构的时候 不会调用子类的析构
	// 导致子类如果有堆区属性，就会出现内存泄露 
	// 因此需要将父类析构改为虚析构 
	delete b;
}

int main() {
	test();
	system("pause");
	return 0;
}