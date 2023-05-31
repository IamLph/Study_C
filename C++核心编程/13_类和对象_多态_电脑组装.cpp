#include<iostream>
#include<string>
using namespace std;

//零件
class CPU {
public:
	virtual void calcuate() = 0;
};
// 显卡
class VideoCard {
public:
	virtual void display() = 0;
};
// 内存
class Memory {
public:
	virtual void storage() = 0;
};
// 电脑
class Computer {
private:
	CPU* Cpu;
	VideoCard* Vc;
	Memory* Mem;
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		Cpu = cpu;
		Vc = vc;
		Mem = mem;
	}
	void work() {
		Cpu->calcuate();
		Vc->display();
		Mem->storage();
	}
	~Computer() {
		if (Cpu != NULL) {
			delete Cpu;
			Cpu = NULL;
		}
		if (Vc != NULL) {
			delete Vc;
			Vc = NULL;
		}
		if (Mem != NULL) {
			delete Mem;
			Mem = NULL;
		}
	}
};
// 具体的厂商
class IntelCPU :public CPU {
public:
	virtual void calcuate() {
		cout << "Interl的CPU" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Interl的显卡 " << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Interl的内存" << endl;
	}
};
// 华为
class HuaWeiCPU :public CPU {
public:
	virtual void calcuate() {
		cout << "HuaWei的CPU" << endl;
	}
};
class HuaWeiVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "HuaWei的显卡 " << endl;
	}
};
class HuaWeiMemory :public Memory {
public:
	virtual void storage() {
		cout << "HuaWei的内存" << endl;
	}
};


// 租装
void test() {
	CPU* intelCpu = new IntelCPU;
	VideoCard* vic = new HuaWeiVideoCard;
	Memory* mem = new IntelMemory;

	Computer* cp = new Computer(intelCpu, vic, mem);
	cp->work();
	delete cp;
}
int main() {
	test();
	system("pause");
	return 0;
}