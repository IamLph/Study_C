 #pragma once
#include<iostream>
//  pragma once ��ֹͷ�ļ��ظ�����
using namespace std;

class Cube {
private:
	int L;
	int W;
	int H;
public:
	void setL(int l);
	int getL();
	void setW(int w);
	int getW();
	void setH(int h);
	int getH();
	void S();
	// ��Ա����
	bool isSame(Cube& c2);
};