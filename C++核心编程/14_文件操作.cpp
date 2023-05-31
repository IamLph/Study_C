#include<iostream>
#include<string>
using namespace std;
#include<fstream>

// 1.写文件
void writeFile() {
	// 1.引入头文件
	// 2.创建流对象
	ofstream ofs;
	// 3.指定打开方式
	ofs.open("test.txt",ios::out);
	// 4.写内容
	ofs << "哈哈哈哈哈哈憨憨" << endl;
	ofs << "哈哈哈哈哈哈憨憨123" << endl;
	ofs << "哈哈哈哈哈哈憨憨234" << endl;
	ofs.close();
}

// 2.读文件

void readFile() {
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
	}
	// 读数据
	// 第一种
	/*char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}*/

	// 第二种 一行一行获取
	/*char buf[1024] = { 0 };
	
	while (ifs.getline(buf,sizeof(buf))) {
		cout << buf << endl;
	}*/

	// 第三种
	/*string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}*/

	// 第四种 EOF end of file 文件的尾部
	// 不推荐 效率太慢
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}
	// 关闭
	ifs.close();
}


int main() {
	// 写文件
	//writeFile();

	// 读文件
	readFile();

	system("pause");
	return 0;
}