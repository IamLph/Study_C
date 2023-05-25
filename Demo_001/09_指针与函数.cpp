#include<iostream>
using namespace std;


void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << "交换：" << a << "---" << b << endl;
}

void swap2(int *p,int *p2) {
	int temp = *p;
	*p = *p2;
	*p2 = temp;
	cout << "地址交换：" << *p << "---" << *p2 << endl;
}
int main() {

	int a = 3;
	int b = 4;
	//1.值传递
	swap(a, b);
	cout << "实参：" << a << "---" << b << endl;
	// 2.地址传递 会修改实参
	// int* p1 = &a;
	// int* p2 = &b;
	swap2(&a, &b);
	cout << "修改实参：" << a << "---" << b << endl;

	system("pause");
	return 0;
}