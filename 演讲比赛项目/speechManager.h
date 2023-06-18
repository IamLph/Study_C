#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
#include"speaker.h"
#include<numeric>
#include<fstream>
using namespace std;


// .h文件只需要做声明 无需实现

// 比赛管理类
class SpeechManger {
public:
	// 成员属性
// 第一轮选手
	vector<int> v1;
	// 第二轮选手
	vector<int>v2;
	// 前三名
	vector<int>vVictory;
	// 存放编号 以及 具体选手
	map<int, Speaker>m_Speaker;
	// 存放比赛轮数
	int Index;
public:
	SpeechManger();

	~SpeechManger();

	void show_Menu();

	void exitSystem();
	
	// 容器初始化
	void initSpeech();

	// 创建选手
	void createSpeaker();

	// 开始比赛
	void startSpeech();

	// 抽签
	void speechDraw();

	// 比赛
	void speechContest();

	// 显示晋级信息
	void showScore();

	// 保存信息
	void saveRecord();

	// 查看往届记录
	void loadRecord();
	// 文件为空标志
	bool fileIsEmpty;
	// 往届记录
	map<int, vector<string>> m_Record;

	// 显示往届记录
	void showRecord();

	// 清空记录
	void clearRecord();
};