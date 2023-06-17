#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
		map������Ԫ�ض���pair
		pair�е�һ��Ԫ��Ϊkey (��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue (ʵֵ)��
		����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
		map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��
		�ŵ�: ���Ը���kevֵ�����ҵ�valueֵ

		map��multimap����:
			map���������������ظ�keyֵԪ��
			multimap�������������ظ�keyֵԪ��
*/
void print(map<int,int>&m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << "  value:" << it->second << endl;
	}
	cout << endl;
}
void test01() {
	// ��һ����keyֵ���� �ڶ�����value����
	map<int, int> m;
	// ʹ�ö��鷽ʽ���ֵ �������ݻᰴ��keyֵ��������
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));
	// �޷�������ͬ��key ��������Ϊ: pair<iterator, bool>
	m.insert(pair<int, int>(5, 60));
	print(m);

	// ��������
	map<int, int>m2(m);
	print(m2);

	// ��ֵ����
	map<int, int>m3;
	m3 = m2;
	print(m3);

}
void test02() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	if (m.empty()) {
		cout << "��" << endl;
	}
	else {
		cout << "��СΪ: " << m.size() << endl;
	}

	map<int, int> m2;
	m2.insert(pair<int, int>(1, 3));
	m2.insert(pair<int, int>(2, 4));
	m2.insert(pair<int, int>(3, 5));

	cout << "����ǰ:" << endl;
	print(m);
	print(m2);

	m2.swap(m);

	cout << "������:" << endl;
	print(m);
	print(m2);


}

void test03() {
	map<int, int> m;
	// ���� ���ַ�ʽ
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	// []��ʽ���������,���ǿ����������� 
	// ��Ϊ���ʹ�ò�����key�Ļ�,���Զ���������һ����
	print(m);

	// ɾ������
	m.erase(m.begin());
	print(m);

	// ���ݼ�ɾ��
	m.erase(3);
	print(m);

	// ����ɾ��
	m.erase(m.begin(), m.end());
	cout << "����ɾ��" << endl;
	print(m);

	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	// ��ղ���
	m.clear();
	cout << "��ղ���" << endl;
	print(m);
}

void test04() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	// ���Ҳ���
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end()) {
		cout << "�ҵ���-->" << (*pos).first << ":" << pos->second << endl;
	}
	else {
		cout << "û���ҵ�" << endl;
	}
	// ͳ�Ʋ��� �ҵ�key��ͬ������
	// map�������ظ�key,����multimap�����ظ�key
	int num = m.count(3);
	cout << "key��ͬ������:" << num << endl;

}
class MyCompare {
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};
void test05() {
	map<int, int, MyCompare> m;
	m.insert(pair<int, int>(2, 10));
	m.insert(make_pair(1, 20));
	m.insert(map<int, int>::value_type(4, 30));
	m[3] = 40;
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << ":" << it->second << endl;
	}
}

int main() {
	// �����븳ֵ map���е�Ԫ�ض��ǳɶԳ��ֵ� ����������Ҫʹ�ö���
	//test01();

	// map�����Ĵ�С�뽻������
	//test02(); 

	// ������ɾ��
	//test03();

	// ������ͳ��
	//test04();

	// �������
	// ���÷º�������ָ��map�������������
	// �����Զ�������,map����ָ��������� ͬset����
	test05();

	system("pause");
	return 0;
}