#include<iostream>
using namespace std;
#include<string>
/*
	友元的目的就是让一个函数或者类 访问另外一个类中的私有成员
	其关键字为 friend
	三种实现：
		1.全局函数
		2.类做友元
		3.成员函数作友元
*/


class Building {
	// 全局函数是友元 可以访问私有成员 声明一下
	friend void goodGay(Building& building);
	// 类做友元
	friend class goodGAY;
public:
	Building();
public:
	string sittingRoom;
private:
	string bedRoom;

};
Building::Building() {
	sittingRoom = "客厅";
	bedRoom = "卧室";
}

// 1.全局函数
void goodGay(Building &building) {
	cout << "好基友在访问:" << building.sittingRoom << endl;
	cout << "好基友在访问:" << building.bedRoom << endl;
}
void test01() {
	Building building;
	goodGay(building);
}

// 2.类做友元
class goodGAY {
public:
	Building* building;
	goodGAY() {
		building = new Building;
	}
	void visit() {
		cout << "好基友在访问" << building->sittingRoom << endl;
		cout << "好基友在访问" << building->bedRoom << endl;
	};
};

void test02() {
	goodGAY gg;
	gg.visit();
};

int main() {
	// 1.全局函数
	// test01();

	// 2.类做友元
	test02();

	system("pause");
	return 0;
}