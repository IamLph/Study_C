#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void test01() {
	stack<int> s;
	// ѹջ
	s.push(1);
	s.push(2);
	s.push(3);

	// �鿴����
	while (!s.empty()) {
		cout << "ջ��Ԫ��:" << s.top() << endl;
		// ��ջ
		s.pop();
	}
	cout << "ջ�Ĵ�С:" << s.size() << endl;
}

int main() {
	/*
		stack:�Ƚ���������ݽṹ ֻ��һ������ ջ��
	*/
	test01();

	system("pause");
	return 0;
}