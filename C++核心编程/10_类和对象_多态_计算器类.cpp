#include<iostream>
#include<string>
using namespace std;

// ��ͨ������
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
		// ������չ���� ����Ҫ�޸�Դ�� ����
		// ����ԭ�� ��չ���� �޸Ĺر�
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


// ��̬������
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
	// ��̬ʹ������
	// ����ָ������ָ���������
	AbstractCalculator* abc = new addCal();
	abc->A = 10;
	abc->B = 5;
	cout << abc->getResult() << endl;
	// ������Ҫ����
	delete abc;

	abc = new subCal();
	abc->A = 30;
	abc->B = 10;
	cout << abc->getResult() << endl;


}
int main() {
	// ��ͨ
	test();
	// ��̬
	test02();
	system("pause");
	return 0;
}