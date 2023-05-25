#include<iostream>
using namespace std;

int main() {

	cout << "定义指针" << endl;
	int a = 10;
	// 定义指针 数据类型 * 指针变量
	int * p;
	// 指针变量记录变量a的地址
	p = &a;
	cout << p << endl;

	// 使用指针  *p 代表找到了内存中的数据 
	// 修改*p就会修改内存地址中的数据 会让原始变量也进行修改的
	// *p = 1000;
	cout << *p << endl;

	*p = 100;
	cout << "修改地址之后a:" << a << endl;
	// 修改之后地址不变数据改变
	cout << "修改地址之后P:" << p << endl;
	cout << "修改地址之后*P:" << *p << endl;

	// 32为操作系统 指针所占的内存都是4字节
	cout << "指针内存大小:" << sizeof(*p) << endl;
	/*
		空指针:
			指针变量指向内存中编号为0的空间 00000000
			用于初始化指针变量
			空指针指向的内存是不可以访问的！也不可以写入数据 
			0~255内存编号是系统占用的，不可以访问
	*/
	int *q = NULL;

	cout << "空指针:" << q << endl;

	//引发了异常: 读取访问权限冲突。 q 是 nullptr。
	// cout << "访问出错: " << *q << endl;


	// 野指针：指针变量指向非法的内存空间 没有申请地址 非要访问 就会出错
	int* y = (int *)0x1100;
	// 直接报错
	// cout << *y << endl;

	/*
		const修饰指针：
		1.修饰指针 --常量指针 
			指针的指向可以改，但是指向的值不可以改
		2.修饰常量 --指针常量
			指针的值可以改，但是指向不可以改
		3.即修饰指针又修饰常量
			都不可以改
	*/
	// 1. 常量指针 
	int a1 = 10;
	int b1 = 100;
	const int* pp = &a1;
	cout << "常量指针：" << endl;
	cout << *pp << endl;
	pp = &b1;
	cout << "修改指针的指向:" <<  * pp << endl;
	// 指针指向的值不可以改
	// * pp = 1000;

	// 2.指针常量
	int a2 = 10;
	int b2 = 100;
	int* const p2 = &a;
	cout << "指针常量" << endl;
	cout << *p2 << endl;
	*p2 = 101;
	cout << *p2 << endl;
	// 指针的指向不可以改
	// p2 = &b2;


	// 3.
	int a3 = 10;
	int b3 = 100;
	const int* const p3 = &a;
	cout << "指针常量" << endl;
	cout << *p3 << endl;
	// 不可修改
	// * p3 = 101;
	// p3 = &b3;
	cout << *p3 << endl;

	// 指针与数组
	int arr[] = { 1,2,34,56,7,8 };

	cout << "第一个元素："<< arr[0] << endl;

	int* ar = arr;
	// cout << "指针第一个元素" << *ar << endl;
	// ar++;
	// cout << "指针第二个元素" << *ar << endl;

	// 指针遍历
	for (int i = 0; i < 5; i++) {
		ar++;
		cout << "指针第"<< i <<"个元素" << *ar << endl;
	}




	system("pause");

	return 0;
}