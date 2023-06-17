#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

// ��ͨ����
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
	// ��ͨ����
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	// �º���
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
	transform �ĸ����� ����ʼ��������
		������������Ŀ��������ʼ��������
		func�������ߺ�������
	*/
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << endl;
	// ����Ŀ������
	vector<int>v2;
	// ��Ҫ���ٿռ�  ����ᱨ��
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
	// �����Ƿ���5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) {
		cout << "δ�ҵ�" << endl;
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
		find:	����Ԫ��
		find_if:	����������Ԫ��
		adjacent_search: ���������ظ�Ԫ��
		binary_search:	���ֲ��ҷ�
		count:	ͳ��Ԫ�ظ���
		count_if:	������ͳ��Ԫ�ظ���
	
	*/
	system("pause");
	return 0;
}