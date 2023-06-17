#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<ctime>
using namespace std;
/*
	公司今天招聘了10个员工 (ABCDEFGHI)，10名员工进入公司之后，需要指派员工在那个部门工作。
	员工信息有: 姓名 工资组成，部门分为: 策划、美术、研发
	随机给10名员工分配部门和工资
	通过multimap进行信息的插入 kev(部门编号)value(员工
	分部门显示员工信息
*/
// 创建员工+
class Worker {
public:
	string Name;
	int Salary;
	Worker(string name, int salary) {
		this->Name = name;
		this->Salary = salary;
	}
};
void createWorker(vector<Worker>&v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		string name = "员工" ;
		name += nameSeed[i];
		int salary = rand() % 10000 + 10000; 
		// 10000~19999
		Worker w(name, salary);
		v.push_back(w);
	}
}
void setGroup(vector<Worker>&v, multimap<int, Worker>&mm) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		// 产生随机部门编号
		int deptId = rand() % 3;
		// 将员工插入到分组中
		mm.insert(make_pair(deptId, *it));
	}
}
void showWorker(vector<Worker> &w) {
	for (vector<Worker>::iterator it = w.begin(); it != w.end(); it++) {
		cout << "姓名:" << it->Name << "  薪水:" << it->Salary << endl;
	}
	cout << endl;
}
void showMmWorker(multimap<int, Worker>& mm) {
	map<int, string> m;
	m.insert(make_pair(0, "策划部门"));
	m.insert(make_pair(1, "美术部门"));
	m.insert(make_pair(2, "策划部门"));
	cout << m[0] << endl;
	for (multimap<int, Worker>::iterator it = mm.begin(); it != mm.end(); it++) {
		cout << "部门:" << m[it->first] << "  姓名:" << it->second.Name << "  薪资:" << it->second.Salary << endl;
	}
}
int main() {
	// 利用系统时间实现真实随机
	srand((unsigned int)time(NULL));
	// 1.创建员工
	vector<Worker> v;
	createWorker(v);
	//showWorker(v);

	// 2.员工分组
	multimap<int, Worker>mm;
	setGroup(v,mm);

	// 3.分组显示员工
	showMmWorker(mm);

	system("pause");
	return 0;
}