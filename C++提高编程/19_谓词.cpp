#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// 仿函数 返回类型是bool
class Five {
public:
	// 重载()
	bool operator()(int val){
		return val > 5;
	}
};

void test01() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i * 2);
	}
	// 查找大于5的数字 返回迭代器
	vector<int>::iterator it = find_if(v.begin(), v.end(), Five());
	if (it == v.end()) {
		cout << "未找到" << endl;
	}
	else {
		cout << *it << endl;
	}
}

class Compare {
public:
	bool operator()(int v1,int v2) {
		return v1 > v2;
	}
};
void test02() {
	vector<int> v;
	v.push_back(1);
	v.push_back(12);
	v.push_back(21);
	v.push_back(31);
	v.push_back(14);
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// 策略 从小到达排序
	sort(v.begin(), v.end(), Compare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	// 一元谓词 operator()接受一个参数
	test01();

	// 二元谓词
	test02();
	system("pause");
	return 0;
}