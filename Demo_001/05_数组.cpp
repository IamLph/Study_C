#include <iostream>
using namespace std;
int main() {
	cout << "����\n\n";

	// ���鶨��1 ���峤��
	int arr[3];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	cout << arr[1] << endl;

	// ���鶨��2 ָ��ֵ
	int arr2[5] = { 1,2,3,4,6 };
	cout << arr2 << endl;

	// ���鶨��3 �ɱ䳤��
	int arr3[] = { 1,23,4,9 };
	cout << arr3[2] << endl;

	// ����������
	// 1.����ͳ���ڴ�ռ䳤�� sizeof() intΪ4�ֽ� 3������12�ֽ� 4��Ϊ16�ֽ�
	// 2.���Ի�ȡ�׵�ַ
	cout << "�ֽڳ���:" << sizeof(arr3) << endl;
	cout << "һ��Ԫ���ֽڳ���:" << sizeof(arr3[0]) << endl;
	cout << "�׵�ַ" << arr3 << endl;
	// ���4���ֽ�
	cout << "��һ��Ԫ���׵�ַ��ʹ��ȡַ����&��" << (int)&arr3[0] << endl;
	cout << "�ڶ���Ԫ���׵�ַ��ʹ��ȡַ����&��" << (int)&arr3[1] << endl;

	// ð������
	int arr4[] = { 63,5,1,3,45,32,26,48,92,125,6,3,7 };
	int len = sizeof(arr4) / sizeof(arr4[0]) - 1;
	cout << "���鳤��Ϊ: " << len << endl;
	cout << "��ʼ������������... " << endl;
	for (int i = 0; i < len -1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr4[j] > arr4[j+1]) {
				int temp = arr4[j];
				arr4[j] = arr4[j + 1];
				arr4[j + 1] = temp;
			}
		}
	}
	cout << "������� " << endl;
	for (int i = 0; i < len; i++) {
		cout << arr4[i] << endl;
	}


	// ��ά����

	/*
		���巽ʽ
		1. ���� ������[����][����]��
		2. ���� ������[����][����] = {{1��2}��{3��4}}��
		3. ���� ������[����][����] = {1��2��3��4}��
		4. ���� ������[][����] = {1��2��3��4}��
	*/
	// 1.
	int a[2][2];
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[i][j] << ",";
		}
		cout << "\n";
	}

	//2.
	int a2[2][2] = {
		{1,2},
		{3,4}
	};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a2[i][j] << ",";
		}
		cout << "\n";
	}
	//3.���Զ���������
	int a3[2][2] = { 1,2,3,4 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a3[i][j] << ",";
		}
		cout << "\n";
	}
	// 4.�Զ���������
	int a4[][2] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a4[i][j] << ",";
		}
		cout << "\n";
	}




	//������
	/*
		1.�鿴�ռ�ռ�ô�С sizeof 
		2.�鿴�׵�ַ
	*/
	cout << "�ڴ��С" <<sizeof(a4) << endl;
	cout << "��һ���ڴ��С" <<sizeof(a4[0]) << endl;
	cout << "��һ��Ԫ���ڴ��С" <<sizeof(a4[0][0]) << endl;
	cout << "�׵�ַ" << a4 << endl;
	cout << "�ڶ���Ԫ�ص�ַ" << &a4[0][1] << endl;
	system("pause");
	return 0;
}