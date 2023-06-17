#include<iostream>
using namespace std;
#include<string>
#include"07_MyArray.hpp"
/*
案例描述:实现一个通用的数组类，要求如下：
	可以对内置数据类型以及自定义数据类型的数据进行存储。
	将数组中的数据存储到堆区。
	构造函数中可以传入数组的容量 T。
	提供对应的拷贝构造函数以及operator=防止浅拷贝问题。
	接口：
	1.提供尾插法和尾删法对数组中的数据进行增加和删除。
	2.可以通过下标的方式访问数组中的元素。
	3.可以获取数组中当前元素个数和数组的容量
*/
// 数据打印
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}
void test() {
	// 测试普通构造
	MyArray<int> arr1(5);
	// 测试拷贝构造
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
	cout << "容量:" << arr1.getCapacity() << endl;
	cout << "大小:" << arr1.getSize() << endl;
	
	MyArray<int> arr2(arr1);
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2大小:" << arr2.getSize() << endl;
}

// 测试自定义数据类型
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
// 数据打印
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
	cout << "容量:" << arr.getCapacity() << endl;
	cout << "大小:" << arr.getSize() << endl;
}
int main() {
	//test();
	//test2();

	test3();
	system("pause");
	return 0;
}