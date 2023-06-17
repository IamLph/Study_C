#include<iostream>
#include<string>
using namespace std;
/*
	����ģ�������̳�ʱ����Ҫע��һ�¼���
	������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
	�����ָ�����������޷�����������ڴ�
	��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
*/
template<class T>
class Base {
	T m;
};
// ����̳� ����Ҫ֪��������T���Ͳſ��� 
//class Son :public Base{};

// ��ȷ�̳�
class Son:public Base<int>{};
void Test() {
	Son s1;
}

// ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T1,class T2>
class Son2 :public Base<T2> {
public:
	Son2() {
		cout << "T1��������" << typeid(T1).name() << endl;
		cout << "T2��������" << typeid(T2).name() << endl;
	}
	T1 obj; 
};
void Test2() {
	// �����Ϊchar����
	Son2<int,char> s2;
}


/*
	��ģ���Ա��������ʵ��
*/

template<class T1,class T2>
class Person {
public:
	T1 Name;
	T2 Age;
	// ����ʵ��
	/*Person(T1 name, T2 age) {
		this->Name = name;
		this->Age = age;
	}
	void showPerson() {
		cout << this->Name << ":" << this->Age << endl;
	}*/

	// ����ʵ��
	Person(T1 name, T2 age);
	void showPerson();
};
// ����ʵ��
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
	Person<string,int> p1("����",23);
	p1.showPerson();
}

int main() {
	/*Test();
	Test2();*/

	Test3();
	system("pause");
	return 0;
}