#include"Cube.h"

using namespace std;

int L;
int W;
int H;

void Cube::setL(int l) {
	L = l;
}
int Cube::getL() {
	return L;
}
void Cube::setW(int w) {
	W = w;
}
int Cube::getW() {
	return W;
}
void Cube::setH(int h) {
	H = h;
}
int Cube::getH() {
	return H;
}
void Cube::S() {
	cout << "���" << L * W * 2 + L * H * 2 + W * H * 2 << endl;
	cout << "���" << L * W * H << endl;
}
// ��Ա����
bool isSame(Cube& c2) {
	if (L == c2.getL() && W == c2.getW() && H == c2.getH()) {
		return true;
	}
	return false;
}
