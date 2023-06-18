#include"speechManager.h"

SpeechManger::SpeechManger() {
	// 初始化
	this->initSpeech();
	// 选手初始化
	this->createSpeaker();
}
SpeechManger::~SpeechManger() {

}
void SpeechManger::show_Menu() {
	cout << "********************************" << endl;
	cout << "******** $.欢迎参加比赛 ********" << endl;
	cout << "******** 1.开始演讲比赛 ********" << endl;
	cout << "******** 2.查看往届记录 ********" << endl;
	cout << "******** 3.清空比赛记录 ********" << endl;
	cout << "******** 0.退出比赛程序 ********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}
void SpeechManger::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManger::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	// 比赛轮数
	this->Index = 1;
	// 初始化记录容器
	this->m_Record.clear();
}
void SpeechManger::createSpeaker() {
	string NameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < NameSeed.size(); i++) {
		string name = "选手";
		name += NameSeed[i];
		Speaker sp;
		sp.Name = name;
		for (int j = 0; j < 2; j++) {
			sp.Score[j] = 0;
		}
		// 12名选手的编号
		this->v1.push_back(i + 10001);

		// 选手编号以及选手 map存放
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManger::speechDraw() {
	cout << "第<< " << this->Index << " >> 轮比赛正在进行抽签" << endl;
	cout << "--------------" << endl;
	cout << "抽签顺序如下:" << endl;
	if (this->Index == 1) {
		// 随机打乱 洗牌算法
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;
	system("pause");
	cout << endl;
}
void SpeechManger::speechContest() {
	cout << "第<< " << this->Index << "  >>轮比赛正式开始:" << endl;
	// 临时容器保存分数、选手编号 并且降序排序
	multimap<double, int, greater<double>> groupScore;
	// 记录人数 6个1组
	int num = 0;
	vector<int>v_Src;
	if (this->Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	// 遍历所有选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;

		// 打分
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			// 600~1000
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		// 排序
		sort(d.begin(), d.end(), greater<double>());
		// 去除最高分与最低分
		d.pop_front();
		d.pop_back();

		// 获取总分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		// 平均分
		double avg = sum / (double)d.size();
		// 每个人的平均分
		this->m_Speaker[*it].Score[this->Index - 1] = avg;
		// 六人一组 临时容器保存 *it为选手编号
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组比赛名次:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				// m_Speaker map类型 存放编号 以及 具体选手Speaker
				cout << "编号: " << it->second <<
					"  姓名:" << this->m_Speaker[it->second].Name <<
					"  成绩:" << this->m_Speaker[it->second].Score[this->Index - 1] << endl;
			}
			int count = 0;
			// 取前三名 放到v2容器里面 存放的是成员编号
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); 
				it != groupScore.end() && count < 3; it++,count++) {
				if (this->Index == 1) {
					v2.push_back((*it).second);
				}
				else {
					vVictory.push_back((*it).second);
				}
			}
			// 小组容器清空
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "第" << this->Index << "比赛已完毕" << endl;
	system("pause");

}

void SpeechManger::showScore() {
	cout << "---------------第<<  " << this->Index << "  >>晋级选手信息如下" << endl;
	
	vector<int>v;
	if (this->Index == 1) {
		// 第一轮就复制v2的信息
		v = v2;
	}
	else {
		// 第二轮就显示胜利者信息
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "选手编号:" << *it <<
			"\t姓名:" << m_Speaker[*it].Name <<
			"\t得分:" << m_Speaker[*it].Score[this->Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}
void SpeechManger::saveRecord() {
	ofstream ofs;
	// 打开文件方式 并且用追加的方式
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	// 文件不空了
	this->fileIsEmpty = false;
}
void SpeechManger::startSpeech() {
	// 第一轮比赛
	// 1.抽签
	this->speechDraw();
	// 2.比赛
	this->speechContest();
	// 3.显示晋级结果
	this->showScore();
	// 第二轮比赛
	this->Index++;
	// 1.抽签
	this->speechDraw();
	// 2.比赛
	this->speechContest();
	// 3.显示晋级结果
	this->showScore();
	// 4.保存分数到文件
	this->saveRecord();
	// 重置比赛
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "比赛完毕！" << endl;
	system("pause");
	system("cls");
};
void SpeechManger::loadRecord() {
	// 输入流 读取文件
	ifstream ifs("speech.csv", ios::in);
	// 首先判断是否打开成功
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}else{
		char ch;
		ifs >> ch;
		// 文件判空
		if (ifs.eof()) {
			cout << "文件为空" << endl;
			this->fileIsEmpty = true;
			ifs.close();
			return;
		}
		else {
			this->fileIsEmpty = false;
			// 读取单个字符放回去
			ifs.putback(ch);
			string data;
			// 第几届
			int index = 0;
			while (ifs >> data) {
				//cout << data << endl;
				//10002, 85.6625, 10008, 84.9, 10005, 83.2625,
				vector<string>v;
				int pos = -1;
				int start = 0;
				while (true) {
					pos = data.find(",", start);
					if (pos == -1) {
						// 找不到返回
						break;
					}
					else {
						string tmp = data.substr(start, pos - start);
						v.push_back(tmp);
						start = pos + 1;
					}
				}
				this->m_Record.insert(make_pair(index, v));
				index++;
			}
			
		}
	}
	ifs.close();
	this->showRecord();
}
void SpeechManger::showRecord() {
	if (this->fileIsEmpty) {
		cout << "文件为空或者文件不存在 ！" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++) {
			cout << "第" << i + 1 << "届\n" <<
				"冠军编号:" << this->m_Record[i][0] << "\t得分" << this->m_Record[i][1] << "\n" <<
				"亚军编号:" << this->m_Record[i][2] << "\t得分" << this->m_Record[i][3] << "\n" <<
				"季军编号:" << this->m_Record[i][4] << "\t得分" << this->m_Record[i][4] << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void SpeechManger::clearRecord() {
	cout << "确认清空" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		// 打开模式 如果存在删除文件就重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "清空成功 !" << endl;
	}
	system("pause");
	system("cls");

}