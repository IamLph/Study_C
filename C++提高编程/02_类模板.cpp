#include<iostream>
using namespace std;
#include<string>

// ��ģ��
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
	Person<string, int> p1("����",23);
	p1.showInfo();
}

/*
	��ģ���뺯��ģ��������Ҫ������
	1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
	2.��ģ����ģ������б��п�����Ĭ�ϲ���
*/

// 2.��ģ����ģ������б��п�����Ĭ�ϲ���
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
	// 1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
	//T_c p("��ɭ��", 23);
	T_c<string, int> p("��ɭ��", 23);
	p.showInfo();

	// 2.��ģ����ģ������б��п�����Ĭ�ϲ���
	T_c<string> p2("��ɭ��2", 23);
	p2.showInfo();

}

/*
	��ģ���Ա�����Ĵ���ʱ��
	��ģ���еĳ�Ա�����ڵ���ʱ�Żᴴ��
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
		// û�е��þͲ��ᱻ����
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
	// ��ģ��
	//p_t();
	
	// ����
	//t_c_t();

	//��ģ���еĳ�Ա�����ڵ���ʱ�Żᴴ��
	MyP_t();
	system("pause");
	return 0;
}