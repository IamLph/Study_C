#include<iostream>
using namespace std;
#include<string>
#include"07_MyArray.hpp"
/*
��������:ʵ��һ��ͨ�õ������࣬Ҫ�����£�
	���Զ��������������Լ��Զ����������͵����ݽ��д洢��
	�������е����ݴ洢��������
	���캯���п��Դ������������ T��
	�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ�������⡣
	�ӿڣ�
	1.�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ����
	2.����ͨ���±�ķ�ʽ���������е�Ԫ�ء�
	3.���Ի�ȡ�����е�ǰԪ�ظ��������������
*/
// ���ݴ�ӡ
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}
void test() {
	// ������ͨ����
	MyArray<int> arr1(5);
	// ���Կ�������
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;
}
void test2() {
	MyArray<int> arr1(5);
	for (int i = 1; i < 6; i++) {
		arr1.Push_Back(i);
	}
	printIntArray(arr1);
	cout << "����:" << arr1.getCapacity() << endl;
	cout << "��С:" << arr1.getSize() << endl;
	
	MyArray<int> arr2(arr1);
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2��С:" << arr2.getSize() << endl;
}

// �����Զ�����������
class Person {
public:
	string Name;
	int Age;

	Person(){}
	Person(string name,int age){
		this->Name = name;
		this->Age = age;
	}
};
// ���ݴ�ӡ
void printPersontArray(MyArray<Person>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i].Name <<":" << arr[i].Age << endl;
	}
}
void test3() {
	MyArray<Person> arr(10);
	Person p1("1",10);
	Person p2("2",11);
	Person p3("3",12);
	Person p4("4",13);
	Person p5("5",14);
	Person p6("6",15);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	arr.Push_Back(p6);
	printPersontArray(arr);
	cout << "����:" << arr.getCapacity() << endl;
	cout << "��С:" << arr.getSize() << endl;
}
int main() {
	//test();
	//test2();

	test3();
	system("pause");
	return 0;
}