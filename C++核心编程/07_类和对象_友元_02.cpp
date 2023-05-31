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
// 需要先声明
class Building;
// 3.成员函数作友元
class ggay {
public:
	ggay();
	void visit();
	// 设置不可以访问私有成员
	void visit2();
private:
	Building* building;
};


class Building {
	// 全局函数是友元 可以访问私有成员 声明一下
	friend void goodGay(Building& building);
	// 类做友元
	friend class goodGAY;
	// 成员函数作友元
	friend void ggay::visit();
public:
	Building();
public:
	string sittingRoom;
private:
	string bedRoom;

};
Building::Building() {
	this->sittingRoom = "客厅";
	this->bedRoom = "卧室";
}

ggay::ggay() {
	building = new Building;
}
void ggay::visit() {
	cout << "好基友在访问" << building->sittingRoom << endl;
	cout << "好基友在访问" << building->bedRoom << endl;
}
void ggay::visit2() {
	cout << "好基友2在访问" << building->sittingRoom << endl;
	//cout << "好基友2在访问" << building->bedRoom << endl;
}

void test03() {
	ggay gg;
	gg.visit();
}
int main() {
	// 3.成员函数作友元
	test03();
	system("pause");
	return 0;
}