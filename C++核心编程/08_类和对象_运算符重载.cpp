#include<iostream>
#include<string>
using namespace std;
/*
	��������� ���������ʵ���µĹ���
*/

// 1.�Ӻ������
class Person {
public:
	int A;
	int B;
	// 1.��Ա��������
	// ������ Person p3 = p1.operator+(p2);
	/*Person operator+(Person& p) {
		Person temp;
		temp.A = this->A + p.A;
		temp.B = this->B + p.B;
		return temp;
	}*/
};
// 2.ȫ�ֺ�������
// ������ Person p3 = operator+( p1,p2);
Person operator+(Person& p1,Person& p2) {
	Person temp;
	temp.A = p1.A + p2.A;
	temp.B = p1.B + p2.B;
	return temp;
}

void p_t() {
	Person p1;
	p1.A = 10;
	p1.B = 100;

	Person p2;
	p2.A = 10;
	p2.B = 10;

	Person p3 = p1 + p2;
	cout << p3.A << ":" << p3.B << endl;
}


// 2.������������� ��������Զ�����������
class Person2 {
public:
	int A;
	int B;
	// 01.��Ա���� �޷��������� cout ��������Ҳ�
	//Person2 operator<<(cout) {}
};
// 02.ȫ�ֺ���
ostream & operator<<(ostream &cout, Person2 &p) {
	cout << p.A << ":" << p.B << endl;
	return cout;
}

void p2_t() {
	Person2 p;
	p.A = 10;
	p.B = 20;
	//cout << p.A << ":" << p.B << endl;
	cout << p ;
}


// 3.������������� ����ʵ���Լ�����������
class MyInterger {
	friend ostream& operator<<(ostream& cout, MyInterger p);

private:
	int m;
public:
	MyInterger() {
		m = 0;
	}
	// ����ǰ�������
	MyInterger& operator++() {
		m++;
		return *this;
	}
	// ���õ���
	MyInterger operator++(int) {
		MyInterger temp = *this;
		m++;
		return temp;
	}
};
ostream& operator<<(ostream& cout, MyInterger p) {
	cout << p.m << endl;
	return cout;
}

void mi_t() {
	MyInterger myint;
	cout << ++myint << endl;

	cout << myint++ << endl;
}


// 4.��ֵ���������
class Person3 {
public:
	int* Age;
	Person3(int age) {
		Age = new int(age);
	}
	// ����
	Person3& operator=(Person3 &p) {
		// ���ж��Ƿ��������ڶ��� ����������ͷ� ֮���ٽ������
		if (Age != NULL) {
			delete Age;
			Age = NULL;
		}
		Age = new int(*p.Age);

		// ���ض�������
		return *this;
	}

	~Person3() {
		if (Age != NULL) {
			delete Age;
			Age = NULL; 
		}
	}
};
void p3_t() {
	Person3 p1(18);
	Person3 p2(22);
	// ��ֵ����
	p2 = p1;
	cout << *p1.Age << endl;
	cout << *p2.Age << endl;
}


// 5.��ϵ���������
class Person4 {
public:
	string Name;
	int Age; 
	Person4(string name, int age) {
		Name = name;
		Age = age;
	}
	bool operator==(Person4 &p) {
		if (this->Name == p.Name && this->Age == p.Age) {
			return true;
		}
		return false;
	}
	bool operator!=(Person4& p) {
		if (this->Name == p.Name && this->Age == p.Age) {
			return false;
		}
		return true;
	}
};

void p4_t() {
	Person4 p1("����", 19);
	Person4 p2("����", 17);
	if (p1 == p2) {
		cout << "ͬ" << endl;
	}
	else if (p1 != p2) {
		cout << "����Noooo!" << endl;
	}
	else {
		cout << "�޷��ж�" << endl;
	}
}

// 6.�������������()���� ��Ϊ�º��� û�й̶�д���������
class MyPrint {
public:
	// ���غ��������
	void operator()(string test) {
		cout << test << endl;
	}
	void operator()(int a,int b) {
		cout << a + b << endl;
	}
};
void mp_t() {
	MyPrint mp;
	mp("��ð�����");
	mp(6,6);
}

int main() {
	// �Ӻ������
	//p_t();

	// ���������
	//p2_t();

	// ���������
	//mi_t();

	// ��ֵ���������
	//p3_t();

	// ��ϵ���������
	//p4_t();

	//���غ���
	mp_t();
	system("pause");
	return 0;
}