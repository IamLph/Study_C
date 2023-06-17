#include<iostream>
#include<string>
using namespace std;

/*
	����ģ��
	����һ��ͨ�ú��� �亯������ֵ���ͺ��β����Ϳ��Բ�����ָ��
	��һ�����������������
	template<typename T>
	������������
*/

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_t() {
	int a = 10;
	int b = 20;
	swap(a,b);
	cout << a << ":" << b << endl;
}

// ��������ģ�壬T��ͨ����������
//	template<typename T>
//  ������������
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void mySwap_t() {
	// ʹ�ú���ģ��

	// 1.�Զ������Ƶ�
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << a << ":" << b << endl;

	// 2.��ʾָ������
	mySwap<int>(a, b);
	cout << a << ":" << b << endl;
}
/*
	ע�����
	1.�Զ��Ƶ�  �������ͱ���һ�²���
	2.ģ�����ȷ����T���������� �ſ���ʹ��
	typename �����滻Ϊ class <T>
*/

// ��������ģ��
template<class T>
void sort_swap(T&a,T&b) {
	T temp = a;
	a = b;
	b = temp;
}


// ����ģ������ ѡ������
template<class T>
void sort(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (max != i) {
			// ����Ԫ��
			sort_swap(arr[max], arr[i]);
		}
	}
}

//��ӡ����ģ��
template<class T>
void print(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sort_t() {
	char charArr[] = "gabzxcnqmprleiuy";
	int len = sizeof(charArr) / sizeof(char);
	//cout << len;
	sort(charArr,len);
	print(charArr, len);


	// ����int
	int arr[] = {9,6,1,4,7,3,5,2,0};
	int num = sizeof(arr) / sizeof(int);
	sort(arr, num);
	print(arr, num);
}
/*
	��ͨ������ģ�庯��������
	1.��ͨ�������Է�����ʽ����ת��
	2.����ģ�� ���Զ������Ƶ� �����Է�����ʽ����ת��
	3.����ģ�� ����ʾָ������ ���Է�����ʽ����ת��
	
*/
// ��ͨ��
int add(int a,int b) {
	return a + b;
}
void add_t() {
	int a = 1;
	// 1.��ͨ�������Է�����ʽ����ת�� ��ʽת��ΪAscll��
	char c = 'A';
	//int b = 2;
	//cout << add(a, b) << endl;
	cout << add(a, c) << endl;
}

template<class T>
T t_add(T a,T b) {
	return a + b;
}
void t_add_t() {
	int a = 20;
	int b = 15;
	char c = 'c';
	cout << t_add(a, b) << endl;
	// 2.����ģ�� ���Զ������Ƶ� �����Է�����ʽ����ת��
	//cout << t_add(a, c) << endl;

	// 3.����ģ�� ����ʾָ������ ���Է�����ʽ����ת��
	cout << t_add<int>(a, c) << endl;
}

/*
	��ͨ�����뺯��ģ����ù���
	1���������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
	2������ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
	3������ģ����Է�����������
	4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
*/
void myPrint(int a, int b) {
	cout << "��ͨ" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "ģ��" << endl;
}
// 3������ģ����Է�����������
template<class T>
void myPrint(T a, T b,T c) {
	cout << "ģ������" << endl;
}

void myPrint_t() {
	int a = 20;
	int b = 15;
	int c = 15;
	myPrint(a, b);

	//2.����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
	myPrint<>(a, b);
	myPrint<>(a, b, c);

	//4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	// ��ͨ����Ҫת�� ģ�����ֱ���Ƴ�����
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);

}

int main() {
	// ��ͨ����
	//swap_t();

	// ģ�庯��
	//mySwap_t();

	// ������
	//sort_t();

	//add_t();
	//t_add_t();

	// ���ù���
	myPrint_t();
	system("pause");
	return 0;
}