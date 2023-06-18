#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;
#include"speechManager.h"

int main() {
	// ����ϵͳʱ��ʵ����ʵ���
	srand((unsigned int)time(NULL));
	// ����������
	SpeechManger sm;
	
	// ����
	int choice = 0;
	while (true) {
		// չʾ�˵�
		sm.show_Menu();
		cout << "ѡ�����:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.startSpeech();
			// ��ʼ����
			break;
		case 2:
			sm.loadRecord();
			// �鿴��¼
			break;
		case 3:
			sm.clearRecord();
			// ��ռ�¼
			break;
		case 0:
			// �˳�ϵͳ
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
��������:
	ѧУ����һ���ݽ�����������12���˲μӡ����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
	ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ��� 10001~10012
	������ʽ: ���������ÿ��6����;
	��һ�ַ�Ϊ����С�飬���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ�.
	ʮ����ί�ֱ��ÿ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣����ƽ����Ϊ����ѡ�ֵĳɼ�
	��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵıȺ�
	�ڶ���Ϊ������ǰ����ʤ��
	ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ
*/