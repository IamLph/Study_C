#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void myPrint(int val) {
	cout << val << endl;
}

void test01() {
	// ��������
	vector<int> v;
	// �������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	// ����
	// ��ʼ������ ָ��������һ��Ԫ��
	vector<int>::iterator itBegin = v.begin();
	// ���������� ָ�����������һ��Ԫ�ص���һ��
	vector<int>::iterator itEnd = v.end();
	// ��һ�ֱ���
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	// �ڶ��ֱ���
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	// �����ֱ� �ص�����
	for_each(v.begin(), v.end(), myPrint);
}


// ��������Զ�����������
class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
};
void test02() {
	vector<Person> v;
	Person p1("aaa",11);
	Person p2("bbb",12);
	Person p3("ccc",13);
	Person p4("ddd",14);
	Person p5("eee",15);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	// ����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		// *�⿪ it��һ��ָ�� ���Լ�ͷ��������
		//cout << "����:" << (*it).name << "����:" << (*it).age << endl;
		cout << "����:" << it->name << "����:" << it->age << endl;
	}
}
void test03() {
	vector<Person*> v;
	Person p1("aaa", 16);
	Person p2("bbb", 17);
	Person p3("ccc", 18);
	Person p4("ddd", 19);
	Person p5("eee", 20);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	// ����
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "����:" << (*it)->name << "����:" << (*it)->age << endl;
	}
}

// ����Ƕ������
void test04() {
	vector<vector<int>> v;
	// ����С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	// С�����������
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	// ����
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		// Ҳ����ʹ�� ��*it��.begin()
		for (vector<int>::iterator i = it->begin(); i != it->end(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}

};

int main() {
	// ������ʼ��
	//test01();
	
	// ��������Զ�����������
	//test02();
	//test03();

	// ����Ƕ������
	test04();
	system("pause");
	return 0;
}