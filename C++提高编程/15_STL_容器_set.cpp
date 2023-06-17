#include<iostream>
#include<set>
#include<string>
using namespace std;
/*
	set容器在插入容器时会自动排序
	set/multiset属于关联式容器 底层为二叉树结构
	set 不允许有重复的数据
	multiset 允许重复的数据
*/
void print(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test01() {
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(54);
	s.insert(34);
	s.insert(31);
	// 会将重复的数据去除
	s.insert(31);
	print(s);
	// 自动排序---> 2 3 31 34 54 
	
	// 拷贝构造
	set<int> s2(s);
	print(s2);

	// 赋值操作
	set<int>s3;
	s3 = s2;
	print(s3);
}

void test02() {
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(54);
	s.insert(34);
	s.insert(31);

	if (s.empty()) {
		cout << "空" << endl;
	}
	else {
		cout << "数目为:" << s.size() << endl;
	}
	set<int> s2;
	s2.insert(6);
	s2.insert(7);
	s2.insert(8);
	s2.insert(9);
	cout << "交换前:" << endl;
	print(s);
	print(s2);
	s2.swap(s);
	cout << "交换后:" << endl;
	print(s);
	print(s2);
}

void test03() {
	set<int>s;
	
	// 插入
	s.insert(11);
	s.insert(23);
	s.insert(3);
	s.insert(67);
	print(s);

	// 删除 会删除最小的哪个 因为自动排序（升序）了
	s.erase(s.begin());
	print(s);

	// 删除指定数字
	s.erase(11);
	print(s);

	// 清空1
	s.erase(s.begin(), s.end());
	print(s);

	s.insert(11);
	s.insert(23);
	s.insert(3);
	s.insert(67);
	print(s);
	// 清空2
	s.clear();
	print(s);
}

void test04() {
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	s.insert(7);

	// 查找元素是否存在 返回迭代器
	set<int>::iterator pos = s.find(2);
	if (pos != s.end()) {
		cout << "找到: " << *pos << endl;
	}
	else {
		cout << "未找到！" << endl;
	}
	// 统计指定元素个数 可以用来判断元素是否存在
	int num = s.count(7);
	cout << "指定元素个数: " << num << endl;
}

void test05() {
	set<int> s;
	/*
	*	insert 返回类型为 _Pairib pair<iterator,bool>
	*	返回的是对组 插入的时候就会返回插入结果 是否成功
	*/
	pair<set<int>::iterator,bool> ret = s.insert(10);
	if (ret.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "插入失败" << endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "插入失败" << endl;
	}
	/*
	*	insert 返回类型为 iterator 迭代器 不会判断是否插入成功
	*	只要可以插入就插
	*	也会自动排序
	*/
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(9);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}

void test06() {
	// 1.默认构造
	pair<string, int>p("Tom", 13);
	cout << p.first << ":" << p.second << endl;

	// 2.
	pair<string, int> p2 = make_pair("漳卅七年", 23);
	cout << p2.first << ":" << p2.second << endl;


}
class MyCompare {
public:
	// 第一个小括号代表需要重载的符号
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}

};
void test07() {
	set<int> s;
	s.insert(4);
	s.insert(41);
	s.insert(14);
	s.insert(61);
	s.insert(9);
	// 默认从小到大排序
	print(s);

	// 利用仿函数 指定排序规则
	set<int, MyCompare>s2;
	s2.insert(4);
	s2.insert(41);
	s2.insert(14);
	s2.insert(61);
	s2.insert(9);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
class P {
public:
	string Name;
	int Age;
	P(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
};
class Compare {
public:
	bool operator()(const P&p1,const P&p2) const{
		// 年龄降序
		return p1.Age > p2.Age;
	}
};
void test08() {
	// 仿函数规则类型添加
	set<P, Compare> s;
	P p1("张三", 21);
	P p2("李四", 23);
	P p3("王五", 22);
	P p4("陆六", 18);
	P p5("陈七", 99);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	// 自定义数据类型无法排序就无法遍历 会报错 因此需要指定规则
	for (set<P, Compare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "姓名: " << it->Name << "年龄: " << it->Age << endl;
	} 

}

int main() {
	// 构造
	//test01();

	// set大小与交换操作
	//test02();

	// 插入与删除
	//test03();
	
	// 查找与统计
	//test04();
	
	/*
		set和multiset区别：
		set不可以插入重复数据，而multiset可以
		set插入数据的同时会返回插入结果，表示插入是否成功。
		multiset不会检测数据，因此可以插入重复数据
	*/
	//test05();

	// pair对组的使用 在需要返回两个数据的时候使用
	//test06();

	// 内置指定规则排序
	//test07();

	// 自定义数据类型排序
	test08();


	system("pause");
	return 0;
}