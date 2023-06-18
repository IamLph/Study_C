#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;
#include"speechManager.h"

int main() {
	// 利用系统时间实现真实随机
	srand((unsigned int)time(NULL));
	// 创建管理类
	SpeechManger sm;
	
	// 操作
	int choice = 0;
	while (true) {
		// 展示菜单
		sm.show_Menu();
		cout << "选择操作:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.startSpeech();
			// 开始比赛
			break;
		case 2:
			sm.loadRecord();
			// 查看记录
			break;
		case 3:
			sm.clearRecord();
			// 清空记录
			break;
		case 0:
			// 退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}

	}


	system("pause");
	return 0;
}
/*
比赛规则:
	学校举行一场演讲比赛，共有12个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
	每名选手都有对应的编号，如 10001~10012
	比赛方式: 分组比赛，每组6个人;
	第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲.
	十个评委分别给每名选手打分，去除最高分和最低分，求的平均分为本轮选手的成绩
	当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比寒
	第二轮为决寒，前三名胜出
	每轮比赛过后需要显示晋级选手的信息
*/