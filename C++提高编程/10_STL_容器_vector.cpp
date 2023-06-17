#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


void print(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	// Ĭ�Ϲ���
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);

	// ���乹��
	vector<int>v2(v1.begin(), v1.end());
	print(v2);

	// n��elm����
	vector<int>v3(10, 100);
	print(v3);
}

void test02() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);

	vector<int> v2;
	v2 = v1;
	print(v2);

	// assign��ֵ
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	print(v3);

	// n��elm����
	vector<int> v4;
	v4.assign(10, 100);
	print(v4);

}

void test03() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);

	// �п�
	if (v1.empty()) {
		cout << "��" << endl;
	}
	else {
		// ����Ϊ13 ��sizeҪ�� ��̬��չ
		cout << "����Ϊ: " << v1.capacity() << endl;
		cout << "��СΪ: " << v1.size() << endl;
	}
	// �������Ĵ�С = �������Ĵ�С  + �������Ĵ�С /2
	// 13 + ��13/2�� = 13+6 = 19
	// �޸Ĵ�С ����Ĭ����0��� Ҳ����ָ�������
	// ���˾�ɾ�������
	//v1.resize(15);
	v1.resize(15,100);
	print(v1);
	cout << "�޸�����Ϊ: " << v1.capacity() << endl;

}

void test04() {
	vector<int>v1;
	for (int i = 0; i < 3; i++) {
		v1.push_back(i);
	}
	print(v1);

	// β��
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	print(v1);
	// βɾ
	v1.pop_back();
	print(v1);

	// ����
	// ��ͷ����һ���� ��һ�������ǵ����� 
	v1.insert(v1.begin(), 100);
	print(v1);

	// ����n��elm
	v1.insert(v1.begin(), 2, 666);
	print(v1);

	// ɾ��
	// ͷɾһ��
	v1.erase(v1.begin());
	print(v1);

	// ���
	v1.clear();
	print(v1);

}
void test05() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;
	
	// ��ȡ��һ��Ԫ��
	cout << v1.front() << endl;

	// ��ȡ���һ��Ԫ��
	cout << v1.back() << endl;

}

void test06() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	cout << "===����ǰ===" << endl;
	print(v1);
	print(v2);
	cout << "===������===" << endl;
	v1.swap(v2);
	print(v1);
	print(v2);
}
void test07() {
	// ʵ����; ���������ڴ�ռ�
	vector<int>v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "������" << v.capacity() << endl;
	cout << "��С��" << v.size() << endl;

	v.resize(3);
	cout << "resize������" << v.capacity() << endl;
	cout << "resize��С��" << v.size() << endl;

	// swap�����ڴ�
	// �������� ��v��ʼ�� Ȼ�󽻻��ڴ�
	vector<int>(v).swap(v);
	cout << "����������" << v.capacity() << endl;
	cout << "������С��" << v.size() << endl;

}

void test08() {
	// Ԥ��ָ����Ԫ�صĳ��� Ԥ��λ�ò���ʼ�� Ԫ�ز��ɷ���
	vector<int> v;
	v.reserve(100001);
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	
	cout << "������" << v.capacity() << endl;
	cout << "��С��" << v.size() << endl;
	
}
int main() {
	// ����
	//test01();

	// ��ֵ
	//test02();

	// �����ʹ�С
	//test03();

	// �����ɾ��
	//test04();

	// ���ݴ�ȡ
	//test05();
	
	// ��������
	//test06();

	// ʵ����; ���������ڴ�ռ�
	//test07();

	// Ԥ���ռ� ���ٶ�̬����ʱ����չ����
	test08();

	system("pause");
	return 0;
}