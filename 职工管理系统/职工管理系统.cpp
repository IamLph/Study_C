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
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			// �˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:
			// ���
			wm.AddEmp();
			break;
		case 2:
			// ��ʾ
			wm.showEmp();
			break;
		case 3:
			// ɾ��
			wm.del_emp();
			break;
		case 4:
			// �޸�
			wm.Mod_emp();
			break;
		case 5:
			// ����
			wm.find_emp();
			break;
		case 6:
			// ����
			wm.sort_emp();
			break;
		case 7:
			// ���
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

	worker = new Employee(1,"����",1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
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