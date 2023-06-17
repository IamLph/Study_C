#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
	queue���� �Ƚ��ȳ������ݽṹ����������
	��������� ǰ�������
*/
class Person {
public:
	string Name;
	int Age;
	Person(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
};

void test01() {
	// ��������
	queue<Person> q;

	Person p1("����", 1);
	Person p2("��4", 12);
	Person p3("��5", 13);
	Person p4("��6", 123);
	// ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty()) {
		cout << "ͷ--" << q.front().Name << endl;
		cout << "β--" << q.back().Name << endl;
		// ����
		q.pop();
	}
	cout << "����С:" << q.size() << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}