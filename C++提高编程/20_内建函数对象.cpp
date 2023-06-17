#include<iostream>
#include<string>
// 使用内建函数对象需要引入
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test01() {
	negate<int>n;
	// 取反操作 负值
	cout << n(50) << endl;
	// 加法操作
	plus<int> p;
	cout << p(10,20)<< endl;
	// 减法
	minus<int>mi;
	// 乘法
	multiplies<int>m;
	// 除法
	divides<int>d;
	// 取模
	modulus<int>md;
	cout << md(20, 3) << endl;

	
}
class jiangxu {
public:
	bool operator()(int a,int b) {
		return a > b;
	}
};
void test02() {
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// 降序
	//sort(v.begin(),v.end(),jiangxu());

	sort(v.begin(),v.end(),greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// 等于
	bool equal_to();
	// 不等于
	bool not_equal();
	// 大于
	bool greater();
	// 大于等于
	bool greater_equal();
	// 小于
	bool less();
	// 小于等于
	bool less_equal();


}

void test03() {
	// 与
	//bool logical_and();
	// 或
	//bool logical_or();
	// 非
	//bool logical_not();


	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// 利用逻辑非 取反 复制到v2
	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main() {
	// 算数仿函数
	//test01();

	// 关系仿函数
	test02();

	// 逻辑仿函数
	test03();
	system("pause");
	return 0;
}