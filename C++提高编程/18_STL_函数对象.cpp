#include<iostream>
#include<string>
using namespace std;
/*
		���غ������ò��������࣬����󳣳�Ϊ��������
		��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���
		��������(�º���)��һ���࣬����һ������
	�ص�:
		����������ʹ��ʱ����������ͨ������������,�����в����������з���ֵ
		�������󳬳���ͨ�����ĸ����������������Լ���״̬.
		�������������Ϊ��������
*/

class MyAdd {
public:
	int operator()(int v1,int v2) {
		return v1 + v2;
	}
};

void test01() {
	MyAdd myadd;
	cout << myadd(10, 12) << endl;
}

class MyPrint {
public:
	// �ڲ��Լ���״̬
	int count;
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}
	MyPrint() {
		this->count = 0;
	}
};

void test02() {
	MyPrint mp;
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	cout << "���ô���:" << mp.count << endl;
}
void DoPrint(MyPrint &mp,string test) {
	mp(test);
}
void test03() {
	MyPrint mp;
	DoPrint(mp, "���!");
}
int main() {
	// ����������ʹ��ʱ����������ͨ������������,�����в����������з���ֵ
	test01();

	// �������󳬳���ͨ�����ĸ����������������Լ���״̬.
	test02();

	// �������������Ϊ��������
	test03();
	system("pause");
	return 0;
}