 #pragma once
#include<iostream>
//  pragma once 防止头文件重复包含
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
	// 成员函数
	bool isSame(Cube& c2);
};