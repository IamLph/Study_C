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


class Building {
	// ȫ�ֺ�������Ԫ ���Է���˽�г�Ա ����һ��
	friend void goodGay(Building& building);
	// ������Ԫ
	friend class goodGAY;
public:
	Building();
public:
	string sittingRoom;
private:
	string bedRoom;

};
Building::Building() {
	sittingRoom = "����";
	bedRoom = "����";
}

// 1.ȫ�ֺ���
void goodGay(Building &building) {
	cout << "�û����ڷ���:" << building.sittingRoom << endl;
	cout << "�û����ڷ���:" << building.bedRoom << endl;
}
void test01() {
	Building building;
	goodGay(building);
}

// 2.������Ԫ
class goodGAY {
public:
	Building* building;
	goodGAY() {
		building = new Building;
	}
	void visit() {
		cout << "�û����ڷ���" << building->sittingRoom << endl;
		cout << "�û����ڷ���" << building->bedRoom << endl;
	};
};

void test02() {
	goodGAY gg;
	gg.visit();
};

int main() {
	// 1.ȫ�ֺ���
	// test01();

	// 2.������Ԫ
	test02();

	system("pause");
	return 0;
}