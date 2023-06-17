#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

// 普通函数
void print01(int val) {
	cout << val << " ";
}
class print02 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};
void test01() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	// 普通函数
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	// 仿函数
	for_each(v.begin(), v.end(), print02());
	cout << endl;

}

class trans {
public:
	int operator()(int v) {
		return v+1;
	}
};
class print03 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};
void test02() {
	/*
	transform 四个参数 （开始迭代器，
		结束迭代器，目标容器开始迭代器，
		func函数或者函数对象）
	*/
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << endl;
	// 创建目标容器
	vector<int>v2;
	// 需要开辟空间  否则会报错
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), trans());

	for_each(v2.begin(), v2.end(), print03());
	cout << endl;
}


void test03() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i+1);
	}
	// 查找是否有5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) {
		cout << "未找到" << endl;
	}
	else {
		cout << *it << endl;
	}
}
int main() {
	// for_each
	test01();

	// transform
	test02();

	// find
	test03();
	/*
		find:	查找元素
		find_if:	按条件查找元素
		adjacent_search: 查找相邻重复元素
		binary_search:	二分查找法
		count:	统计元素个数
		count_if:	按条件统计元素个数
	
	*/
	system("pause");
	return 0;
}