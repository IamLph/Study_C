#include<iostream>
#include<string>
using namespace std;


// �������޷���ʵ����
class Base {
public:
	// ���麯��
	// ��Ҫ�д��麯�� ����ͳ�Ϊ������
	// �ص� �޷�ʵ��������
	// ���������д
	virtual void func() = 0;
};
class Son :public Base {
public:
	void func() {
		cout << "�Ѿ���д�� " << endl;
	}
};
void test() {
	//Base b;
	Son s;
	s.func();
	// ������д�ſ�ʵ����
	Base *b = new Son;
	b->func();
}

int main() {
	test();
	system("pause");
	return 0;
}