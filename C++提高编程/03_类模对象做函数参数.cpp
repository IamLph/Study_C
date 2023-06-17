#include<iostream>
using namespace std;
#include<string>

// ��ģ���������������
template<class T1,class T2>
class Person {
public:
	T1 Name;
	T2 Age;
	Person(T1 name, T2 age){
		this->Name = name;
		this->Age = age;
	}
	void showPerson() {
		cout << this->Name << ":" << this->Age << endl;
	}
};

// 1.����ָ������
void printPerson1(Person<string, int>&p) {
	p.showPerson();
}
void test01() {
	Person<string, int> p("�����", 23);
	printPerson1(p);
}

// 2.����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p) {
	p.showPerson();
}
void test02() {
	Person<string, int> p("12���", 23);
	printPerson2(p);
}

// 3.������ģ�廯
template<class T>
void printPerson3(T& p) {
	p.showPerson();
}
void test03() {
	Person<string, int> p("�������", 23);
	printPerson3(p);
}

int main() {
	//test01();
	test02();
	test03();
	system("pause");
	return 0;
}