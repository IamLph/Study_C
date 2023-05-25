#include <iostream>
using namespace std;
// 单行注释
/*
* 多行注释
*/

// 宏常量 不可修改全局的
#define PAI 3.14
int main()
{	
	// 变量
	int a = 10;
	cout << "HelloWolrd" << endl;
	cout << "a = " << a << endl;
	cout << "PAI = " << PAI << endl;
	// const 常量 亦不可修改
	const int month = 12;
	cout << "month = " << month << endl;
	//见于程序的末尾处，用于看运行结果，避免程序一闪而过
	system("pause");
	return 0;
}