#include<iostream>
using namespace std;
#include<fstream>

// 1.�������ļ�
class Person {
public:
	char Name[64];
	int Age;
};
void writeFile() {
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "��ʤ��",24 };
	ofs.write((const char*)&p,sizeof(Person));
	ofs.close();
}

void readFile() {
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << p.Age << "��" << p.Name << endl;
	ifs.close();
}


int main() {
	//writeFile();
	readFile();
	system("pause");
	return 0;
}