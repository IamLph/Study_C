#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void test01() {
	stack<int> s;
	// 压栈
	s.push(1);
	s.push(2);
	s.push(3);

	// 查看数据
	while (!s.empty()) {
		cout << "栈顶元素:" << s.top() << endl;
		// 出栈
		s.pop();
	}
	cout << "栈的大小:" << s.size() << endl;
}

int main() {
	/*
		stack:先进后出的数据结构 只有一个出口 栈！
	*/
	test01();

	system("pause");
	return 0;
}