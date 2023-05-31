#include<iostream>
using namespace std;


// ���ຯ��Ĭ�϶��� ����Ϊ�� 
class Person {
public:
	int age;
	// 1.���캯�� �����ʼ����ʱ����е���
	// �޲ι���
	Person() {
		cout << "���캯������" << endl;
	}
	// �вι���
	Person(int a) {
		age = a;
		cout << "�вι�����ã�a="<< a << endl;
	}
	// �������캯��
	Person(const Person &p) {
		// ��������˵����� ��������ǰ������
		age = p.age;
		cout << "�������캯��==��" << age << endl;
	}

	// 2.��������
	~Person() {
		cout << "������������" << endl;
	}
};


void test01() {
	
	// 1.���ŷ�
	//Person p1;
	//Person p2(10);
	//Person p3(p2);
	// ʹ��Ĭ�Ϲ��캯����ʱ�� ��Ҫ��() ����Ϊ��һ������������ ������Ϊ�ڴ�������
	//Person p1();


	// 2.��ʾ��
	Person p1;
	// �вι���
	Person p2 = Person(10);
	// ��������
	Person p3 = Person(p2);
	
	// 3.��ʽת����
	Person p4 = 10; // �൱�� Person p2 = Person(10);
	Person p5 = p4; // ��������
}

/*
* 	
	����û��������вι��캯�� C++�Ͳ����ṩĬ�ϵ��޲ι��캯�� ���ǻ��ṩĬ�Ͽ�������
	����û������˿������캯�� C++�Ͳ������ṩ�����Ĺ��캯��
	
	���캯���ĵ��ù���
	1.����һ���� C++���������ÿ���඼���������������
	Ĭ�Ϲ��� (��ʵ��)
	�������� (��ʵ��)
	�������� (ֵ����)
*/
class Person2 {
public:
	int Age;
	Person2() {
		cout << "Person��Ĭ�Ϲ���" << endl;
	}
	// �ṩ�вι��� �Ͳ����ṩĬ�Ϲ����� �����ҪдĬ�Ϲ���
	Person2(int age) {
		Age = age;
		cout << "Person���вκ�������" << Age << endl;
	}
	// ����ѹ��캯��ע���˵Ļ� Ĭ�ϻ��ṩֵ����������Age�Ĵ���
	// ����û������˿������캯�� C++�Ͳ������ṩ�����Ĺ��캯�� ��Ҫ�Լ��ṩ 
	/*Person2(const Person2& p) {
		Age = p.Age;
		cout << "Person�Ŀ�����������" << Age << endl;
	}*/

	~Person2() {
		cout << "person��������������" << endl;
	}
};

void test() {
	Person2 p;
	p.Age = 18;
	Person2 p2(p);
	cout << "p2��������:" << p2.Age << endl;
}
void test02() {
	Person2 p;
}


// 3.�����ǳ����
class Person3 {
public:
	int Age;
	int* Height;
	Person3() {
		cout << "Person3��Ĭ�Ϲ���" << endl;
	}

	Person3(int age,int height) {
		Height = new int(height);
		Age = age;
		cout << "Person3���вκ�������" << Age << endl;
	}

	/*Person2(const Person2& p) {
		Age = p.Age;
		cout << "Person�Ŀ�����������" << Age << endl;
	}*/

	~Person3() {
		// �������� ִ�ж������ݵ��ͷŲ���
		// ǳ��������������ڴ���ظ��ͷ� �����Ҫ���
		if (Height != NULL) {
			delete Height;
			Height = NULL;
		}
		cout << "person��������������" << endl;
	}

	// �Լ�ʵ�����
	Person3(const Person3 &p) {
		cout << "person3�Ŀ�����������" << endl;
		Age = p.Age;
		// �������
		Height = new int(*p.Height);
	}
};

void p3_test() {
	Person3 p1(18,160);
	cout << "p1������" << p1.Age <<":" << *p1.Height << endl;
	// ǳ���� 
	Person3 p2(p1);
	cout << "p2������" << p2.Age << ":" << *p1.Height << endl;
}


/*	
	4.��ʼ���б�
*/
class Car {
public:
	int A;
	int B;
	int C;

	// ��ͳ��ʼ������
	/*Car(int a, int b, int c) {
		A = a;
		B = b;
		C = c;
	}*/

	// ��ʼ���б���ֵ
	Car(int a, int b, int c):A(a),B(b),C(c){}

};

void car() {
	//Car c(10, 20, 30);
	//cout << c.A << ":" << c.B << ":" << c.C << endl;

	Car c2(1,2,3);
	cout << c2.A << ":" << c2.B << ":" << c2.C << endl;
}

/*
	5.�������Ϊ���Ա
*/

class Phone {
public:
	string p_name;
	Phone(string n) {
		cout << "Phone�����������" << endl;
		p_name = n;
	}
};
class Person4 {
public:
	string name;
	Phone phone;

	Person4(string n, string pn):name(n),phone(pn) {
		cout << "person�����������" << endl;
	}
};

void person4() {
	Person4 p("����", "��Ϊ");
	cout << p.name << p.phone.p_name << endl;
}

int main() {
	// 1.���캯����ʹ��
	//test01();
	//Person p;
	
	// 2.���캯���ĵ��ù���
	//test();
	// �ṩ�вι��� �Ͳ����ṩĬ�Ϲ����� �����ҪдĬ�Ϲ���
	//test02();

	// 3.ǳ���������
	//p3_test();

	// 4.��ʼ���б�
	//car();

	// 5.�������Ϊ���Ա
	person4();

	system("pause");
	return 0;
}