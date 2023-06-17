#include<iostream>
#include<set>
#include<string>
using namespace std;
/*
	set�����ڲ�������ʱ���Զ�����
	set/multiset���ڹ���ʽ���� �ײ�Ϊ�������ṹ
	set ���������ظ�������
	multiset �����ظ�������
*/
void print(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test01() {
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(54);
	s.insert(34);
	s.insert(31);
	// �Ὣ�ظ�������ȥ��
	s.insert(31);
	print(s);
	// �Զ�����---> 2 3 31 34 54 
	
	// ��������
	set<int> s2(s);
	print(s2);

	// ��ֵ����
	set<int>s3;
	s3 = s2;
	print(s3);
}

void test02() {
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(54);
	s.insert(34);
	s.insert(31);

	if (s.empty()) {
		cout << "��" << endl;
	}
	else {
		cout << "��ĿΪ:" << s.size() << endl;
	}
	set<int> s2;
	s2.insert(6);
	s2.insert(7);
	s2.insert(8);
	s2.insert(9);
	cout << "����ǰ:" << endl;
	print(s);
	print(s2);
	s2.swap(s);
	cout << "������:" << endl;
	print(s);
	print(s2);
}

void test03() {
	set<int>s;
	
	// ����
	s.insert(11);
	s.insert(23);
	s.insert(3);
	s.insert(67);
	print(s);

	// ɾ�� ��ɾ����С���ĸ� ��Ϊ�Զ�����������
	s.erase(s.begin());
	print(s);

	// ɾ��ָ������
	s.erase(11);
	print(s);

	// ���1
	s.erase(s.begin(), s.end());
	print(s);

	s.insert(11);
	s.insert(23);
	s.insert(3);
	s.insert(67);
	print(s);
	// ���2
	s.clear();
	print(s);
}

void test04() {
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	s.insert(7);

	// ����Ԫ���Ƿ���� ���ص�����
	set<int>::iterator pos = s.find(2);
	if (pos != s.end()) {
		cout << "�ҵ�: " << *pos << endl;
	}
	else {
		cout << "δ�ҵ���" << endl;
	}
	// ͳ��ָ��Ԫ�ظ��� ���������ж�Ԫ���Ƿ����
	int num = s.count(7);
	cout << "ָ��Ԫ�ظ���: " << num << endl;
}

void test05() {
	set<int> s;
	/*
	*	insert ��������Ϊ _Pairib pair<iterator,bool>
	*	���ص��Ƕ��� �����ʱ��ͻ᷵�ز����� �Ƿ�ɹ�
	*/
	pair<set<int>::iterator,bool> ret = s.insert(10);
	if (ret.second) {
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	/*
	*	insert ��������Ϊ iterator ������ �����ж��Ƿ����ɹ�
	*	ֻҪ���Բ���Ͳ�
	*	Ҳ���Զ�����
	*/
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(9);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}

void test06() {
	// 1.Ĭ�Ϲ���
	pair<string, int>p("Tom", 13);
	cout << p.first << ":" << p.second << endl;

	// 2.
	pair<string, int> p2 = make_pair("��ئ����", 23);
	cout << p2.first << ":" << p2.second << endl;


}
class MyCompare {
public:
	// ��һ��С���Ŵ�����Ҫ���صķ���
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}

};
void test07() {
	set<int> s;
	s.insert(4);
	s.insert(41);
	s.insert(14);
	s.insert(61);
	s.insert(9);
	// Ĭ�ϴ�С��������
	print(s);

	// ���÷º��� ָ���������
	set<int, MyCompare>s2;
	s2.insert(4);
	s2.insert(41);
	s2.insert(14);
	s2.insert(61);
	s2.insert(9);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
class P {
public:
	string Name;
	int Age;
	P(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
};
class Compare {
public:
	bool operator()(const P&p1,const P&p2) const{
		// ���併��
		return p1.Age > p2.Age;
	}
};
void test08() {
	// �º��������������
	set<P, Compare> s;
	P p1("����", 21);
	P p2("����", 23);
	P p3("����", 22);
	P p4("½��", 18);
	P p5("����", 99);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	// �Զ������������޷�������޷����� �ᱨ�� �����Ҫָ������
	for (set<P, Compare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "����: " << it->Name << "����: " << it->Age << endl;
	} 

}

int main() {
	// ����
	//test01();

	// set��С�뽻������
	//test02();

	// ������ɾ��
	//test03();
	
	// ������ͳ��
	//test04();
	
	/*
		set��multiset����
		set�����Բ����ظ����ݣ���multiset����
		set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ���
		multiset���������ݣ���˿��Բ����ظ�����
	*/
	//test05();

	// pair�����ʹ�� ����Ҫ�����������ݵ�ʱ��ʹ��
	//test06();

	// ����ָ����������
	//test07();

	// �Զ���������������
	test08();


	system("pause");
	return 0;
}