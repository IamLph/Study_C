#include<iostream>
#include<string>
using namespace std;

// 反面教材 这样写太多重复了
//class JAVA {
//public:
//	void header() {
//		cout << "JAVA首页" << endl;
//	}
//	void footer() {
//		cout << "JAVA脚" << endl;
//	}
//	void left() {
//		cout << "JAVA链接" << endl;
//	}
//	void content() {
//		cout << "JAVA视频" << endl;
//	}
//};
//
//
//
//class PYTHON {
//public:
//	void header() {
//		cout << "PYTHON首页" << endl;
//	}
//	void footer() {
//		cout << "PYTHON脚" << endl;
//	}
//	void left() {
//		cout << "PYTHON链接" << endl;
//	}
//	void content() {
//		cout << "PYTHON视频" << endl;
//	}
//};
//
//void ja_t() {
//	JAVA ja;
//	cout << "java信息" << endl;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//	cout << "PYTHON信息" << endl;
//	PYTHON py;
//	py.header();
//	py.footer();
//	py.left();
//	py.content();
//
//}

// 继承实现页面
// 公共页面
class BasePage {
public:
	void header() {
		cout << "首页" << endl;
	}
	void footer() {
		cout << "脚" << endl;
	}
	void left() {
		cout << "链接" << endl;
	}
	
};
class JAVA : public BasePage {
public:
	void content() {
		cout << "JAVA视频" << endl;
	}
};
class PYTHON : public BasePage {
public:
	void content() {
		cout << "PYTHON视频" << endl;
	}
};

void t_Base() {
	cout << "JAVA信息" << endl;
	JAVA ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "PYTHON信息" << endl;
	PYTHON py;
	py.header();
	py.footer();
	py.left();
	py.content();
}

// 2.继承方式 公共 私有 保护
class BASE {
public:
	int a;
protected:
	int b;
private:
	int c;
};
class A :public BASE {
	void func() {
		a = 10;
		// 到子类仍为保护权限
		b = 10;
		// 私有不可访问
		//c = 10;
	}
};
class B :protected BASE {
	void func() {
		// 到子类全为保护 都不可类外修改
		a = 10;
		b = 10;
		// 私有不可访问
		//c = 10;
	}
};
class C :private BASE {
	void func() {
		// 子类为私有 类外不可访问
		a = 10;
		b = 10;
		// 父类私有不可访问
		//c = 10;
	}
};
class CC :public C {
	void func() {
		// 父类私有，皆不可访问
		// a = 10;
		// b = 10;
	}
};

void abc_t() {
	A a;
	a.a = 10;
	// 到子类仍为保护权限
	//a.b = 10;
	
	B b;
	// 到子类全为保护
	//b.a = 10;

	C c;
	// 子类为私有 类外不可访问
	//c.a = 10;
}

/*
	继承中的顺序；
		父类构造 > 子类构造 > 子类析构 > 父类析构
*/


/*
	同名成员处理：
	访问子类：直接访问
	访问父类：需要添加作用域
*/

class F {
public:
	int A;
	F() {
		A = 100;
	}
	void func() {
		cout << "父类的函数" << endl;
	}
};
class Z :public F {
public:
	int A;
	Z() {
		A = 200;
	}
	void func() {
		cout << "子类的函数" << endl;
	}
};

void F_t() {
	Z z;
	cout << z.A << endl;
	// 子类访问父类同名成员
	cout << z.F::A << endl;

	z.func();
	// 子类调用夫类同名函数 使用作用域
	z.F::func();
}

// 同名静态成员的处理方式与上相同

// 多继承 实际开发不建议使用
class B_A {
public:
	int A;
	B_A() {
		A = 100;
	}
};
class B_B {
public:
	int B;
	B_B() {
		B = 200;
	}
};
class B_C :public B_A, public::B_B {
public:
	int C;
	B_C() {
		A = 1;
		//B = 2;
		C = 300;
	}
	void show() {
		cout << A << ":" << B << ":" << C << endl;
	}
};
void B_C_test() {
	B_C bc;
	bc.show();
};

/*
	菱形继承：
	两个类继承一个基类
	一个类继承两个派生类
	容易产生二义性
*/
class Animal {
public:
	int Age;
};
// 利用虚继承 解决菱形继承问题 virtual
// 从而Animal成为虚基类
class Yang:virtual public Animal {

};
class Tuo :virtual public Animal {

};
class YangTuo :public Yang, public Tuo {

};
void YT_t() {
	YangTuo yt;
	// 出现二义性 不知道继承自哪里的Age
	//yt.Age = 18;
	yt.Tuo::Age = 28;
	yt.Yang::Age = 18;
	yt.Age = 666;
	cout << yt.Yang::Age << ":" << yt.Tuo::Age << ":" << yt.Age<< endl;
	// 导致两份数据 资源浪费
	// 虚继承只会有一个数据 是最后的一份数据
}

int main() {
	// 反面教材 这样写太多重复了
	//ja_t();

	// 继承
	//t_Base();

	// 同名测试
	//F_t();

	// 多继承
	//B_C_test();

	// 菱形继承
	YT_t();
	system("pause");
	return 0;
}

