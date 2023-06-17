#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
	queue容器 先进先出的数据结构，两个出口
	后面进数据 前面出数据
*/
class Person {
public:
	string Name;
	int Age;
	Person(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
};

void test01() {
	// 创建队列
	queue<Person> q;

	Person p1("张三", 1);
	Person p2("张4", 12);
	Person p3("张5", 13);
	Person p4("张6", 123);
	// 入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty()) {
		cout << "头--" << q.front().Name << endl;
		cout << "尾--" << q.back().Name << endl;
		// 出队
		q.pop();
	}
	cout << "最后大小:" << q.size() << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}