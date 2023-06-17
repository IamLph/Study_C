#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<string>
using namespace std;

// const�޶�ֻ�� �������޸�
void print(const deque<int> &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << ":";
	}
	cout << endl;
	/*for (int i = 0; i < d.size(); i++) {
		cout << d[i] << ":";
	}
	cout << endl;*/
}
/*
	deque
	˫�����飬����ͷ��������ɾ��
*/

void test01() {
	// ��ʼ��
	deque<int>d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	print(d);

	// ��ֵ
	deque<int>d2(d.begin(), d.end());
	print(d2);
	
	// n��elm
	deque<int> d3(6, 666);
	print(d3);

	// copy
	deque<int>d4(d3);
	print(d4);

}
void test02() {
	deque<int>d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	print(d);
	// ��ֵ���� =
	deque<int> d2;
	d2 = d;
	print(d2);

	// assign
	deque<int>d3;
	d3.assign(d.begin(), d.end());
	print(d3);
	
	deque<int>d4;
	d4.assign(3, 55);
	print(d4);
	 
}

void test03() {
	deque<int>d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	// �ж��Ƿ�Ϊ��
	if (d.empty()) {
		cout << "��" << endl;
	}
	else {
		cout << "����" << endl;
		cout << "��С:" << d.size() << endl;

		// �޸Ĵ�С -1���
		d.resize(20,-1);
		print(d);
		// �ü�
		d.resize(6);
		print(d);
	}
	
}
void test04() {
	deque<int>d;
	// β��
	d.push_back(1);
	d.push_back(2);
	// ͷ��
	d.push_front(-1);
	print(d);
	// βɾ
	d.pop_back();
	print(d);
	// ͷɾ
	d.pop_front();
	print(d);

	d.push_back(10);
	d.push_back(11);
	d.push_back(12);
	d.push_back(13);
	d.push_back(14);
	cout << "============�µĿ�ʼ============" << endl;
	print(d);

	// insert����
	d.insert(d.begin(), 1000);
	print(d);

	// �������
	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	// ��ͷ��ʼ����һ������
	d.insert(d.begin(), d2.begin(), d2.end());
	print(d);


	cout << "===ɾ������===" << endl;
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d3.push_back(5);
	print(d3);

	// ɾ��
	// ʹ�õ�������ȡͷλ��
	deque<int>::iterator it = d3.begin();
	// ɾ���ڶ���������
	it++;
	d3.erase(it);
	print(d3);
	// ���䷽ʽɾ��
	d3.erase(d3.begin(), d3.end());
	print(d3);
}
void test05() {
	deque<int>d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;

	// at����
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "���һ��Ԫ�أ�" << d.front() << endl;
	cout << "��һ��Ԫ��:" << d.back() << endl;

}
// ����
void test06() {
	deque<int>d;
	d.push_back(10);
	d.push_back(14);
	d.push_back(12);
	d.push_back(11);
	d.push_back(200);
	print(d);

	// ����Ĭ������ 
	sort(d.begin(),d.end());
	cout << "����� " << endl;
	print(d);
}

class Person {
public:
	string Name;
	int Score;
	Person(string name,int score) {
		this->Name = name;
		this->Score = score;
	}
};
void createPerson(vector<Person>&v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}
void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			// ���������
			// 60~100��
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		// ȥ����������
		d.pop_back();
		d.pop_front();
		// ƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		int avg = sum / d.size();
		// ����ƽ����
		it->Score = avg;
	}
}
// ����
void run() {
	/*
		ABCDE���ѡ�� 10����ί���д�� ȥ����߷� ȥ����ͷ� ȡƽ����
	*/
	// ����ѡ��
	vector<Person> v;
	createPerson(v);
	
	// ���÷���
	setScore(v);

	// �鿴�÷�
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->Name << ":" << it->Score << endl;
	}
}

int main() {
	// ����
	//test01();
	
	// ��ֵ����
	//test02();

	// ��С����
	//test03();

	// �����ɾ��
	//test04();

	// ���ݴ�ȡ
	//test05();

	// ����
	//test06();


	// ���� ��ί���
	/*
		ABCDE���ѡ�� 10����ί���д�� ȥ����߷� ȥ����ͷ� ȡƽ����
	*/
	run();

	system("pause");
	return 0;
}