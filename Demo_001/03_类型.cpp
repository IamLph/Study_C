#include <iostream>
using namespace std;
#include <string>
int main() {

	// sizeof 关键字 查看字节数量
	cout << "int size 4:" << sizeof(int) << endl;
	cout << "int size 2:" << sizeof(short) << endl;
	cout << "int size 4:" << sizeof(long) << endl;
	cout << "int size 8:" << sizeof(long long) << endl;
	// 实型 float 4字节 double 8字节 加f表示单精度 否则默认为双精度
	float a1 = 3.14f;
	double a2 = 3.1415926539;
	cout << a1 << ":" << sizeof(a1) << endl;
	cout << a2 << ":" << sizeof(a2) <<  endl;

	// 科学计数法
	float f1 = 3e2; // 3 * 10^2 == 300
	//float f1 = 3e-2; // 3 * 0.1^2 == 0.03
	cout << f1 << endl;


	// 字符型 使用单引号 1字节
	char c1 = 'a';
	cout << c1 << endl;
	// 转化为对应的ASCII编码 97
	cout << int(c1) << endl;


	// 转义字符 \n:换行 \\:输出反斜杠  \t制表符号 等等 可以自己去找
	cout << "hello wolrd \n";
	cout << "12" << endl;;


	// 字符串
	// 1.char 变量名[] = "*******"
	// 1.string 变量名 = "*******" 需要头文件 #include <string>
	char ch1[] = "ABCDEFG";
	cout << ch1 << endl;
	string ch2 = "GFDSA";
	cout << ch2 << endl;

	// 布尔类型 1字节 非0为真
	bool flag = true;
	cout << flag << endl;



	system("pause");
	return 0;
}