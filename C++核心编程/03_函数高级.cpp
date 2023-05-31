#include<iostream>
using namespace std;
#include<string>

// 1.函数默认参数 无则默认 有则修改
void func(int a, int b = 20, int c = 30) {

	cout << a + b + c << endl;
}
// 2.如果函数声明有默认参数 那么函数实现就不能有默认参数了
// 声明和实现只能有一个有默认
void func2(int a = 10, int b = 20);


// 3.函数的占位参数 只用数据类型即可实现占位 也就是说传递参数的时候必须要传
// 可以不用 但是得有
void func3(int a,int) {
	cout << "占位" << a << endl;
}

// 4.函数重载
/*
	函数名相同 提高复用性 
	参数类型不同 个数不同 或者顺序不同

*/
void chongzai(int a, int b) {
	cout << "重载1:" << a + b << endl;
}
void chongzai(int a, int b,int c) {
	cout << "重载2:" << a + b + c<< endl;
}
void chongzai(int a, string b) {
	cout << "重载3:" << b << endl;
}

/*
	注意事项：
	1.引用作为重载的条件
		若用变量传参则调用第一个
		常量传参掉用第二个
	2.使用函数重载就避免使用默认参数 要不然编译器无法分辨使用哪个就会报错
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
	chongzai(10,"哈哈哈");*/

	int a = 10;
	zai(a);
	zai(10);



	system("pause");
	return 0;
}

void func2(int a, int b) {
	cout << a + b << endl;
}