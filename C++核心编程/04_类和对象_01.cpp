#include<iostream>
using namespace std;
#include<string>
#define PI 3.14
#include"Cube.h"

/*
	1.��װ
	���Բ�࣬��Բ���ܳ�
*/
class Circul {
	// ����Ȩ�� ����
	public:
		// ����
		int r;
		// ��Ϊ
		void getZhouchang() {
			cout << "�ܳ�Ϊ��" << 2 * PI * r << endl;
		}
};
/*
	���ѧ����
*/
class Studnet {
public:
	string Name;
	int age;
	int sex;
	void getInfo() {
		cout <<"����:"<< Name <<"����:" << age <<"�Ա�:"<< (sex == 0? "Ů":"��") << endl;
	}
	// ��ֵ���� ���Ʋ�����ͬ
	void setName(string name) {
		Name = name;
	}
};

/*
	��װȨ�ޣ�
	public		���ڷ��� �����
	protected	���ڷ��� ���ⲻ�� ���ӿ��Է���
	private		���ڷ��� ���ⲻ�� ���Ӳ��ɷ���
*/

class Person {
public:
	string name;
protected:
	int money;
private:
	int password;
// ���ڷ���
public:
	void func() {
		name = "����";
		money = 100;
		password = 123456; 
		cout << name << ":" << money << ":" << password << endl;
	}
};
/*
	struct��Ĭ��Ȩ��Ϊ����
	class��Ĭ��Ȩ��Ϊ˽��
	ʵ�������𣬶�������Ϊ��ʹ��
*/
class C1 {
	int m;
};
struct C2 {
	int m;
};


/*
	��Ա����˽�л� ���Կ��ƶ�д дȨ�޿��Լ�����ݵ���Ч��
	˽���ⲿ���ɷ��ʣ�����ͨ�����е��޸ķ�������
*/
class Person2 {
private:
	string name;
	int age;
	string lover;
public:
	// name���ÿɶ���д
	void steName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	// age����ֻ��
	int getAge() {
		age = 12;
		return age;
	}
	// loverֻд
	void setLover(string love) {
		lover = love;
	}

};


/*
	���ӣ���������
	�����������������
	�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
*/
//class Cube {
//private:
//	int L;
//	int W;
//	int H;
//public:
//	void setL(int l) {
//		L = l;
//	}
//	int getL() {
//		return L;
//	}
//	void setW(int w) {
//		W = w;
//	}
//	int getW() {
//		return W;
//	}
//	void setH(int h) {
//		H = h;
//	}
//	int getH() {
//		return H;
//	}
//	void S() {
//		cout << "���" << L * W * 2 + L * H * 2 + W * H * 2 << endl;
//		cout << "���" << L * W * H << endl;
//	}
//	// ��Ա����
//	bool isSame(Cube& c2) {
//		if (L == c2.getL() && W == c2.getW() && H == c2.getH()) {
//			return true;
//		}
//		return false;
//	}
//};

// ȫ�ֺ����ж��Ƿ����
bool isSame(Cube& c1, Cube& c2) {
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		cout << "��ͬ" << endl;
		return true;
	}
	cout << "����ͬ" << endl;
	return false;
}

int main() {
	// ʵ���� ��������
	/*Circul c1;
	c1.r = 1;
	c1.getZhouchang();
	Studnet s1;
	s1.setName("����");
	s1.age = 12;
	s1.sex = 0;
	s1.getInfo();*/

	//Person p1;
	//p1.name = "66";
	//// ����Ȩ�������ⲻ�ɷ���
	////p1.money = 12;
	//// ˽��Ȩ�������ⲻ�ɷ���
	////p1.password = 123;
	//p1.func();


	// struct �� class ������ Ȩ������
	/*C1 c1;
	c1.m = 12;
	C2 c2;
	c2.m = 12;*/

	/*Person2 p2;
	p2.steName("����");
	cout << "����:" << p2.getName() << endl ;
	cout << "����:" << p2.getAge() << endl ;
	p2.setLover("��");*/

	Cube cu;
	cu.setH(10);
	cu.setW(10);
	cu.setL(10);
	cu.S();
	//Cube cu2;
	//cu2.setH(10);
	//cu2.setW(100);
	//cu2.setL(10);
	//bool result = isSame(cu, cu2);
	//if (result) {
	//	cout << "��ͬ" << endl;
	//}
	//else {
	//	cout << "����ͬ" << endl;
	//}
	//cu2.isSame(cu);



	system("pause");
	return 0;
}