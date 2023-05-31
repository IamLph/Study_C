#include<iostream>
using namespace std;
#include<string>
#define PI 3.14
#include"Cube.h"

/*
	1.封装
	设计圆类，求圆的周长
*/
class Circul {
	// 访问权限 公开
	public:
		// 属性
		int r;
		// 行为
		void getZhouchang() {
			cout << "周长为：" << 2 * PI * r << endl;
		}
};
/*
	设计学生类
*/
class Studnet {
public:
	string Name;
	int age;
	int sex;
	void getInfo() {
		cout <<"姓名:"<< Name <<"年龄:" << age <<"性别:"<< (sex == 0? "女":"男") << endl;
	}
	// 赋值操作 名称不可相同
	void setName(string name) {
		Name = name;
	}
};

/*
	封装权限：
	public		类内访问 类外可
	protected	类内访问 类外不可 儿子可以访问
	private		类内访问 类外不可 儿子不可访问
*/

class Person {
public:
	string name;
protected:
	int money;
private:
	int password;
// 类内访问
public:
	void func() {
		name = "张三";
		money = 100;
		password = 123456; 
		cout << name << ":" << money << ":" << password << endl;
	}
};
/*
	struct的默认权限为共有
	class的默认权限为私有
	实质无区别，都可以作为类使用
*/
class C1 {
	int m;
};
struct C2 {
	int m;
};


/*
	成员属性私有化 可以控制读写 写权限可以检测数据的有效性
	私有外部不可访问，可以通过类中的修改方法才行
*/
class Person2 {
private:
	string name;
	int age;
	string lover;
public:
	// name设置可读可写
	void steName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	// age设置只读
	int getAge() {
		age = 12;
		return age;
	}
	// lover只写
	void setLover(string love) {
		lover = love;
	}

};


/*
	例子：立方体类
	求立方体的面积和体积
	分别用全局函数和成员函数判断两个立方体是否相等
*/
//class Cube {
//private:
//	int L;
//	int W;
//	int H;
//public:
//	void setL(int l) {
//		L = l;
//	}
//	int getL() {
//		return L;
//	}
//	void setW(int w) {
//		W = w;
//	}
//	int getW() {
//		return W;
//	}
//	void setH(int h) {
//		H = h;
//	}
//	int getH() {
//		return H;
//	}
//	void S() {
//		cout << "面积" << L * W * 2 + L * H * 2 + W * H * 2 << endl;
//		cout << "体积" << L * W * H << endl;
//	}
//	// 成员函数
//	bool isSame(Cube& c2) {
//		if (L == c2.getL() && W == c2.getW() && H == c2.getH()) {
//			return true;
//		}
//		return false;
//	}
//};

// 全局函数判断是否相等
bool isSame(Cube& c1, Cube& c2) {
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		cout << "相同" << endl;
		return true;
	}
	cout << "不相同" << endl;
	return false;
}

int main() {
	// 实例化 创建对象
	/*Circul c1;
	c1.r = 1;
	c1.getZhouchang();
	Studnet s1;
	s1.setName("李四");
	s1.age = 12;
	s1.sex = 0;
	s1.getInfo();*/

	//Person p1;
	//p1.name = "66";
	//// 保护权限在类外不可访问
	////p1.money = 12;
	//// 私有权限在类外不可访问
	////p1.password = 123;
	//p1.func();


	// struct 与 class 的区别 权限问题
	/*C1 c1;
	c1.m = 12;
	C2 c2;
	c2.m = 12;*/

	/*Person2 p2;
	p2.steName("张三");
	cout << "姓名:" << p2.getName() << endl ;
	cout << "年龄:" << p2.getAge() << endl ;
	p2.setLover("月");*/

	Cube cu;
	cu.setH(10);
	cu.setW(10);
	cu.setL(10);
	cu.S();
	//Cube cu2;
	//cu2.setH(10);
	//cu2.setW(100);
	//cu2.setL(10);
	//bool result = isSame(cu, cu2);
	//if (result) {
	//	cout << "相同" << endl;
	//}
	//else {
	//	cout << "不相同" << endl;
	//}
	//cu2.isSame(cu);



	system("pause");
	return 0;
}