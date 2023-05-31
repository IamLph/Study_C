#include<iostream>
using namespace std;

int* func() {
	// 利用new关键字 可以将数据开辟到堆区
	// 指针本质也是局部变量 放在栈区 指针保存的数据是放在堆区的
	// 堆区数据由程序员开辟和释放
	// 堆区数据利用new关键字进行开辟内存
	int* p = new int(10);
	return p;
}

void test02() {

	// 创建数组 在堆区
	int * arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	// 释放堆区数组 需要添加[]
	delete[] arr;
}

int main() {

	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	// 释放内存 之后就无法使用了
	delete p;
	// cout << *p << endl;


	test02();

	system("pause");
	return 0;
}