#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
	// 虚函数 晚绑定
	virtual void speak() {
		cout << "Animal说话" << endl;
	}
};
class Cat :public Animal {
public:
	void speak() {
		cout << "Cat说话" << endl;
	}
};

// 地址在编译阶段就确定了地址 导致走Animal的函数
// 因此需要使用virtual晚绑定
// 当子类重写父类的虚函数的时候，就会发生一个重写操作
// 子类中的虚函数表内部会替换成子类的虚函数地址
void doSpeak(Animal& animal) {
	animal.speak();
}
void cat_t() {
	Cat cat;
	doSpeak(cat);
}

int main() {
	cat_t(); 

	system("pause");
	return 0;
}