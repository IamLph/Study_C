#include<iostream>
using namespace std;
#include<string>
// �ṹ��
/*
	struct �������� { ��Ա�б� }
*/
struct Student {
	string name;
	int age;
	int score;
}s3;

// �ṹ��Ƕ��
struct Teacher {
	string name;
	int age;
	struct Student stu;
};

void print(Student stu) {
	cout << stu.name << "-" << stu.age << "-" << stu.score << endl;
}
void print2(Student * stu) {
	cout << stu->name << "-" << stu->age << "-" << stu->score << endl;
}

int main() {

	// �ṹ�崴��ѧ������ֵ
	// ��ʽһ
	struct Student s1;
	s1.name = "����";
	s1.age = 18;
	s1.score = 66;

	cout << "������" << s1.name << endl;
	cout << "���䣺" << s1.age << endl;
	cout << "������" << s1.score << endl;

	// ��ʽ��
	struct Student s2 = {"����",23,13};
	cout << "������" << s2.name << endl;
	cout << "���䣺" << s2.age << endl;
	cout << "������" << s2.score << endl;

	//��ʽ�� ����struct��ʱ��ʹ����ṹ����� ������
	s3.name = "����";
	s3.age = 18;
	s3.score = 66;
	cout << "������" << s3.name << endl;
	cout << "���䣺" << s3.age << endl;
	cout << "������" << s3.score << endl;


	// �ṹ������
	struct Student stuArr[3] = {
		{"����",12,13},
		{"43",13,14},
		{"��5",120,130},
	};
	cout << stuArr[1].name << endl;


	// �ṹ��ָ�� ʹ�� -> ���ʽṹ������
	Student s4 = { "����",123,123 };
	Student* p = &s4;
	cout << p -> name << p-> age<< endl;


	// �ṹ��Ƕ�� 
	Teacher t = { "����",13,s4 };
	cout << t.name << "Ƕ�׵�ѧ��:" << t.stu.name << endl;

	// �ṹ����Ϊ��������
	struct Student stu1 = { "����",153,123 };
	// ֵ���� �޸ĵĻ������޸�ʵ��
	print(stu1); 
	// ��ַ���� �޸ĵĻ����޸�ʵ�� 
	Student *sp2 = &stu1;
	print2(sp2);

	system("pause");
	return 0;
}