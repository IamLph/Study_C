#include <iostream>
using namespace std;
#include <string>
int main() {

	// sizeof �ؼ��� �鿴�ֽ�����
	cout << "int size 4:" << sizeof(int) << endl;
	cout << "int size 2:" << sizeof(short) << endl;
	cout << "int size 4:" << sizeof(long) << endl;
	cout << "int size 8:" << sizeof(long long) << endl;
	// ʵ�� float 4�ֽ� double 8�ֽ� ��f��ʾ������ ����Ĭ��Ϊ˫����
	float a1 = 3.14f;
	double a2 = 3.1415926539;
	cout << a1 << ":" << sizeof(a1) << endl;
	cout << a2 << ":" << sizeof(a2) <<  endl;

	// ��ѧ������
	float f1 = 3e2; // 3 * 10^2 == 300
	//float f1 = 3e-2; // 3 * 0.1^2 == 0.03
	cout << f1 << endl;


	// �ַ��� ʹ�õ����� 1�ֽ�
	char c1 = 'a';
	cout << c1 << endl;
	// ת��Ϊ��Ӧ��ASCII���� 97
	cout << int(c1) << endl;


	// ת���ַ� \n:���� \\:�����б��  \t�Ʊ���� �ȵ� �����Լ�ȥ��
	cout << "hello wolrd \n";
	cout << "12" << endl;;


	// �ַ���
	// 1.char ������[] = "*******"
	// 1.string ������ = "*******" ��Ҫͷ�ļ� #include <string>
	char ch1[] = "ABCDEFG";
	cout << ch1 << endl;
	string ch2 = "GFDSA";
	cout << ch2 << endl;

	// �������� 1�ֽ� ��0Ϊ��
	bool flag = true;
	cout << flag << endl;



	system("pause");
	return 0;
}