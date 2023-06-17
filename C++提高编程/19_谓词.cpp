#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// �º��� ����������bool
class Five {
public:
	// ����()
	bool operator()(int val){
		return val > 5;
	}
};

void test01() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i * 2);
	}
	// ���Ҵ���5������ ���ص�����
	vector<int>::iterator it = find_if(v.begin(), v.end(), Five());
	if (it == v.end()) {
		cout << "δ�ҵ�" << endl;
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
	// ���� ��С��������
	sort(v.begin(), v.end(), Compare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	// һԪν�� operator()����һ������
	test01();

	// ��Ԫν��
	test02();
	system("pause");
	return 0;
}