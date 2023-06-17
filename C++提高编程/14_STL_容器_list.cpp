#include<iostream>
#include<string>
#include<list>
using namespace std;
void print(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	// Ĭ�Ϲ���
	list<int> L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	print(L1);
	
	// ���乹��
	list<int> L2(L1.begin(),L1.end());
	print(L2);

	// ��������
	list<int> L3(L2);
	print(L3);

	// n �� elem
	list<int> L4(10, 666);
	print(L4);
	

}
void test02() {
	list<int>L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	print(L1);
	list<int> L2;
	// operator= ��ֵ����
	L2 = L1;
	print(L2);

	// assign��ֵ
	list<int> L3;
	// assign���丳ֵ
	L3.assign(L2.begin(), L2.end());
	print(L3);

	// assign n��elem
	list<int>L4;
	L4.assign(10, 555);
	print(L4);
}

void test03() {
	list<int>L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);

	list<int> L2;
	L2.assign(10, 100);
	cout << "����ǰ:" << endl;
	print(L1);
	print(L2);
	L1.swap(L2);
	cout << "������ǰ:" << endl;
	print(L1);
	print(L2);

}

void test04() {
	list<int>L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
    
	// �п�
	if (L1.empty()) {
		cout << "��" << endl;
	}
	else {
		cout << "����" << endl;
		// �鿴��С
		cout << L1.size() << endl;
	}

	// ����ָ����С ����ԭ�� 0��� С��ԭ�� ȡ������
	L1.resize(10);
	print(L1);

	
}

void test05() {
	list<int>L1;

	// β��
	L1.push_back(10);
	L1.push_back(8);
	L1.push_back(6);
	print(L1);

	// ͷ��
	L1.push_front(0);
	print(L1);

	// βɾ
	L1.pop_back();
	print(L1);

	// ͷɾ
	L1.pop_front();
	print(L1);

	// insert����
	L1.insert(L1.begin(), 1000);
	print(L1);

	// insert������ƫ�Ʋ���
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 66);
	print(L1);

	// ɾ��
	it = L1.begin();
	L1.erase(it);
	print(L1);

	// �Ƴ�������ֵͬ������
	L1.push_back(1);
	L1.push_back(1);
	print(L1);
	L1.remove(1);
	print(L1);

	// ���
	L1.clear();
	print(L1);

}
void test06() {
	list<int>L1;

	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	cout << "���ʵ�һ��:" << L1.front() << endl;
	cout << "�������һ��:" << L1.back() << endl;
	// ��֧��������� ֻ��ʹ�õ������� ++ -- ����
	list<int>::iterator it = L1.begin();
	it++;
	cout << *it << endl;
	++it;
	cout << *it << endl;
	it--;
	cout << *it << endl;
	--it;
	cout << *it << endl;
	//print(L1);
}
bool myCompare(int v1, int v2) {
	// ���� �õ�һ�������ڵڶ�����
	return v1 > v2;
}
void test07() {
	list<int> l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(1);
	l.push_back(4);

	print(l);
	// ��ת����
	l.reverse();
	print(l);

	// ������� Ĭ������
	l.sort();
	print(l);
	// ����
	l.sort(myCompare);
	print(l);

}

class Ps {
public:
	string Name;
	int Age;
	int Height;
	Ps(string name, int age,int height) {
		this->Name = name;
		this->Age = age;
		this->Height = height;
	}
};

// �ƶ��������
bool comparePerson(Ps &p1,Ps &p2) {
	// ��������
	if (p1.Age == p2.Age) {
		return p1.Height > p2.Height;
	}
	else {
		return p1.Age < p2.Age;
	}
	
}

void run() {
	/*
		person������������ ������߽���
	*/
	list<Ps> l;
	Ps p1("����", 23, 171);
	Ps p2("����", 18, 172);
	Ps p3("����", 22, 176);
	Ps p4("����", 22, 173);
	Ps p5("����", 22, 175);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);

	for (list<Ps>::iterator it = l.begin(); it != l.end(); it++) {
		cout << "����: " << (*it).Name << 
				"����: " << it->Age << 
				"���: " << it->Height << endl;
	}
	// ����
	cout << "----------����----------" << endl;
	// �����Զ����������� ��Ҫָ���������
	l.sort(comparePerson);
	for (list<Ps>::iterator it = l.begin(); it != l.end(); it++) {
		cout << "����: " << (*it).Name <<
			"����: " << it->Age <<
			"���: " << it->Height << endl;
	}


}
int main() {
	/*
		list��ʽ�洢 �ɽ�㹹�� �������������ָ���򹹳�
		�ŵ㣺����������λ�ÿ��ٲ����ɾ��
		ȱ�㣺�����ٶ�����ռ�ÿռ��
	*/
	// ����
	//test01();

	// ��ֵ
	//test02();
	
	// ����
	//test03();

	// ��С����
	//test04();

	// ������ɾ��
	//test05();

	// ���ݴ�ȡ
	//test06();

	// ��ת������
	//test07();

	// ������
	run();


	system("pause");
	return 0;
}