#include<iostream>
#include<string>
using namespace std;


class Base {
public:
	Base() {
		cout << "Base ����" << endl;
	}
	// ���������� ��������ͷ�
	/*virtual ~Base() {
		cout << "Base ����" << endl;
	}*/
	// �������� ��Ҫ���� ����Ҫʵ��
	virtual ~Base() = 0;
	virtual void func() = 0;
};
Base::~Base() {
	cout << "��������" << endl;
}
class Son :public Base {
public:
	string * Name;
	Son(string name) {
		cout << "Son ����" << endl;
		Name = new string(name);
	}
	void func() {
		cout << *Name <<"Son��˵��" << endl;
	}
	~Son() {
		if (Name != NULL) {
			cout << "��ʼ�ͷ�" << endl;
			delete Name;
			Name = NULL;
		}
	}
};
void test() {
	Base* b = new Son("Tom");
	b->func();
	// �����ָ����������ʱ�� ����������������
	// ������������ж������ԣ��ͻ�����ڴ�й¶ 
	// �����Ҫ������������Ϊ������ 
	delete b;
}

int main() {
	test();
	system("pause");
	return 0;
}