#include<iostream>
using namespace std;
#include<string>
/*
	��Ԫ��Ŀ�ľ�����һ������������ ��������һ�����е�˽�г�Ա
	��ؼ���Ϊ friend
	����ʵ�֣�
		1.ȫ�ֺ���
		2.������Ԫ
		3.��Ա��������Ԫ
*/
// ��Ҫ������
class Building;
// 3.��Ա��������Ԫ
class ggay {
public:
	ggay();
	void visit();
	// ���ò����Է���˽�г�Ա
	void visit2();
private:
	Building* building;
};


class Building {
	// ȫ�ֺ�������Ԫ ���Է���˽�г�Ա ����һ��
	friend void goodGay(Building& building);
	// ������Ԫ
	friend class goodGAY;
	// ��Ա��������Ԫ
	friend void ggay::visit();
public:
	Building();
public:
	string sittingRoom;
private:
	string bedRoom;

};
Building::Building() {
	this->sittingRoom = "����";
	this->bedRoom = "����";
}

ggay::ggay() {
	building = new Building;
}
void ggay::visit() {
	cout << "�û����ڷ���" << building->sittingRoom << endl;
	cout << "�û����ڷ���" << building->bedRoom << endl;
}
void ggay::visit2() {
	cout << "�û���2�ڷ���" << building->sittingRoom << endl;
	//cout << "�û���2�ڷ���" << building->bedRoom << endl;
}

void test03() {
	ggay gg;
	gg.visit();
}
int main() {
	// 3.��Ա��������Ԫ
	test03();
	system("pause");
	return 0;
}