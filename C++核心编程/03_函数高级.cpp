#include<iostream>
using namespace std;
#include<string>

// 1.����Ĭ�ϲ��� ����Ĭ�� �����޸�
void func(int a, int b = 20, int c = 30) {

	cout << a + b + c << endl;
}
// 2.�������������Ĭ�ϲ��� ��ô����ʵ�־Ͳ�����Ĭ�ϲ�����
// ������ʵ��ֻ����һ����Ĭ��
void func2(int a = 10, int b = 20);


// 3.������ռλ���� ֻ���������ͼ���ʵ��ռλ Ҳ����˵���ݲ�����ʱ�����Ҫ��
// ���Բ��� ���ǵ���
void func3(int a,int) {
	cout << "ռλ" << a << endl;
}

// 4.��������
/*
	��������ͬ ��߸����� 
	�������Ͳ�ͬ ������ͬ ����˳��ͬ

*/
void chongzai(int a, int b) {
	cout << "����1:" << a + b << endl;
}
void chongzai(int a, int b,int c) {
	cout << "����2:" << a + b + c<< endl;
}
void chongzai(int a, string b) {
	cout << "����3:" << b << endl;
}

/*
	ע�����
	1.������Ϊ���ص�����
		���ñ�����������õ�һ��
		�������ε��õڶ���
	2.ʹ�ú������ؾͱ���ʹ��Ĭ�ϲ��� Ҫ��Ȼ�������޷��ֱ�ʹ���ĸ��ͻᱨ��
*/
void zai(int& a) {
	cout << "func (&a):" << endl;
}
void zai(const int& a) {
	cout << "func (const &a):" << endl;
}


int main() {
	//func(10,1);

	//func2();

	//func3(10,1);

	/*chongzai(10,20);
	chongzai(10,20,30);
	chongzai(10,"������");*/

	int a = 10;
	zai(a);
	zai(10);



	system("pause");
	return 0;
}

void func2(int a, int b) {
	cout << a + b << endl;
}