#include <iostream>
using namespace std;

/*
1.�޲��޷�
2.�в��޷�
3.�޲��з�
4.�в��з�
*/
// ���庯��
int getsum(int a,int b) {
	int sum = a + b;
	return sum;
}


// ��������
// ���߱����������������Լ���ε��ú��� ����˵�����Ļ����Ϳ��԰Ѻ�������main()������
// ���°汾��Vs2022���Բ���������
int max(int a,int b);



int main() {
	// ��������
	int sum = getsum(3, 4);
	cout << sum << endl;


	cout << max(66, 55) << endl;
	system("pause");
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}