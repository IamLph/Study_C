#include<iostream>
using namespace std;
#include<string>
// 结构体
/*
	struct 类型名称 { 成员列表 }
*/
struct Student {
	string name;
	int age;
	int score;
}s3;

// 结构体嵌套
struct Teacher {
	string name;
	int age;
	struct Student stu;
};

void print(Student stu) {
	cout << stu.name << "-" << stu.age << "-" << stu.score << endl;
}
void print2(Student * stu) {
	cout << stu->name << "-" << stu->age << "-" << stu->score << endl;
}

int main() {

	// 结构体创建学生并赋值
	// 方式一
	struct Student s1;
	s1.name = "张三";
	s1.age = 18;
	s1.score = 66;

	cout << "姓名：" << s1.name << endl;
	cout << "年龄：" << s1.age << endl;
	cout << "分数：" << s1.score << endl;

	// 方式二
	struct Student s2 = {"王五",23,13};
	cout << "姓名：" << s2.name << endl;
	cout << "年龄：" << s2.age << endl;
	cout << "分数：" << s2.score << endl;

	//方式三 创建struct的时候就创建结构体变量 看上面
	s3.name = "张三";
	s3.age = 18;
	s3.score = 66;
	cout << "姓名：" << s3.name << endl;
	cout << "年龄：" << s3.age << endl;
	cout << "分数：" << s3.score << endl;


	// 结构体数组
	struct Student stuArr[3] = {
		{"张三",12,13},
		{"43",13,14},
		{"张5",120,130},
	};
	cout << stuArr[1].name << endl;


	// 结构体指针 使用 -> 访问结构体属性
	Student s4 = { "阿三",123,123 };
	Student* p = &s4;
	cout << p -> name << p-> age<< endl;


	// 结构体嵌套 
	Teacher t = { "阿玉",13,s4 };
	cout << t.name << "嵌套的学生:" << t.stu.name << endl;

	// 结构体作为函数参数
	struct Student stu1 = { "阿五",153,123 };
	// 值传递 修改的话不会修改实参
	print(stu1); 
	// 地址传递 修改的话会修改实参 
	Student *sp2 = &stu1;
	print2(sp2);

	system("pause");
	return 0;
}