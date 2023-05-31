#include<iostream>
using namespace std;

// 静态成员 所有成员共享一份数据
class Person {
public:
	// 1.静态变量 所有对象共享
	// 2.编译的时候就分配内存
	// 3.需要类内声明 类外初始化操作
	static int A;
// 私有静态成员 类外无法访问
private:
	static int B;
};
// 需要类内声明 类外初始化操作
int Person::A = 100;
int Person::B = 200;

void test() {
	Person p;
	cout << p.A << endl;
	Person p1;
	// 共享数据 一个修改 其他也会修改
	p1.A = 200;
	cout << p.A << endl;
}
void test02() {
	// 1.通过对象进行访问
	Person p;
	cout << p.A << endl;
	//cout << p.B << endl;

	// 2.通过类名进行访问
	cout << Person::A << endl;
	// 私有无法访问
	//cout << Person::B << endl;
}



/*
	静态成员函数
	所有对象共享
	静态成员函数只能访问静态成员变量
*/
class Person2 {
public:
	static void func() {
		p2_A = 100;
		// 非静态的成员变量无法访问
		//p2_B = 200;
		cout << "static void func调用" << endl;
	}
	static int p2_A;
	int p2_B;
private:
	static void func2() {
		cout << "static void func2调用" << endl;
	}
};
int Person2::p2_A = 666;
void p2_t() {
	// 1.通过对象访问
	Person2 p;
	p.func();
		
	// 2.通过类名访问
	Person2::func();
	// 私有类外无法访问
	//Person2::func2();

}

/*
	成员函数和成员变量分开存储
*/

class Car {
	int A;
	// 静态成员变量 不属于类对象上
	static int car_B;
	// 非静态成员函数 亦不属于类对象上
	void func() {
		// 空间
	}
};
int Car::car_B = 20;
void car_t() {
	Car c;
	// sizeof  空对象占用内存为1 非空则为变量占用的内存，不用这个1了
	cout << sizeof(c) << endl;
}

/*
	this指针
*/
class PP {
public:
	int age;
	PP(int age) {
		this->age = age;
	}
	// 不用&的话就会成为拷贝函数 无法返回内存本身 是一个新的对象
	PP& PPadd(PP &p) {
		this->age += p.age;
		return *this;
	}
};
// 1.用于解决命名冲突
void PP_t() {
	PP p(18);
	cout << "p_age" << p.age << endl;
}
// 2.返回对象本身用 *this
void PP_t2() {
	PP p1(10);
	PP p2(10);
	//p2.PPadd(p1);
	p2.PPadd(p1).PPadd(p1).PPadd(p1).PPadd(p1).PPadd(p1);
	cout << p2.age << endl;
}


/*
	空指针访问成员函数
*/
class AA {
public:
	int Age;
	void showClassName() {
		cout << "this is AA class " << endl;
	}
	void showAge() {
		if (this == NULL) {
			cout << "this is a null point" << endl;
			return;
		}
		cout << "this age = " <<Age << endl;
	}
};
void AA_t() {
	AA* a = NULL;
	a->showClassName();
	// 空指针无法找到age 还要访问成员就会报错
	a->showAge();
}

/*
	const修饰成员函数
	常函数：
		成员函数后加const后我们称为这个函数为常函数
		常函数内不可以修改成员属性I
		成员属性声明时加关键字mutable后，在常函数中依然可以修改
	常对象：
		声明对象前加const称该对象为常对象
		常对象只能调用常函数
*/
class BB {
public:
	int A; 
	// 特殊变量 可以在常函数中修改其值
	mutable int B;
	/*
		BB * const this;
		this的本质是指针常量 指向不可修改 但是值可以修改
		若想让指针的值也不可以修改 则为 const BB * const this;
		需要选择const的位置 在函数()后面 修饰的是this指针
	*/
	void show() const {
		//A = 100;
		//this->A = 100;
		//cout << A << endl; 
		
		this->B = 100;
		cout << B << endl; 
	}
	void s() {
		cout << "普通函数" << endl;
	}
};
void bb_t() {
	BB b;
	b.show();
}
// 常对象 其属性不可修改 除非加了 mutable

void bb_t2() {
	const BB b;
	//b.A = 100;
	b.B = 99;
	b.show();
	// 常对象只能调用常函数
	//b.s();
}
int main() {
	// 静态成员
	//test();
	// 访问方式
	//test02();

	// 静态函数
	//p2_t();


	// 成员函数和成员变量分开存储
	//car_t();

	// this指针 
	//PP_t();
	//PP_t2();

	// 空指针访问成员函数
	//AA_t();

	// const修饰成员函数
	bb_t();

	system("pause");
	return 0;
}