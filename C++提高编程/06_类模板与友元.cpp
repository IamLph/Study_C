#include<iostream>
#include<string>
using namespace std;

// �������
template<class T1, class T2>
class Person;

// ȫ�ֺ��� ����ʵ��
template<class T1, class T2>
void showPerson2(Person<T1, T2> p) {
	cout << p.Name << ":" << p.Age << endl;
};

template<class T1, class T2>
class Person {
	// ȫ�ֺ��� ����ʵ��
	friend void showPerson(Person<T1, T2> p) {
		cout << p.Name << ":" << p.Age << endl;
	};
	// ȫ�ֺ��� ����ʵ��
	// �ӿ�ģ������б�ſ�ʹ��
	friend void showPerson2<>(Person<T1, T2> p);
public:
	T1 Name;
	T2 Age;

	Person(T1 name, T2 age) {
		this->Name = name;
		this->Age = age;
	};
};
// ȫ�ֺ��� ����ʵ��
void test01() {
	Person<string,int> p("����",23);
	showPerson(p);
}

void test02() {
	Person<string,int> p("��12��", 23);
	showPerson2(p);
}
int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}