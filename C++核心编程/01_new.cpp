#include<iostream>
using namespace std;

int* func() {
	// ����new�ؼ��� ���Խ����ݿ��ٵ�����
	// ָ�뱾��Ҳ�Ǿֲ����� ����ջ�� ָ�뱣��������Ƿ��ڶ�����
	// ���������ɳ���Ա���ٺ��ͷ�
	// ������������new�ؼ��ֽ��п����ڴ�
	int* p = new int(10);
	return p;
}

void test02() {

	// �������� �ڶ���
	int * arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	// �ͷŶ������� ��Ҫ���[]
	delete[] arr;
}

int main() {

	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	// �ͷ��ڴ� ֮����޷�ʹ����
	delete p;
	// cout << *p << endl;


	test02();

	system("pause");
	return 0;
}