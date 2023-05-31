#include<iostream>
#include<string>
using namespace std;

// ����̲� ����д̫���ظ���
//class JAVA {
//public:
//	void header() {
//		cout << "JAVA��ҳ" << endl;
//	}
//	void footer() {
//		cout << "JAVA��" << endl;
//	}
//	void left() {
//		cout << "JAVA����" << endl;
//	}
//	void content() {
//		cout << "JAVA��Ƶ" << endl;
//	}
//};
//
//
//
//class PYTHON {
//public:
//	void header() {
//		cout << "PYTHON��ҳ" << endl;
//	}
//	void footer() {
//		cout << "PYTHON��" << endl;
//	}
//	void left() {
//		cout << "PYTHON����" << endl;
//	}
//	void content() {
//		cout << "PYTHON��Ƶ" << endl;
//	}
//};
//
//void ja_t() {
//	JAVA ja;
//	cout << "java��Ϣ" << endl;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//	cout << "PYTHON��Ϣ" << endl;
//	PYTHON py;
//	py.header();
//	py.footer();
//	py.left();
//	py.content();
//
//}

// �̳�ʵ��ҳ��
// ����ҳ��
class BasePage {
public:
	void header() {
		cout << "��ҳ" << endl;
	}
	void footer() {
		cout << "��" << endl;
	}
	void left() {
		cout << "����" << endl;
	}
	
};
class JAVA : public BasePage {
public:
	void content() {
		cout << "JAVA��Ƶ" << endl;
	}
};
class PYTHON : public BasePage {
public:
	void content() {
		cout << "PYTHON��Ƶ" << endl;
	}
};

void t_Base() {
	cout << "JAVA��Ϣ" << endl;
	JAVA ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "PYTHON��Ϣ" << endl;
	PYTHON py;
	py.header();
	py.footer();
	py.left();
	py.content();
}

// 2.�̳з�ʽ ���� ˽�� ����
class BASE {
public:
	int a;
protected:
	int b;
private:
	int c;
};
class A :public BASE {
	void func() {
		a = 10;
		// ��������Ϊ����Ȩ��
		b = 10;
		// ˽�в��ɷ���
		//c = 10;
	}
};
class B :protected BASE {
	void func() {
		// ������ȫΪ���� �����������޸�
		a = 10;
		b = 10;
		// ˽�в��ɷ���
		//c = 10;
	}
};
class C :private BASE {
	void func() {
		// ����Ϊ˽�� ���ⲻ�ɷ���
		a = 10;
		b = 10;
		// ����˽�в��ɷ���
		//c = 10;
	}
};
class CC :public C {
	void func() {
		// ����˽�У��Բ��ɷ���
		// a = 10;
		// b = 10;
	}
};

void abc_t() {
	A a;
	a.a = 10;
	// ��������Ϊ����Ȩ��
	//a.b = 10;
	
	B b;
	// ������ȫΪ����
	//b.a = 10;

	C c;
	// ����Ϊ˽�� ���ⲻ�ɷ���
	//c.a = 10;
}

/*
	�̳��е�˳��
		���๹�� > ���๹�� > �������� > ��������
*/


/*
	ͬ����Ա����
	�������ֱࣺ�ӷ���
	���ʸ��ࣺ��Ҫ���������
*/

class F {
public:
	int A;
	F() {
		A = 100;
	}
	void func() {
		cout << "����ĺ���" << endl;
	}
};
class Z :public F {
public:
	int A;
	Z() {
		A = 200;
	}
	void func() {
		cout << "����ĺ���" << endl;
	}
};

void F_t() {
	Z z;
	cout << z.A << endl;
	// ������ʸ���ͬ����Ա
	cout << z.F::A << endl;

	z.func();
	// ������÷���ͬ������ ʹ��������
	z.F::func();
}

// ͬ����̬��Ա�Ĵ���ʽ������ͬ

// ��̳� ʵ�ʿ���������ʹ��
class B_A {
public:
	int A;
	B_A() {
		A = 100;
	}
};
class B_B {
public:
	int B;
	B_B() {
		B = 200;
	}
};
class B_C :public B_A, public::B_B {
public:
	int C;
	B_C() {
		A = 1;
		//B = 2;
		C = 300;
	}
	void show() {
		cout << A << ":" << B << ":" << C << endl;
	}
};
void B_C_test() {
	B_C bc;
	bc.show();
};

/*
	���μ̳У�
	������̳�һ������
	һ����̳�����������
	���ײ���������
*/
class Animal {
public:
	int Age;
};
// ������̳� ������μ̳����� virtual
// �Ӷ�Animal��Ϊ�����
class Yang:virtual public Animal {

};
class Tuo :virtual public Animal {

};
class YangTuo :public Yang, public Tuo {

};
void YT_t() {
	YangTuo yt;
	// ���ֶ����� ��֪���̳��������Age
	//yt.Age = 18;
	yt.Tuo::Age = 28;
	yt.Yang::Age = 18;
	yt.Age = 666;
	cout << yt.Yang::Age << ":" << yt.Tuo::Age << ":" << yt.Age<< endl;
	// ������������ ��Դ�˷�
	// ��̳�ֻ����һ������ ������һ������
}

int main() {
	// ����̲� ����д̫���ظ���
	//ja_t();

	// �̳�
	//t_Base();

	// ͬ������
	//F_t();

	// ��̳�
	//B_C_test();

	// ���μ̳�
	YT_t();
	system("pause");
	return 0;
}

