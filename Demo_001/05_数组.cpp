#include <iostream>
using namespace std;
int main() {
	cout << "数组\n\n";

	// 数组定义1 定义长度
	int arr[3];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	cout << arr[1] << endl;

	// 数组定义2 指定值
	int arr2[5] = { 1,2,3,4,6 };
	cout << arr2 << endl;

	// 数组定义3 可变长度
	int arr3[] = { 1,23,4,9 };
	cout << arr3[2] << endl;

	// 数组名作用
	// 1.可以统计内存空间长度 sizeof() int为4字节 3个就是12字节 4个为16字节
	// 2.可以获取首地址
	cout << "字节长度:" << sizeof(arr3) << endl;
	cout << "一个元素字节长度:" << sizeof(arr3[0]) << endl;
	cout << "首地址" << arr3 << endl;
	// 相差4个字节
	cout << "第一个元素首地址，使用取址符号&：" << (int)&arr3[0] << endl;
	cout << "第二个元素首地址，使用取址符号&：" << (int)&arr3[1] << endl;

	// 冒泡排序
	int arr4[] = { 63,5,1,3,45,32,26,48,92,125,6,3,7 };
	int len = sizeof(arr4) / sizeof(arr4[0]) - 1;
	cout << "数组长度为: " << len << endl;
	cout << "开始进行升序排序... " << endl;
	for (int i = 0; i < len -1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr4[j] > arr4[j+1]) {
				int temp = arr4[j];
				arr4[j] = arr4[j + 1];
				arr4[j + 1] = temp;
			}
		}
	}
	cout << "排序完成 " << endl;
	for (int i = 0; i < len; i++) {
		cout << arr4[i] << endl;
	}


	// 二维数组

	/*
		定义方式
		1. 类型 数组名[行数][列数]；
		2. 类型 数组名[行数][列数] = {{1，2}，{3，4}}；
		3. 类型 数组名[行数][列数] = {1，2，3，4}；
		4. 类型 数组名[][列数] = {1，2，3，4}；
	*/
	// 1.
	int a[2][2];
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[i][j] << ",";
		}
		cout << "\n";
	}

	//2.
	int a2[2][2] = {
		{1,2},
		{3,4}
	};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a2[i][j] << ",";
		}
		cout << "\n";
	}
	//3.会自动区分行列
	int a3[2][2] = { 1,2,3,4 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a3[i][j] << ",";
		}
		cout << "\n";
	}
	// 4.自动划分行数
	int a4[][2] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a4[i][j] << ",";
		}
		cout << "\n";
	}




	//数组名
	/*
		1.查看空间占用大小 sizeof 
		2.查看首地址
	*/
	cout << "内存大小" <<sizeof(a4) << endl;
	cout << "第一行内存大小" <<sizeof(a4[0]) << endl;
	cout << "第一个元素内存大小" <<sizeof(a4[0][0]) << endl;
	cout << "首地址" << a4 << endl;
	cout << "第二个元素地址" << &a4[0][1] << endl;
	system("pause");
	return 0;
}