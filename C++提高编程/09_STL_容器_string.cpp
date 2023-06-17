#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// string本质上是一个类
void test01() {
	// 默认构造
	string s1;

	const char* str = "Hello World";
	// 有参构造
	string s2(str);
	// 拷贝构造
	string s3(s2);
	// 初始化10个a
	string s4(10,'a');

	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
}

void test02() {
	string s1 = "HelloWolrd";
	cout << "s1 = " << s1 << endl;

	string s2 = s1;
	cout << "s2 = " << s2 << endl;

	string s3;
	s3 = 'a';
	cout << "s3 = " << s3 << endl;

	string s4;
	s4.assign("Hello Assign");
	cout << "s4 = " << s4 << endl;

	// 字符串的前n个字符赋值给当前的字符串
	string s5;
	s5.assign("I Love my", 6);
	cout << "s5 = " << s5 << endl;

	// 将n个字符c赋值给当前字符串
	string s6;
	s6.assign(6, '6');
	cout << "s6 = " << s6 << endl;

	string s7;
	s7.assign(s6);
	cout << "s7 = " << s7 << endl;
}

// 字符串拼接
void test03() {
	string s1 = "I";
	s1 += "Love";
	cout << "s1 = " << s1 << endl;
	// 追加字符
	s1 += ":";
	cout << "s1 = " << s1 << endl;
	// 追加字符串
	string s2 = "Wmy";
	s1 += s2;
	cout << "s1 = " << s1 << endl;

	string s3 = "I";
	s3.append(" love ");
	cout << "s3 = " << s3 << endl;
	// 追加字符串的前n个字符
	s3.append("Wmy I Love", 3);
	cout << "s3 = " << s3 << endl;
	// 追加字符串
	s3.append(s1);
	cout << "s3 = " << s3 << endl;
	// 从字符串的pos位置开始截n个字符到末尾
	s3.append("1234567", 1, 4);
	cout << "s3 = " << s3 << endl;

}

void test04() {
	string str1 = "abcdeafasde";
	// find 查找第一次出现的位置 没有就返回-1
	int pos = str1.find("de");
	cout << "find位置: " << pos << endl;


	// rfind 区别 find左往右 rfind从右往左
	int pos2 = str1.rfind("de");
	cout << "rfind位置: " << pos2 << endl;

	// 替换
	string str2 = "abcdefghijklmn";
	// 1-3号字符替换 3个替换为n个
	str2.replace(1, 3, "666777");
	cout << "替换后:" <<  str2 << endl;

}

void test05() {
	string s1 = "zbc";
	string s2 = "abc";
	// 比较Ascll码
	char a = (s1.compare(s2) == 0) ? 'Y' : 'N';
	cout << a << endl;

	char b = (s1.compare(s2) > 0) ? 'Y' : 'N';
	cout << b << endl;

	char c = (s1.compare(s2) < 0) ? 'Y' : 'N';
	cout << c << endl;

}
void test06() {
	string s1 = "hello world!";
	cout << s1 << endl;

	// 访问字符 方式1
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";
	}
	cout << endl;
	// 访问字符 方式2
	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << " ";
	}
	cout << endl;
	// 修改单个字符
	s1[0] = 'I';
	cout << s1 << endl;
	s1.at(1) = 'L';
	cout << s1 << endl;
}

void test07() {
	string s1 = "hello";
	// 插入
	s1.insert(1, "666");
	cout << s1 << endl;
	// 删除
	s1.erase(1, 3);
	cout << s1 << endl;

}
void test08() {
	string s1 = "Hello Wolrd!";

	// 从一号位置开始截取三个
	string sub = s1.substr(1, 3);
	cout << sub << endl;

	string s2 = "hello@163.com";
	// 获取用户名信息
	int pos = s2.find("@");
	string name = s2.substr(0, pos);
	cout << name << endl;


}
int main() {
	// string本质上是一个类 构造方法
	//test01();

	// 赋值操作
	//test02();

	// 字符串拼接
	//test03();

	// 字符串替换和查找
	//test04();

	// 字符串比较
	//test05();
	 
	// 字符存取
	// test06();

	// 字符串插入与删除
	//test07();

	// 字串获取
	test08();


	system("pause");
	return 0;
}