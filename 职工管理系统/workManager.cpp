#include"workManager.h"
// 1.创建管理类
WorkManager::WorkManager() {
	// 初始化分情况考虑
	
	// 文件不存在 bool fileIsEmpty();

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "职工文件不存在" << endl;
		// 初始化属性
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "存在文件 但是为空" << endl;
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	// 文件在 有数据
	int num = this->getEmpNum();
	cout << "当前职工人数为:" << num << endl;
	this->EmpNum = num;
	// 设置数组长度 开辟空间
	this->EmpArray = new Worker * [this->EmpNum];
	// 初始化数据
	this->init_emp();
	//for (int i = 0; i < this->EmpNum; i++) {
	//	cout << this->EmpArray[i]->Id << ":"
	//		<< this->EmpArray[i]->Name << ":"
	//		<< this->EmpArray[i]->DeptId << endl;
	//}


}
WorkManager::~WorkManager() {
	if (this->EmpArray != NULL) {
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}
void WorkManager::showMenu() {
	cout << "*********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统  ************" << endl;
	cout << "*********    0.退出管理系统      ************" << endl;
	cout << "*********    1.增加职工信息      ************" << endl;
	cout << "*********    2.显示职工信息      ************" << endl;
	cout << "*********    3.删除职工信息      ************" << endl;
	cout << "*********    4.修改职工信息      ************" << endl;
	cout << "*********    5.查找职工信息      ************" << endl;
	cout << "*********    6.按照编号排序      ************" << endl;
	cout << "*********    7.清空所有文档      ************" << endl;
	cout << "*********************************************" << endl;

}

void WorkManager::ExitSystem() {
	cout << "欢迎下次使用 " << endl;
	system("pause");
	exit(0);
}
void WorkManager::AddEmp() {
	cout << "请输入要添加职工的数量:" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// 计算添加新的空间大小
		int newSize = this->EmpNum + addNum;
		Worker ** newSpace = new Worker* [newSize];
		// 将原来空间下的数据 拷贝到新的空间下
		if (this->EmpArray != NULL) {
			for (int i = 0; i < this->EmpNum; i++) {
				newSpace[i] = this->EmpArray[i];
			}
		}
		// 添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工的编号:" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名:" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个新职工的岗位:" << endl;
			cout << "1、普通职工   2、经理   3、Boss" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			// 保存到数组中
			newSpace[this->EmpNum + i] = worker;
		}
		//释放原有的空间
		delete[] this->EmpArray;
		// 修改新空间的指向
		this->EmpArray = newSpace;
		// 更新新的职工人数
		this->EmpNum = newSize;
		// 职工不为空
		this->fileIsEmpty = false;
		cout << "成功添加:" << addNum << "人" << endl;
		// 保存数据
		this->save();
	}
	else {
		cout << "输入有误！！" << endl;
	}
	system("pause");
	system("cls");
};
void WorkManager::save() {
	ofstream ofs;
	// 用输出的方式打开文件 -- 写文件
	ofs.open(FILENAME, ios::out); 
	for (int i = 0; i < this->EmpNum; i++) {
		ofs << this->EmpArray[i]->Id << " "
			<< this->EmpArray[i]->Name << " "
			<< this->EmpArray[i]->DeptId << endl;
	}
	ofs.close();
};
// 统计文件人数
int WorkManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	return num;
};

void WorkManager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}else if (dId == 3) {
			worker = new Boss(id, name, dId);
		}
		this->EmpArray[index] = worker;
		index++;
	}
	ifs.close();
};
void WorkManager::showEmp() {
	if (this->fileIsEmpty) {
		cout << "文件不存在或记录为空 ！！" << endl;
	}
	else {
		for (int i = 0; i < EmpNum; i++) {
			// 利用多态调用程序接口
			this->EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");

};

// 判断职工是否存在
int WorkManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++) {
		if (this->EmpArray[i]->Id == id) {
			index = i;
			break;
		}
	}
	return index;
};
// 删除职工
void WorkManager::del_emp() {
	if (this->fileIsEmpty) {
		cout << "文件不存在|记录为空!" << endl;
	}
	else {
		cout << "请输入要删除的职工:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			// 删除即为数据前移
			for (int i = index;i<this->EmpNum-1; i++) {
				this->EmpArray[i] = this->EmpArray[i + 1];
			}
			this->EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "未发现该职工 ！！" << endl;
		}
	}
	system("pause");
	system("cls");
};
void WorkManager::Mod_emp() {
	if (this->fileIsEmpty) {
		cout << "文件不存在|记录为空!" << endl;
	}
	else {
		cout << "请输入要修改的职工:" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1) {
			cout << "未发现该职工 ！！" << endl;
		}
		else {
			delete this->EmpArray[index];
			int newId = 0;
			string newName = "";
			int newDselect = 0;
			cout << "查到:" << id << "号职工，请输入新的职工号" << endl;
			cin >> newId;
			cout << "新名字:" << endl;
			cin >> newName;
			cout << "新岗位:" << endl;
			cout << "1、普通职工   2、经理   3、Boss" << endl;
			cin >> newDselect;

			Worker* worker = NULL;
			switch (newDselect)
			{
			case 1:
				worker = new Employee(newId, newName, newDselect);
				break;
			case 2:
				worker = new Manager(newId, newName, newDselect);
				break;
			case 3:
				worker = new Boss(newId, newName, newDselect);
				break;
			default:
				break;
			}
			this->EmpArray[index] = worker;
			cout << "修改成功 ！" << endl;
			// 保存
			this->save();
		}
	}
	system("pause");
	system("cls");
};

void WorkManager::find_emp() {
	if (this->fileIsEmpty) {
		cout << "文件不存在|记录为空!" << endl;
	}
	else {
		cout << "请输入查找类型[1、编号 2、姓名]:" << endl;
		int type;
		cin >> type;
		if (type == 1) {
			int id;
			cout << "请输入要查找的编号:" << endl;
			cin >> id;
			// 先判断是否存在
			int index = this->IsExist(id);
			if (index == -1) {
				cout << "该职工不存在 !! " << endl;
			}
			else {
				cout << "信息如下 :" << endl;
				this->EmpArray[index]->showInfo();
			}
		}
		else if (type == 2) {
			string name;
			cout << "请输入要查找的姓名:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < EmpNum; i++) {
				if (EmpArray[i]->Name == name) {
					cout << "查找结果如下:" << endl;
					flag = true;
					this->EmpArray[i]->showInfo();
			
				}
			}
			if (flag == false) {
				cout << "没有此人！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
};

void WorkManager::sort_emp() {
	if (this->fileIsEmpty) {
		cout << "文件不存在|记录为空!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式[1、升序，2、降序]:" << endl;
		int type;
		cin >> type;
		// 选择排序算法
		for (int i = 0; i < EmpNum; i++) {
			int minOrMax = i;
			for (int j = i + 1; j < EmpNum; j++) {
				if (type == 1) {
					if (EmpArray[minOrMax]->Id > EmpArray[j]->Id) {
						minOrMax = j;
					}
				}
				else {
					if (EmpArray[minOrMax]->Id < EmpArray[j]->Id) {
						minOrMax = j;
					}
				}
			}
			// 若是不等就交换
			if (i != minOrMax) {
				Worker* temp = EmpArray[i];
				EmpArray[i] = EmpArray[minOrMax];
				EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序完成" << endl;
		this->save();
		this->showEmp();
	}
};


void WorkManager::clean_file() {
	cout << "确认清空?[1、是 2、否]" << endl;
	int type;
	cin >> type;
	if (type == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->EmpArray != NULL) {
			// 删除对象
			for (int i = 0; i < this->EmpNum; i++) {
				delete this->EmpArray[i];
				this->EmpArray[i] = NULL;
			}
			// 删除数组指针
			delete[] this->EmpArray;
			this->EmpArray = NULL;
			this->EmpNum = 0;
			this->fileIsEmpty = true;
		}
		cout << "已清空!" << endl;
	}
	system("pause");
	system("cls");
};