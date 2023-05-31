#include<iostream>
using namespace std;

// ��̬��Ա ���г�Ա����һ������
class Person {
public:
	// 1.��̬���� ���ж�����
	// 2.�����ʱ��ͷ����ڴ�
	// 3.��Ҫ�������� �����ʼ������
	static int A;
// ˽�о�̬��Ա �����޷�����
private:
	static int B;
};
// ��Ҫ�������� �����ʼ������
int Person::A = 100;
int Person::B = 200;

void test() {
	Person p;
	cout << p.A << endl;
	Person p1;
	// �������� һ���޸� ����Ҳ���޸�
	p1.A = 200;
	cout << p.A << endl;
}
void test02() {
	// 1.ͨ��������з���
	Person p;
	cout << p.A << endl;
	//cout << p.B << endl;

	// 2.ͨ���������з���
	cout << Person::A << endl;
	// ˽���޷�����
	//cout << Person::B << endl;
}



/*
	��̬��Ա����
	���ж�����
	��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
*/
class Person2 {
public:
	static void func() {
		p2_A = 100;
		// �Ǿ�̬�ĳ�Ա�����޷�����
		//p2_B = 200;
		cout << "static void func����" << endl;
	}
	static int p2_A;
	int p2_B;
private:
	static void func2() {
		cout << "static void func2����" << endl;
	}
};
int Person2::p2_A = 666;
void p2_t() {
	// 1.ͨ���������
	Person2 p;
	p.func();
		
	// 2.ͨ����������
	Person2::func();
	// ˽�������޷�����
	//Person2::func2();

}

/*
	��Ա�����ͳ�Ա�����ֿ��洢
*/

class Car {
	int A;
	// ��̬��Ա���� �������������
	static int car_B;
	// �Ǿ�̬��Ա���� �಻�����������
	void func() {
		// �ռ�
	}
};
int Car::car_B = 20;
void car_t() {
	Car c;
	// sizeof  �ն���ռ���ڴ�Ϊ1 �ǿ���Ϊ����ռ�õ��ڴ棬�������1��
	cout << sizeof(c) << endl;
}

/*
	thisָ��
*/
class PP {
public:
	int age;
	PP(int age) {
		this->age = age;
	}
	// ����&�Ļ��ͻ��Ϊ�������� �޷������ڴ汾�� ��һ���µĶ���
	PP& PPadd(PP &p) {
		this->age += p.age;
		return *this;
	}
};
// 1.���ڽ��������ͻ
void PP_t() {
	PP p(18);
	cout << "p_age" << p.age << endl;
}
// 2.���ض������� *this
void PP_t2() {
	PP p1(10);
	PP p2(10);
	//p2.PPadd(p1);
	p2.PPadd(p1).PPadd(p1).PPadd(p1).PPadd(p1).PPadd(p1);
	cout << p2.age << endl;
}


/*
	��ָ����ʳ�Ա����
*/
class AA {
public:
	int Age;
	void showClassName() {
		cout << "this is AA class " << endl;
	}
	void showAge() {
		if (this == NULL) {
			cout << "this is a null point" << endl;
			return;
		}
		cout << "this age = " <<Age << endl;
	}
};
void AA_t() {
	AA* a = NULL;
	a->showClassName();
	// ��ָ���޷��ҵ�age ��Ҫ���ʳ�Ա�ͻᱨ��
	a->showAge();
}

/*
	const���γ�Ա����
	��������
		��Ա�������const�����ǳ�Ϊ�������Ϊ������
		�������ڲ������޸ĳ�Ա����I
		��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�
	������
		��������ǰ��const�Ƹö���Ϊ������
		������ֻ�ܵ��ó�����
*/
class BB {
public:
	int A; 
	// ������� �����ڳ��������޸���ֵ
	mutable int B;
	/*
		BB * const this;
		this�ı�����ָ�볣�� ָ�򲻿��޸� ����ֵ�����޸�
		������ָ���ֵҲ�������޸� ��Ϊ const BB * const this;
		��Ҫѡ��const��λ�� �ں���()���� ���ε���thisָ��
	*/
	void show() const {
		//A = 100;
		//this->A = 100;
		//cout << A << endl; 
		
		this->B = 100;
		cout << B << endl; 
	}
	void s() {
		cout << "��ͨ����" << endl;
	}
};
void bb_t() {
	BB b;
	b.show();
}
// ������ �����Բ����޸� ���Ǽ��� mutable

void bb_t2() {
	const BB b;
	//b.A = 100;
	b.B = 99;
	b.show();
	// ������ֻ�ܵ��ó�����
	//b.s();
}
int main() {
	// ��̬��Ա
	//test();
	// ���ʷ�ʽ
	//test02();

	// ��̬����
	//p2_t();


	// ��Ա�����ͳ�Ա�����ֿ��洢
	//car_t();

	// thisָ�� 
	//PP_t();
	//PP_t2();

	// ��ָ����ʳ�Ա����
	//AA_t();

	// const���γ�Ա����
	bb_t();

	system("pause");
	return 0;
}