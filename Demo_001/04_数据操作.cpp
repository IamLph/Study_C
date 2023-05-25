#include <iostream>
using namespace std;
int main() {

	// 整型输入 cin >> 
	// int a = 0;
	// cout << "请输入a数据: " << endl;
	// cin >> a;
	// cout << a << endl;
	// 实型输入 cin >>
	// float f = 3.14f;
	// cout << "请输入f数据: " << endl;
	// cin >> f;
	// cout << f << endl;
	// 其他类型 char string 布尔.....

	// +-*/
	int a = 3;
	int b = 4;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;
	// 后置加1 后面变成4 但是当前为3
	cout << a++ << endl;
	// 前置加1 先加再计算 变成5 直接输出
	cout << ++a << endl;
	cout << a-- << endl;
	cout << --a << endl;

	// 赋值运算
	cout << "赋值运算 \n";

	int c = 10;
	int d = 2;
	c += 2;
	cout << c << endl;
	// 比较运算符 == != < > <= >= ...

	// 逻辑运算符 !非 &&与 ||或 

	// 顺序 选择 循环结构
	int flag = 1;
	cout << "输入一个数字: " << endl;
	//cin >> flag;
	flag = 1250;
	if (flag >= 200) {
		cout << "大于200" << endl;
		if (flag > 900) {
			cout << "wocao!!" << endl;
		}
	}
	else if(flag >= 100 && flag < 200) {
		cout << "小于200大于100" << endl;
	}
	else {
		cout << "小于100" << endl;
	}

	// 三目运算符 表达式1 ? 表达式2:表达式3 
	// 返回的是变量可以继续赋值 就是最后重新修改值 然并卵
	int x1 = 3;
	int x2 = 4;
	int x3 = 5;

	x3 = (x2 > x1 ? x1 : x2);
	cout << x3 << endl;

	// switch语句 级别划分 break跳出分支
 	int s1 = 55;
	int s2 = 66;

	switch (s1)
	{
		case 1:
			cout << "1" << endl;
			break;
		case 55:
			cout << "是55" << endl;
			break;
		default:
			cout << "啥也不是" << endl;
			break;
	}
	// 循环条件
	int i = 0;
	while (i < 10) {
		cout << i++ << endl;
	}

	// 随机数 生成 1-100
	int num = rand() % 100 + 1;
	cout << num << endl;

	// do{} while() 即先执行一次
	int n = 0;
	do {
		cout << n * n << endl;
		n++;
	} while (n < 10);

	// 水仙花数 100-999

	int fl = 100;
	do {
		int a = 0;//个
		int b = 0;//十
		int c = 0;//百
		a = fl % 100;
		b = fl / 10 % 10;
		c = fl / 100;
		if (a*a*a+b*b*b+c*c*c == fl) {
			cout << "水仙花数:" << fl << endl;
		}
		fl++;
	} while (fl < 1000);

	// for循环
	for (int i = 0; i < 10;i++) {
		cout << i << endl;
	}

	// 跳转语句 goto 后面冒号确定标记
	goto FLLL;
	cout << "被跳转" << endl;
	FLLL:
	cout << "跳转过来了" << endl;

	system("pause");
	return 0;
}