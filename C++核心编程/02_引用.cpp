#include<iostream>
using namespace std;

// 引用 给变量起别名 修改会同时修改 地址不变
// 数据类型 &别名 = 原名 
/*
	1.使用需知 引用必须要初始化 必须得指向一个变量
	引用一旦初始化后 就不可以更改 让用的别名改成其他变量的别名
*/

/*
	2.引用做函数参数，
	利用引用让形参修改实参
	可以简化指针修改实参
*/
// 引用传递
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

/*
	引用作函数返回值
	1.不要返回局部变量的引用
	2.函数的调用可以作为左值
*/
int& test() {
	static int a = 10;
	return a;
}

/*
	常量引用 用来修饰形参 防止误操作
	在函数形参列表中，可以加const修饰形参，防止形参改变实参
*/
void showValue(const int& val) {
	//val = 1000;
	cout << "val == " << val << endl;
}
int main() {

	int a = 20;
	int& b = a;
	cout << a << endl;
	cout << b << endl;
	b = 10;
	cout << a << endl;
	cout << b << endl;

	int c = 10;
	int d = 20;
	// 引用传递
	swap(c, d);
	cout << c << endl;
	cout << d << endl;

	cout << "引用函数返回值" << endl;
	int& ref = test();
	cout << ref << endl;
	cout << ref << endl;
	// 函数作为左值 返回的是引用 修改值就相当于对变量做了引用
	test() = 1000;
	cout << ref << endl;
	cout << ref << endl;

	int val = 10;
	showValue(val);
	cout << "由于引用操作之后的val会背修改===,加上Const就会防止修改了" << val << endl;
	system("pause");
	return 0;
}