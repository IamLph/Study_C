#include<iostream>
using namespace std;
#include"workManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

void Run() {
	WorkManager wm;

	int choice = 0;
	while (true) {
		wm.showMenu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			// 退出系统
			wm.ExitSystem();
			break;
		case 1:
			// 添加
			wm.AddEmp();
			break;
		case 2:
			// 显示
			wm.showEmp();
			break;
		case 3:
			// 删除
			wm.del_emp();
			break;
		case 4:
			// 修改
			wm.Mod_emp();
			break;
		case 5:
			// 查找
			wm.find_emp();
			break;
		case 6:
			// 排序
			wm.sort_emp();
			break;
		case 7:
			// 清空
			wm.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}

}
void testWorker() {
	Worker* worker = NULL;

	worker = new Employee(1,"张三",1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "JackMa", 3);
	worker->showInfo();
	delete worker;


}

int main() {
	Run();
	//testWorker();

	system("pause");
	return 0;
}