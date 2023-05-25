#include<iostream>
#include<string>
using namespace std;
#include "showMenu.h"
#define MAX 1000

// 联系人结构体
struct Person {
	string m_Name;
	int m_sex;
	int m_age;
	string m_Phone;
	string m_Addr;
};

// 通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];
	// 当前联系人数
	int m_Size;
};


void addPerson(Addressbooks* abs) {
	// 判断是否人满
	if (abs->m_Size == MAX) {
		cout << "通讯录已满,无法添加！！" << endl;
		return;
	}
	else {
		// 添加
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		int sex;
		cout << "请输入性别-->[1 --- 男,0 --- 女]：" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 0) {
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		// 更新人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "没有联系人" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名:" << abs->personArray[i].m_Name << "\t"
				<< "性别:" << (abs->personArray[i].m_sex == 1 ? "男":"女") << "\t"
				<< "年龄:" << abs->personArray[i].m_age << "\t"
				<< "电话:" << abs->personArray[i].m_Phone << "\t"
				<< "地址:" << abs->personArray[i].m_Addr << endl;
		}
		system("pause");
		system("cls");
	}
}

// 判断联系人是否存在
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	// 若是没有的话
	return -1;
}

void deletePerson(Addressbooks *abs) {
	cout << "请输入要删除的联系人的姓名:" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = result; i < abs->m_Size; i++) {
			// 数据前移进行覆盖
			abs->personArray[i] = abs->personArray[i + 1];
		}
		// 更新 人数
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs) {
	cout << "请输入要找的人:" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名:" << abs->personArray[result].m_Name << "\t"
			<< "性别:" << (abs->personArray[result].m_sex == 1 ? "男" : "女") << "\t"
			<< "年龄:" << abs->personArray[result].m_age << "\t"
			<< "电话:" << abs->personArray[result].m_Phone << "\t"
			<< "地址:" << abs->personArray[result].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名:" << abs->personArray[result].m_Name << "\t"
			<< "性别:" << (abs->personArray[result].m_sex == 1 ? "男" : "女") << "\t"
			<< "年龄:" << abs->personArray[result].m_age << "\t"
			<< "电话:" << abs->personArray[result].m_Phone << "\t"
			<< "地址:" << abs->personArray[result].m_Addr << endl;

		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[result].m_Name = name;
		int sex;
		cout << "请输入性别-->[1 --- 男,0 --- 女]：" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 0) {
				abs->personArray[result].m_sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[result].m_age = age;
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[result].m_Phone = phone;
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[result].m_Addr = address;
	}
	system("pause");
	system("cls");

};

void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}

int main() {

	Addressbooks abs;
	abs.m_Size = 0;

	while (true) {
		// 1.显示菜单
		showMenu();
		// 输入的变量
		int select = 0;
		cin >> select;

		switch (select)
		{
			case 1:
				// 添加联系人
				addPerson(&abs);
				break;
			case 2:
				// 显示联系人
				showPerson(&abs);
				break;
			case 3:
				// 删除联系人
				deletePerson(&abs);
			case 4:
				// 查找联系人
				findPerson(&abs);
				break;
			case 5:
				// 修改联系人
				modifyPerson(&abs);
				break;
			case 6:
				cleanPerson(&abs);
				// 清空联系人
				break;
			case 0:
				// 退出
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	}
	
	return 0;
}