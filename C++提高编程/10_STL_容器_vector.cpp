#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


void print(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	// 默认构造
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);

	// 区间构造
	vector<int>v2(v1.begin(), v1.end());
	print(v2);

	// n个elm构造
	vector<int>v3(10, 100);
	print(v3);
}

void test02() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);

	vector<int> v2;
	v2 = v1;
	print(v2);

	// assign赋值
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	print(v3);

	// n个elm方法
	vector<int> v4;
	v4.assign(10, 100);
	print(v4);

}

void test03() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);

	// 判空
	if (v1.empty()) {
		cout << "空" << endl;
	}
	else {
		// 容量为13 比size要大 动态扩展
		cout << "容量为: " << v1.capacity() << endl;
		cout << "大小为: " << v1.size() << endl;
	}
	// 新容量的大小 = 旧容量的大小  + 旧容量的大小 /2
	// 13 + （13/2） = 13+6 = 19
	// 修改大小 长了默认用0填充 也可以指定数填充
	// 短了就删除后面的
	//v1.resize(15);
	v1.resize(15,100);
	print(v1);
	cout << "修改容量为: " << v1.capacity() << endl;

}

void test04() {
	vector<int>v1;
	for (int i = 0; i < 3; i++) {
		v1.push_back(i);
	}
	print(v1);

	// 尾插
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	print(v1);
	// 尾删
	v1.pop_back();
	print(v1);

	// 插入
	// 在头插入一个数 第一个参数是迭代器 
	v1.insert(v1.begin(), 100);
	print(v1);

	// 插入n个elm
	v1.insert(v1.begin(), 2, 666);
	print(v1);

	// 删除
	// 头删一个
	v1.erase(v1.begin());
	print(v1);

	// 清空
	v1.clear();
	print(v1);

}
void test05() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;
	
	// 获取第一个元素
	cout << v1.front() << endl;

	// 获取最后一个元素
	cout << v1.back() << endl;

}

void test06() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	cout << "===交换前===" << endl;
	print(v1);
	print(v2);
	cout << "===交换后===" << endl;
	v1.swap(v2);
	print(v1);
	print(v2);
}
void test07() {
	// 实际用途 可以收缩内存空间
	vector<int>v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "容量：" << v.capacity() << endl;
	cout << "大小：" << v.size() << endl;

	v.resize(3);
	cout << "resize容量：" << v.capacity() << endl;
	cout << "resize大小：" << v.size() << endl;

	// swap收缩内存
	// 匿名对象 用v初始化 然后交换内存
	vector<int>(v).swap(v);
	cout << "收缩容量：" << v.capacity() << endl;
	cout << "收缩大小：" << v.size() << endl;

}

void test08() {
	// 预留指定个元素的长度 预留位置不初始化 元素不可访问
	vector<int> v;
	v.reserve(100001);
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	
	cout << "容量：" << v.capacity() << endl;
	cout << "大小：" << v.size() << endl;
	
}
int main() {
	// 构造
	//test01();

	// 赋值
	//test02();

	// 容量和大小
	//test03();

	// 插入和删除
	//test04();

	// 数据存取
	//test05();
	
	// 互换容器
	//test06();

	// 实际用途 可以收缩内存空间
	//test07();

	// 预留空间 减少动态扩容时的扩展次数
	test08();

	system("pause");
	return 0;
}