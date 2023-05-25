#include<iostream>
using namespace std;

#include "swap.h"
/*
	分文件步骤：
	1.创建.h后缀名的头文件
	2.创建.cpp后缀的源文件
	3.头文件中写函数的声明
	4.在源文件中写函数的定义
*/

int main() {

	swap(13, 14);
	system("pause");
	return 0;
}