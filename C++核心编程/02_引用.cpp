#include<iostream>
using namespace std;

// ���� ����������� �޸Ļ�ͬʱ�޸� ��ַ����
// �������� &���� = ԭ�� 
/*
	1.ʹ����֪ ���ñ���Ҫ��ʼ�� �����ָ��һ������
	����һ����ʼ���� �Ͳ����Ը��� ���õı����ĳ����������ı���
*/

/*
	2.����������������
	�����������β��޸�ʵ��
	���Լ�ָ���޸�ʵ��
*/
// ���ô���
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

/*
	��������������ֵ
	1.��Ҫ���ؾֲ�����������
	2.�����ĵ��ÿ�����Ϊ��ֵ
*/
int& test() {
	static int a = 10;
	return a;
}

/*
	�������� ���������β� ��ֹ�����
	�ں����β��б��У����Լ�const�����βΣ���ֹ�βθı�ʵ��
*/
void showValue(const int& val) {
	//val = 1000;
	cout << "val == " << val << endl;
}
int main() {

	int a = 20;
	int& b = a;
	cout << a << endl;
	cout << b << endl;
	b = 10;
	cout << a << endl;
	cout << b << endl;

	int c = 10;
	int d = 20;
	// ���ô���
	swap(c, d);
	cout << c << endl;
	cout << d << endl;

	cout << "���ú�������ֵ" << endl;
	int& ref = test();
	cout << ref << endl;
	cout << ref << endl;
	// ������Ϊ��ֵ ���ص������� �޸�ֵ���൱�ڶԱ�����������
	test() = 1000;
	cout << ref << endl;
	cout << ref << endl;

	int val = 10;
	showValue(val);
	cout << "�������ò���֮���val�ᱳ�޸�===,����Const�ͻ��ֹ�޸���" << val << endl;
	system("pause");
	return 0;
}