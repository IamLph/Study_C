#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void myPrint(int val) {
	cout << val << endl;
}

void test01() {
	// 创建容器
	vector<int> v;
	// 添加数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	// 遍历
	// 起始迭代器 指向容器第一个元素
	vector<int>::iterator itBegin = v.begin();
	// 结束迭代器 指向容器中最后一个元素的下一个
	vector<int>::iterator itEnd = v.end();
	// 第一种遍历
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	// 第二种遍历
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	// 第三种遍 回调技术
	for_each(v.begin(), v.end(), myPrint);
}


// 容器存放自定义数据类型
class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
};
void test02() {
	vector<Person> v;
	Person p1("aaa",11);
	Person p2("bbb",12);
	Person p3("ccc",13);
	Person p4("ddd",14);
	Person p5("eee",15);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	// 遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		// *解开 it是一个指针 可以箭头访问属性
		//cout << "姓名:" << (*it).name << "年龄:" << (*it).age << endl;
		cout << "姓名:" << it->name << "年龄:" << it->age << endl;
	}
}
void test03() {
	vector<Person*> v;
	Person p1("aaa", 16);
	Person p2("bbb", 17);
	Person p3("ccc", 18);
	Person p4("ddd", 19);
	Person p5("eee", 20);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	// 遍历
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名:" << (*it)->name << "年龄:" << (*it)->age << endl;
	}
}

// 容器嵌套容器
void test04() {
	vector<vector<int>> v;
	// 创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	// 小容器添加数据
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	// 遍历
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		// 也可以使用 （*it）.begin()
		for (vector<int>::iterator i = it->begin(); i != it->end(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}

};

int main() {
	// 容器初始化
	//test01();
	
	// 容器存放自定义数据类型
	//test02();
	//test03();

	// 容器嵌套容器
	test04();
	system("pause");
	return 0;
}