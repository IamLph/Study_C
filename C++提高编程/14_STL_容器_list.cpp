#include<iostream>
#include<string>
#include<list>
using namespace std;
void print(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	// 默认构造
	list<int> L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	print(L1);
	
	// 区间构造
	list<int> L2(L1.begin(),L1.end());
	print(L2);

	// 拷贝构造
	list<int> L3(L2);
	print(L3);

	// n 个 elem
	list<int> L4(10, 666);
	print(L4);
	

}
void test02() {
	list<int>L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	print(L1);
	list<int> L2;
	// operator= 赋值操作
	L2 = L1;
	print(L2);

	// assign赋值
	list<int> L3;
	// assign区间赋值
	L3.assign(L2.begin(), L2.end());
	print(L3);

	// assign n个elem
	list<int>L4;
	L4.assign(10, 555);
	print(L4);
}

void test03() {
	list<int>L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);

	list<int> L2;
	L2.assign(10, 100);
	cout << "互换前:" << endl;
	print(L1);
	print(L2);
	L1.swap(L2);
	cout << "互换后前:" << endl;
	print(L1);
	print(L2);

}

void test04() {
	list<int>L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
    
	// 判空
	if (L1.empty()) {
		cout << "空" << endl;
	}
	else {
		cout << "不空" << endl;
		// 查看大小
		cout << L1.size() << endl;
	}

	// 重新指定大小 大于原本 0填充 小于原本 取消后面
	L1.resize(10);
	print(L1);

	
}

void test05() {
	list<int>L1;

	// 尾插
	L1.push_back(10);
	L1.push_back(8);
	L1.push_back(6);
	print(L1);

	// 头插
	L1.push_front(0);
	print(L1);

	// 尾删
	L1.pop_back();
	print(L1);

	// 头删
	L1.pop_front();
	print(L1);

	// insert插入
	L1.insert(L1.begin(), 1000);
	print(L1);

	// insert迭代器偏移插入
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 66);
	print(L1);

	// 删除
	it = L1.begin();
	L1.erase(it);
	print(L1);

	// 移除所有相同值的数据
	L1.push_back(1);
	L1.push_back(1);
	print(L1);
	L1.remove(1);
	print(L1);

	// 清空
	L1.clear();
	print(L1);

}
void test06() {
	list<int>L1;

	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	cout << "访问第一个:" << L1.front() << endl;
	cout << "访问最后一个:" << L1.back() << endl;
	// 不支持随机访问 只能使用迭代器的 ++ -- 操作
	list<int>::iterator it = L1.begin();
	it++;
	cout << *it << endl;
	++it;
	cout << *it << endl;
	it--;
	cout << *it << endl;
	--it;
	cout << *it << endl;
	//print(L1);
}
bool myCompare(int v1, int v2) {
	// 降序 让第一个数大于第二个数
	return v1 > v2;
}
void test07() {
	list<int> l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(1);
	l.push_back(4);

	print(l);
	// 反转操作
	l.reverse();
	print(l);

	// 排序操作 默认升序
	l.sort();
	print(l);
	// 降序
	l.sort(myCompare);
	print(l);

}

class Ps {
public:
	string Name;
	int Age;
	int Height;
	Ps(string name, int age,int height) {
		this->Name = name;
		this->Age = age;
		this->Height = height;
	}
};

// 制定排序规则
bool comparePerson(Ps &p1,Ps &p2) {
	// 年龄升序
	if (p1.Age == p2.Age) {
		return p1.Height > p2.Height;
	}
	else {
		return p1.Age < p2.Age;
	}
	
}

void run() {
	/*
		person按照年龄升序 按照身高降序
	*/
	list<Ps> l;
	Ps p1("张三", 23, 171);
	Ps p2("李四", 18, 172);
	Ps p3("王五", 22, 176);
	Ps p4("陈六", 22, 173);
	Ps p5("老七", 22, 175);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);

	for (list<Ps>::iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名: " << (*it).Name << 
				"年龄: " << it->Age << 
				"身高: " << it->Height << endl;
	}
	// 排序
	cout << "----------排序----------" << endl;
	// 操作自定义数据类型 需要指定排序规则
	l.sort(comparePerson);
	for (list<Ps>::iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名: " << (*it).Name <<
			"年龄: " << it->Age <<
			"身高: " << it->Height << endl;
	}


}
int main() {
	/*
		list链式存储 由结点构成 结点由数据域与指针域构成
		优点：可以在任意位置快速插入或删除
		缺点：遍历速度慢、占用空间大
	*/
	// 构造
	//test01();

	// 赋值
	//test02();
	
	// 交换
	//test03();

	// 大小操作
	//test04();

	// 插入与删除
	//test05();

	// 数据存取
	//test06();

	// 反转与排序
	//test07();

	// 排序案例
	run();


	system("pause");
	return 0;
}