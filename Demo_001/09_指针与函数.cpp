#include<iostream>
using namespace std;


void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << "������" << a << "---" << b << endl;
}

void swap2(int *p,int *p2) {
	int temp = *p;
	*p = *p2;
	*p2 = temp;
	cout << "��ַ������" << *p << "---" << *p2 << endl;
}
int main() {

	int a = 3;
	int b = 4;
	//1.ֵ����
	swap(a, b);
	cout << "ʵ�Σ�" << a << "---" << b << endl;
	// 2.��ַ���� ���޸�ʵ��
	// int* p1 = &a;
	// int* p2 = &b;
	swap2(&a, &b);
	cout << "�޸�ʵ�Σ�" << a << "---" << b << endl;

	system("pause");
	return 0;
}