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


// .h�ļ�ֻ��Ҫ������ ����ʵ��

// ����������
class SpeechManger {
public:
	// ��Ա����
// ��һ��ѡ��
	vector<int> v1;
	// �ڶ���ѡ��
	vector<int>v2;
	// ǰ����
	vector<int>vVictory;
	// ��ű�� �Լ� ����ѡ��
	map<int, Speaker>m_Speaker;
	// ��ű�������
	int Index;
public:
	SpeechManger();

	~SpeechManger();

	void show_Menu();

	void exitSystem();
	
	// ������ʼ��
	void initSpeech();

	// ����ѡ��
	void createSpeaker();

	// ��ʼ����
	void startSpeech();

	// ��ǩ
	void speechDraw();

	// ����
	void speechContest();

	// ��ʾ������Ϣ
	void showScore();

	// ������Ϣ
	void saveRecord();

	// �鿴�����¼
	void loadRecord();
	// �ļ�Ϊ�ձ�־
	bool fileIsEmpty;
	// �����¼
	map<int, vector<string>> m_Record;

	// ��ʾ�����¼
	void showRecord();

	// ��ռ�¼
	void clearRecord();
};