#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<string>
using namespace std;

// const限定只读 不可以修改
void print(const deque<int> &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << ":";
	}
	cout << endl;
	/*for (int i = 0; i < d.size(); i++) {
		cout << d[i] << ":";
	}
	cout << endl;*/
}
/*
	deque
	双端数组，可以头部插入与删除
*/

void test01() {
	// 初始化
	deque<int>d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	print(d);

	// 赋值
	deque<int>d2(d.begin(), d.end());
	print(d2);
	
	// n个elm
	deque<int> d3(6, 666);
	print(d3);

	// copy
	deque<int>d4(d3);
	print(d4);

}
void test02() {
	deque<int>d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	print(d);
	// 赋值操作 =
	deque<int> d2;
	d2 = d;
	print(d2);

	// assign
	deque<int>d3;
	d3.assign(d.begin(), d.end());
	print(d3);
	
	deque<int>d4;
	d4.assign(3, 55);
	print(d4);
	 
}

void test03() {
	deque<int>d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	// 判断是否为空
	if (d.empty()) {
		cout << "空" << endl;
	}
	else {
		cout << "不空" << endl;
		cout << "大小:" << d.size() << endl;

		// 修改大小 -1填充
		d.resize(20,-1);
		print(d);
		// 裁剪
		d.resize(6);
		print(d);
	}
	
}
void test04() {
	deque<int>d;
	// 尾插
	d.push_back(1);
	d.push_back(2);
	// 头插
	d.push_front(-1);
	print(d);
	// 尾删
	d.pop_back();
	print(d);
	// 头删
	d.pop_front();
	print(d);

	d.push_back(10);
	d.push_back(11);
	d.push_back(12);
	d.push_back(13);
	d.push_back(14);
	cout << "============新的开始============" << endl;
	print(d);

	// insert插入
	d.insert(d.begin(), 1000);
	print(d);

	// 区间插入
	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	// 从头开始插入一个区间
	d.insert(d.begin(), d2.begin(), d2.end());
	print(d);


	cout << "===删除操作===" << endl;
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d3.push_back(5);
	print(d3);

	// 删除
	// 使用迭代器获取头位置
	deque<int>::iterator it = d3.begin();
	// 删除第二个数据了
	it++;
	d3.erase(it);
	print(d3);
	// 区间方式删除
	d3.erase(d3.begin(), d3.end());
	print(d3);
}
void test05() {
	deque<int>d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;

	// at访问
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "最后一个元素：" << d.front() << endl;
	cout << "第一个元素:" << d.back() << endl;

}
// 排序
void test06() {
	deque<int>d;
	d.push_back(10);
	d.push_back(14);
	d.push_back(12);
	d.push_back(11);
	d.push_back(200);
	print(d);

	// 排序默认升序 
	sort(d.begin(),d.end());
	cout << "排序后 " << endl;
	print(d);
}

class Person {
public:
	string Name;
	int Score;
	Person(string name,int score) {
		this->Name = name;
		this->Score = score;
	}
};
void createPerson(vector<Person>&v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}
void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			// 随机数赋分
			// 60~100分
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		// 去除最高与最低
		d.pop_back();
		d.pop_front();
		// 平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		int avg = sum / d.size();
		// 设置平均分
		it->Score = avg;
	}
}
// 案例
void run() {
	/*
		ABCDE五个选手 10个评委进行打分 去除最高分 去除最低分 取平均分
	*/
	// 创建选手
	vector<Person> v;
	createPerson(v);
	
	// 设置分数
	setScore(v);

	// 查看得分
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->Name << ":" << it->Score << endl;
	}
}

int main() {
	// 构建
	//test01();
	
	// 赋值操作
	//test02();

	// 大小操作
	//test03();

	// 插入和删除
	//test04();

	// 数据存取
	//test05();

	// 排序
	//test06();


	// 案例 评委打分
	/*
		ABCDE五个选手 10个评委进行打分 去除最高分 去除最低分 取平均分
	*/
	run();

	system("pause");
	return 0;
}