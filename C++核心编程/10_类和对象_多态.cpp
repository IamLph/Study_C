#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
	// �麯�� ���
	virtual void speak() {
		cout << "Animal˵��" << endl;
	}
};
class Cat :public Animal {
public:
	void speak() {
		cout << "Cat˵��" << endl;
	}
};

// ��ַ�ڱ���׶ξ�ȷ���˵�ַ ������Animal�ĺ���
// �����Ҫʹ��virtual���
// ��������д������麯����ʱ�򣬾ͻᷢ��һ����д����
// �����е��麯�����ڲ����滻��������麯����ַ
void doSpeak(Animal& animal) {
	animal.speak();
}
void cat_t() {
	Cat cat;
	doSpeak(cat);
}

int main() {
	cat_t(); 

	system("pause");
	return 0;
}