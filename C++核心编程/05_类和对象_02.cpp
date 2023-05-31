#include<iostream>
using namespace std;


// 二类函数默认都有 但是为空 
class Person {
public:
	int age;
	// 1.构造函数 程序初始化的时候进行调用
	// 无参构造
	Person() {
		cout << "构造函数调用" << endl;
	}
	// 有参构造
	Person(int a) {
		age = a;
		cout << "有参构造调用：a="<< a << endl;
	}
	// 拷贝构造函数
	Person(const Person &p) {
		// 将传入的人的属性 拷贝到当前人身上
		age = p.age;
		cout << "拷贝构造函数==》" << age << endl;
	}

	// 2.析构函数
	~Person() {
		cout << "析构函数调用" << endl;
	}
};


void test01() {
	
	// 1.括号法
	//Person p1;
	//Person p2(10);
	//Person p3(p2);
	// 使用默认构造函数的时候 不要加() 回认为是一个函数的声明 不会认为在创建对象
	//Person p1();


	// 2.显示法
	Person p1;
	// 有参构造
	Person p2 = Person(10);
	// 拷贝构造
	Person p3 = Person(p2);
	
	// 3.隐式转换法
	Person p4 = 10; // 相当于 Person p2 = Person(10);
	Person p5 = p4; // 拷贝构造
}

/*
* 	
	如果用户定义了有参构造函数 C++就不再提供默认的无参构造函数 但是会提供默认拷贝构造
	如果用户定义了拷贝构造函数 C++就不会再提供其他的构造函数
	
	构造函数的调用规则
	1.创建一个类 C++编译器会给每个类都添加至少三个函数
	默认构造 (空实现)
	析构函数 (空实现)
	拷贝构造 (值拷贝)
*/
class Person2 {
public:
	int Age;
	Person2() {
		cout << "Person的默认构造" << endl;
	}
	// 提供有参构造 就不会提供默认构造了 因此需要写默认构造
	Person2(int age) {
		Age = age;
		cout << "Person的有参函数构造" << Age << endl;
	}
	// 如果把构造函数注释了的话 默认会提供值拷贝，进行Age的传递
	// 如果用户定义了拷贝构造函数 C++就不会再提供其他的构造函数 需要自己提供 
	/*Person2(const Person2& p) {
		Age = p.Age;
		cout << "Person的拷贝函数构造" << Age << endl;
	}*/

	~Person2() {
		cout << "person的析构函数调用" << endl;
	}
};

void test() {
	Person2 p;
	p.Age = 18;
	Person2 p2(p);
	cout << "p2的年龄是:" << p2.Age << endl;
}
void test02() {
	Person2 p;
}


// 3.深拷贝与浅拷贝
class Person3 {
public:
	int Age;
	int* Height;
	Person3() {
		cout << "Person3的默认构造" << endl;
	}

	Person3(int age,int height) {
		Height = new int(height);
		Age = age;
		cout << "Person3的有参函数构造" << Age << endl;
	}

	/*Person2(const Person2& p) {
		Age = p.Age;
		cout << "Person的拷贝函数构造" << Age << endl;
	}*/

	~Person3() {
		// 析构代码 执行堆区数据的释放操作
		// 浅拷贝会引起堆区内存的重复释放 因此需要深拷贝
		if (Height != NULL) {
			delete Height;
			Height = NULL;
		}
		cout << "person的析构函数调用" << endl;
	}

	// 自己实现深拷贝
	Person3(const Person3 &p) {
		cout << "person3的拷贝函数调用" << endl;
		Age = p.Age;
		// 深拷贝操作
		Height = new int(*p.Height);
	}
};

void p3_test() {
	Person3 p1(18,160);
	cout << "p1的年龄" << p1.Age <<":" << *p1.Height << endl;
	// 浅拷贝 
	Person3 p2(p1);
	cout << "p2的年龄" << p2.Age << ":" << *p1.Height << endl;
}


/*	
	4.初始化列表
*/
class Car {
public:
	int A;
	int B;
	int C;

	// 传统初始化操作
	/*Car(int a, int b, int c) {
		A = a;
		B = b;
		C = c;
	}*/

	// 初始化列表赋初值
	Car(int a, int b, int c):A(a),B(b),C(c){}

};

void car() {
	//Car c(10, 20, 30);
	//cout << c.A << ":" << c.B << ":" << c.C << endl;

	Car c2(1,2,3);
	cout << c2.A << ":" << c2.B << ":" << c2.C << endl;
}

/*
	5.类对象作为类成员
*/

class Phone {
public:
	string p_name;
	Phone(string n) {
		cout << "Phone函数构造调用" << endl;
		p_name = n;
	}
};
class Person4 {
public:
	string name;
	Phone phone;

	Person4(string n, string pn):name(n),phone(pn) {
		cout << "person函数构造调用" << endl;
	}
};

void person4() {
	Person4 p("张三", "华为");
	cout << p.name << p.phone.p_name << endl;
}

int main() {
	// 1.构造函数的使用
	//test01();
	//Person p;
	
	// 2.构造函数的调用规则
	//test();
	// 提供有参构造 就不会提供默认构造了 因此需要写默认构造
	//test02();

	// 3.浅拷贝与深拷贝
	//p3_test();

	// 4.初始化列表
	//car();

	// 5.类对象作为类成员
	person4();

	system("pause");
	return 0;
}