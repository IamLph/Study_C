#include<iostream>
#include<string>
using namespace std;
/*
	运算符重载 对运算符号实现新的功能
*/

// 1.加号运算符
class Person {
public:
	int A;
	int B;
	// 1.成员函数重载
	// 本质是 Person p3 = p1.operator+(p2);
	/*Person operator+(Person& p) {
		Person temp;
		temp.A = this->A + p.A;
		temp.B = this->B + p.B;
		return temp;
	}*/
};
// 2.全局函数重载
// 本质是 Person p3 = operator+( p1,p2);
Person operator+(Person& p1,Person& p2) {
	Person temp;
	temp.A = p1.A + p2.A;
	temp.B = p1.B + p2.B;
	return temp;
}

void p_t() {
	Person p1;
	p1.A = 10;
	p1.B = 100;

	Person p2;
	p2.A = 10;
	p2.B = 10;

	Person p3 = p1 + p2;
	cout << p3.A << ":" << p3.B << endl;
}


// 2.左移运算符重载 可以输出自定义数据类型
class Person2 {
public:
	int A;
	int B;
	// 01.成员函数 无法重载左移 cout 会出现在右侧
	//Person2 operator<<(cout) {}
};
// 02.全局函数
ostream & operator<<(ostream &cout, Person2 &p) {
	cout << p.A << ":" << p.B << endl;
	return cout;
}

void p2_t() {
	Person2 p;
	p.A = 10;
	p.B = 20;
	//cout << p.A << ":" << p.B << endl;
	cout << p ;
}


// 3.递增运算符重载 可以实现自己的整型数据
class MyInterger {
	friend ostream& operator<<(ostream& cout, MyInterger p);

private:
	int m;
public:
	MyInterger() {
		m = 0;
	}
	// 重载前置运算符
	MyInterger& operator++() {
		m++;
		return *this;
	}
	// 后置递增
	MyInterger operator++(int) {
		MyInterger temp = *this;
		m++;
		return temp;
	}
};
ostream& operator<<(ostream& cout, MyInterger p) {
	cout << p.m << endl;
	return cout;
}

void mi_t() {
	MyInterger myint;
	cout << ++myint << endl;

	cout << myint++ << endl;
}


// 4.赋值运算符重载
class Person3 {
public:
	int* Age;
	Person3(int age) {
		Age = new int(age);
	}
	// 重载
	Person3& operator=(Person3 &p) {
		// 先判断是否有属性在堆区 如果有则先释放 之后再进行深拷贝
		if (Age != NULL) {
			delete Age;
			Age = NULL;
		}
		Age = new int(*p.Age);

		// 返回对象自身
		return *this;
	}

	~Person3() {
		if (Age != NULL) {
			delete Age;
			Age = NULL; 
		}
	}
};
void p3_t() {
	Person3 p1(18);
	Person3 p2(22);
	// 赋值操作
	p2 = p1;
	cout << *p1.Age << endl;
	cout << *p2.Age << endl;
}


// 5.关系运算符重载
class Person4 {
public:
	string Name;
	int Age; 
	Person4(string name, int age) {
		Name = name;
		Age = age;
	}
	bool operator==(Person4 &p) {
		if (this->Name == p.Name && this->Age == p.Age) {
			return true;
		}
		return false;
	}
	bool operator!=(Person4& p) {
		if (this->Name == p.Name && this->Age == p.Age) {
			return false;
		}
		return true;
	}
};

void p4_t() {
	Person4 p1("张三", 19);
	Person4 p2("李四", 17);
	if (p1 == p2) {
		cout << "同" << endl;
	}
	else if (p1 != p2) {
		cout << "不不Noooo!" << endl;
	}
	else {
		cout << "无法判断" << endl;
	}
}

// 6.函数调用运算符()重载 称为仿函数 没有固定写法，很灵活
class MyPrint {
public:
	// 重载函数运算符
	void operator()(string test) {
		cout << test << endl;
	}
	void operator()(int a,int b) {
		cout << a + b << endl;
	}
};
void mp_t() {
	MyPrint mp;
	mp("你好啊！！");
	mp(6,6);
}

int main() {
	// 加号运算符
	//p_t();

	// 左移运算符
	//p2_t();

	// 递增运算符
	//mi_t();

	// 赋值运算符重载
	//p3_t();

	// 关系运算符重载
	//p4_t();

	//重载函数
	mp_t();
	system("pause");
	return 0;
}