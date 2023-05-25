#include <iostream>
using namespace std;

/*
1.无参无返
2.有参无返
3.无参有返
4.有参有返
*/
// 定义函数
int getsum(int a,int b) {
	int sum = a + b;
	return sum;
}


// 函数声明
// 告诉编译器函数的名称以及如何调用函数 就是说声明的话，就可以把函数放在main()后面了
// 最新版本的Vs2022可以不用声明了
int max(int a,int b);



int main() {
	// 函数调用
	int sum = getsum(3, 4);
	cout << sum << endl;


	cout << max(66, 55) << endl;
	system("pause");
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}