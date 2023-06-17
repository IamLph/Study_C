#include<iostream>
#include<string>
using namespace std;

/*
	函数模板
	建立一个通用函数 其函数返回值类型和形参类型可以不具体指定
	用一个虚拟的类型来代表
	template<typename T>
	函数声明或定义
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

// 声明函数模板，T是通用数据类型
//	template<typename T>
//  函数声明或定义
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void mySwap_t() {
	// 使用函数模板

	// 1.自动类型推导
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << a << ":" << b << endl;

	// 2.显示指定类型
	mySwap<int>(a, b);
	cout << a << ":" << b << endl;
}
/*
	注意事项：
	1.自动推导  数据类型必须一致才行
	2.模板必须确定出T的数据类型 才可以使用
	typename 可以替换为 class <T>
*/

// 交换函数模板
template<class T>
void sort_swap(T&a,T&b) {
	T temp = a;
	a = b;
	b = temp;
}


// 函数模板排序 选择排序
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
			// 交换元素
			sort_swap(arr[max], arr[i]);
		}
	}
}

//打印数组模板
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


	// 测试int
	int arr[] = {9,6,1,4,7,3,5,2,0};
	int num = sizeof(arr) / sizeof(int);
	sort(arr, num);
	print(arr, num);
}
/*
	普通函数与模板函数的区别
	1.普通函数可以发生隐式类型转换
	2.函数模板 用自动类型推导 不可以发生隐式类型转换
	3.函数模板 用显示指定类型 可以发生隐式类型转换
	
*/
// 普通的
int add(int a,int b) {
	return a + b;
}
void add_t() {
	int a = 1;
	// 1.普通函数可以发生隐式类型转换 隐式转换为Ascll码
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
	// 2.函数模板 用自动类型推导 不可以发生隐式类型转换
	//cout << t_add(a, c) << endl;

	// 3.函数模板 用显示指定类型 可以发生隐式类型转换
	cout << t_add<int>(a, c) << endl;
}

/*
	普通函数与函数模板调用规则
	1、如果函数模板和普通函数都可以调用，优先调用普通函数
	2、可以通过空模板参数列表 强制调用 函数模板
	3、函数模板可以发生函数重载
	4、如果函数模板可以产生更好的匹配，优先调用函数模板
*/
void myPrint(int a, int b) {
	cout << "普通" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "模板" << endl;
}
// 3、函数模板可以发生函数重载
template<class T>
void myPrint(T a, T b,T c) {
	cout << "模板重载" << endl;
}

void myPrint_t() {
	int a = 20;
	int b = 15;
	int c = 15;
	myPrint(a, b);

	//2.可以通过空模板参数列表 强制调用 函数模板
	myPrint<>(a, b);
	myPrint<>(a, b, c);

	//4、如果函数模板可以产生更好的匹配，优先调用函数模板
	// 普通的需要转换 模板可以直接推出类型
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);

}

int main() {
	// 普通函数
	//swap_t();

	// 模板函数
	//mySwap_t();

	// 排序案例
	//sort_t();

	//add_t();
	//t_add_t();

	// 调用规则
	myPrint_t();
	system("pause");
	return 0;
}