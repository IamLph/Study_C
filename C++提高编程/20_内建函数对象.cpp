#include<iostream>
#include<string>
// ʹ���ڽ�����������Ҫ����
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void test01() {
	negate<int>n;
	// ȡ������ ��ֵ
	cout << n(50) << endl;
	// �ӷ�����
	plus<int> p;
	cout << p(10,20)<< endl;
	// ����
	minus<int>mi;
	// �˷�
	multiplies<int>m;
	// ����
	divides<int>d;
	// ȡģ
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
	// ����
	//sort(v.begin(),v.end(),jiangxu());

	sort(v.begin(),v.end(),greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// ����
	bool equal_to();
	// ������
	bool not_equal();
	// ����
	bool greater();
	// ���ڵ���
	bool greater_equal();
	// С��
	bool less();
	// С�ڵ���
	bool less_equal();


}

void test03() {
	// ��
	//bool logical_and();
	// ��
	//bool logical_or();
	// ��
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

	// �����߼��� ȡ�� ���Ƶ�v2
	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main() {
	// �����º���
	//test01();

	// ��ϵ�º���
	test02();

	// �߼��º���
	test03();
	system("pause");
	return 0;
}