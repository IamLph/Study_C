#include<iostream>
#include<string>
using namespace std;

// 普通计算器
class Calculator {
public:
	int A;
	int B;
	int getResult(string oper) {
		if (oper == "+") {
			return A + B;
		}
		else if (oper == "-") {
			return A - B;
		}
		else if (oper == "*") {
			return A * B;
		}
		else if (oper == "/") {
			return A / B;
		}
		// 若是拓展计算 则需要修改源码 不好
		// 开闭原则 扩展开放 修改关闭
	}
};
void test() {
	Calculator c;
	c.A = 10;
	c.B = 20;
	cout << c.getResult("+") << endl;
	cout << c.getResult("-") << endl;
	cout << c.getResult("*") << endl;
	cout << c.getResult("/") << endl;
}


// 多态计算器
class AbstractCalculator {
public:
	int A;
	int B;
	virtual int getResult() { return 0; };
};
class addCal :public AbstractCalculator {
public:
	int getResult() {
		return A + B;
	}
};
class subCal :public AbstractCalculator {
public:
	int getResult() {
		return A - B;
	}
};
class mulbCal :public AbstractCalculator {
public:
	int getResult() {
		return A * B;
	}
};
class chubCal :public AbstractCalculator {
public:
	int getResult() {
		return A / B;
	}
};

void test02() {
	// 多态使用条件
	// 父类指针引用指向子类对象
	AbstractCalculator* abc = new addCal();
	abc->A = 10;
	abc->B = 5;
	cout << abc->getResult() << endl;
	// 用完需要销毁
	delete abc;

	abc = new subCal();
	abc->A = 30;
	abc->B = 10;
	cout << abc->getResult() << endl;


}
int main() {
	// 普通
	test();
	// 多态
	test02();
	system("pause");
	return 0;
}