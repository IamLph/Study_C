#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
		map中所有元素都是pair
		pair中第一个元素为key (键值)，起到索引作用，第二个元素为value (实值)。
		所有元素都会根据元素的键值自动排序
		map/multimap属于关联式容器，底层结构是用二叉树实现
		优点: 可以根据kev值快速找到value值

		map和multimap区别:
			map不允许容器中有重复key值元素
			multimap允许容器中有重复key值元素
*/
void print(map<int,int>&m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << "  value:" << it->second << endl;
	}
	cout << endl;
}
void test01() {
	// 第一个是key值类型 第二个是value类型
	map<int, int> m;
	// 使用对组方式添加值 插入数据会按照key值进行排序
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));
	// 无法插入相同的key 返回类型为: pair<iterator, bool>
	m.insert(pair<int, int>(5, 60));
	print(m);

	// 拷贝构造
	map<int, int>m2(m);
	print(m2);

	// 赋值操作
	map<int, int>m3;
	m3 = m2;
	print(m3);

}
void test02() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	if (m.empty()) {
		cout << "空" << endl;
	}
	else {
		cout << "大小为: " << m.size() << endl;
	}

	map<int, int> m2;
	m2.insert(pair<int, int>(1, 3));
	m2.insert(pair<int, int>(2, 4));
	m2.insert(pair<int, int>(3, 5));

	cout << "交换前:" << endl;
	print(m);
	print(m2);

	m2.swap(m);

	cout << "交换后:" << endl;
	print(m);
	print(m2);


}

void test03() {
	map<int, int> m;
	// 插入 四种方式
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	// []方式不建议插入,但是可以用来访问 
	// 因为如果使用不存在key的话,会自动创建出来一个数
	print(m);

	// 删除操作
	m.erase(m.begin());
	print(m);

	// 根据键删除
	m.erase(3);
	print(m);

	// 区间删除
	m.erase(m.begin(), m.end());
	cout << "区间删除" << endl;
	print(m);

	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	// 清空操作
	m.clear();
	cout << "清空操作" << endl;
	print(m);
}

void test04() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	// 查找操作
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end()) {
		cout << "找到了-->" << (*pos).first << ":" << pos->second << endl;
	}
	else {
		cout << "没有找到" << endl;
	}
	// 统计操作 找到key相同的数量
	// map不允许重复key,但是multimap可以重复key
	int num = m.count(3);
	cout << "key相同的数量:" << num << endl;

}
class MyCompare {
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};
void test05() {
	map<int, int, MyCompare> m;
	m.insert(pair<int, int>(2, 10));
	m.insert(make_pair(1, 20));
	m.insert(map<int, int>::value_type(4, 30));
	m[3] = 40;
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << ":" << it->second << endl;
	}
}

int main() {
	// 构造与赋值 map所有的元素都是成对出现的 插入数据需要使用对组
	//test01();

	// map容器的大小与交换操作
	//test02(); 

	// 插入与删除
	//test03();

	// 查找与统计
	//test04();

	// 排序操作
	// 利用仿函数可以指定map容器的排序规则
	// 对于自定义类型,map必须指定排序规则 同set容器
	test05();

	system("pause");
	return 0;
}