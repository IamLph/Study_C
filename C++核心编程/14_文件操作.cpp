#include<iostream>
#include<string>
using namespace std;
#include<fstream>

// 1.д�ļ�
void writeFile() {
	// 1.����ͷ�ļ�
	// 2.����������
	ofstream ofs;
	// 3.ָ���򿪷�ʽ
	ofs.open("test.txt",ios::out);
	// 4.д����
	ofs << "����������������" << endl;
	ofs << "����������������123" << endl;
	ofs << "����������������234" << endl;
	ofs.close();
}

// 2.���ļ�

void readFile() {
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	// ������
	// ��һ��
	/*char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}*/

	// �ڶ��� һ��һ�л�ȡ
	/*char buf[1024] = { 0 };
	
	while (ifs.getline(buf,sizeof(buf))) {
		cout << buf << endl;
	}*/

	// ������
	/*string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}*/

	// ������ EOF end of file �ļ���β��
	// ���Ƽ� Ч��̫��
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}
	// �ر�
	ifs.close();
}


int main() {
	// д�ļ�
	//writeFile();

	// ���ļ�
	readFile();

	system("pause");
	return 0;
}