#include <iostream>
using namespace std;
int main() {

	// �������� cin >> 
	// int a = 0;
	// cout << "������a����: " << endl;
	// cin >> a;
	// cout << a << endl;
	// ʵ������ cin >>
	// float f = 3.14f;
	// cout << "������f����: " << endl;
	// cin >> f;
	// cout << f << endl;
	// �������� char string ����.....

	// +-*/
	int a = 3;
	int b = 4;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;
	// ���ü�1 ������4 ���ǵ�ǰΪ3
	cout << a++ << endl;
	// ǰ�ü�1 �ȼ��ټ��� ���5 ֱ�����
	cout << ++a << endl;
	cout << a-- << endl;
	cout << --a << endl;

	// ��ֵ����
	cout << "��ֵ���� \n";

	int c = 10;
	int d = 2;
	c += 2;
	cout << c << endl;
	// �Ƚ������ == != < > <= >= ...

	// �߼������ !�� &&�� ||�� 

	// ˳�� ѡ�� ѭ���ṹ
	int flag = 1;
	cout << "����һ������: " << endl;
	//cin >> flag;
	flag = 1250;
	if (flag >= 200) {
		cout << "����200" << endl;
		if (flag > 900) {
			cout << "wocao!!" << endl;
		}
	}
	else if(flag >= 100 && flag < 200) {
		cout << "С��200����100" << endl;
	}
	else {
		cout << "С��100" << endl;
	}

	// ��Ŀ����� ���ʽ1 ? ���ʽ2:���ʽ3 
	// ���ص��Ǳ������Լ�����ֵ ������������޸�ֵ Ȼ����
	int x1 = 3;
	int x2 = 4;
	int x3 = 5;

	x3 = (x2 > x1 ? x1 : x2);
	cout << x3 << endl;

	// switch��� ���𻮷� break������֧
 	int s1 = 55;
	int s2 = 66;

	switch (s1)
	{
		case 1:
			cout << "1" << endl;
			break;
		case 55:
			cout << "��55" << endl;
			break;
		default:
			cout << "ɶҲ����" << endl;
			break;
	}
	// ѭ������
	int i = 0;
	while (i < 10) {
		cout << i++ << endl;
	}

	// ����� ���� 1-100
	int num = rand() % 100 + 1;
	cout << num << endl;

	// do{} while() ����ִ��һ��
	int n = 0;
	do {
		cout << n * n << endl;
		n++;
	} while (n < 10);

	// ˮ�ɻ��� 100-999

	int fl = 100;
	do {
		int a = 0;//��
		int b = 0;//ʮ
		int c = 0;//��
		a = fl % 100;
		b = fl / 10 % 10;
		c = fl / 100;
		if (a*a*a+b*b*b+c*c*c == fl) {
			cout << "ˮ�ɻ���:" << fl << endl;
		}
		fl++;
	} while (fl < 1000);

	// forѭ��
	for (int i = 0; i < 10;i++) {
		cout << i << endl;
	}

	// ��ת��� goto ����ð��ȷ�����
	goto FLLL;
	cout << "����ת" << endl;
	FLLL:
	cout << "��ת������" << endl;

	system("pause");
	return 0;
}