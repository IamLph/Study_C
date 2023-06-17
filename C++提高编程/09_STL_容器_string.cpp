#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// string��������һ����
void test01() {
	// Ĭ�Ϲ���
	string s1;

	const char* str = "Hello World";
	// �вι���
	string s2(str);
	// ��������
	string s3(s2);
	// ��ʼ��10��a
	string s4(10,'a');

	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
}

void test02() {
	string s1 = "HelloWolrd";
	cout << "s1 = " << s1 << endl;

	string s2 = s1;
	cout << "s2 = " << s2 << endl;

	string s3;
	s3 = 'a';
	cout << "s3 = " << s3 << endl;

	string s4;
	s4.assign("Hello Assign");
	cout << "s4 = " << s4 << endl;

	// �ַ�����ǰn���ַ���ֵ����ǰ���ַ���
	string s5;
	s5.assign("I Love my", 6);
	cout << "s5 = " << s5 << endl;

	// ��n���ַ�c��ֵ����ǰ�ַ���
	string s6;
	s6.assign(6, '6');
	cout << "s6 = " << s6 << endl;

	string s7;
	s7.assign(s6);
	cout << "s7 = " << s7 << endl;
}

// �ַ���ƴ��
void test03() {
	string s1 = "I";
	s1 += "Love";
	cout << "s1 = " << s1 << endl;
	// ׷���ַ�
	s1 += ":";
	cout << "s1 = " << s1 << endl;
	// ׷���ַ���
	string s2 = "Wmy";
	s1 += s2;
	cout << "s1 = " << s1 << endl;

	string s3 = "I";
	s3.append(" love ");
	cout << "s3 = " << s3 << endl;
	// ׷���ַ�����ǰn���ַ�
	s3.append("Wmy I Love", 3);
	cout << "s3 = " << s3 << endl;
	// ׷���ַ���
	s3.append(s1);
	cout << "s3 = " << s3 << endl;
	// ���ַ�����posλ�ÿ�ʼ��n���ַ���ĩβ
	s3.append("1234567", 1, 4);
	cout << "s3 = " << s3 << endl;

}

void test04() {
	string str1 = "abcdeafasde";
	// find ���ҵ�һ�γ��ֵ�λ�� û�оͷ���-1
	int pos = str1.find("de");
	cout << "findλ��: " << pos << endl;


	// rfind ���� find������ rfind��������
	int pos2 = str1.rfind("de");
	cout << "rfindλ��: " << pos2 << endl;

	// �滻
	string str2 = "abcdefghijklmn";
	// 1-3���ַ��滻 3���滻Ϊn��
	str2.replace(1, 3, "666777");
	cout << "�滻��:" <<  str2 << endl;

}

void test05() {
	string s1 = "zbc";
	string s2 = "abc";
	// �Ƚ�Ascll��
	char a = (s1.compare(s2) == 0) ? 'Y' : 'N';
	cout << a << endl;

	char b = (s1.compare(s2) > 0) ? 'Y' : 'N';
	cout << b << endl;

	char c = (s1.compare(s2) < 0) ? 'Y' : 'N';
	cout << c << endl;

}
void test06() {
	string s1 = "hello world!";
	cout << s1 << endl;

	// �����ַ� ��ʽ1
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";
	}
	cout << endl;
	// �����ַ� ��ʽ2
	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << " ";
	}
	cout << endl;
	// �޸ĵ����ַ�
	s1[0] = 'I';
	cout << s1 << endl;
	s1.at(1) = 'L';
	cout << s1 << endl;
}

void test07() {
	string s1 = "hello";
	// ����
	s1.insert(1, "666");
	cout << s1 << endl;
	// ɾ��
	s1.erase(1, 3);
	cout << s1 << endl;

}
void test08() {
	string s1 = "Hello Wolrd!";

	// ��һ��λ�ÿ�ʼ��ȡ����
	string sub = s1.substr(1, 3);
	cout << sub << endl;

	string s2 = "hello@163.com";
	// ��ȡ�û�����Ϣ
	int pos = s2.find("@");
	string name = s2.substr(0, pos);
	cout << name << endl;


}
int main() {
	// string��������һ���� ���췽��
	//test01();

	// ��ֵ����
	//test02();

	// �ַ���ƴ��
	//test03();

	// �ַ����滻�Ͳ���
	//test04();

	// �ַ����Ƚ�
	//test05();
	 
	// �ַ���ȡ
	// test06();

	// �ַ���������ɾ��
	//test07();

	// �ִ���ȡ
	test08();


	system("pause");
	return 0;
}