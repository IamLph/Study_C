#include<iostream>
#include<string>
using namespace std;

//���
class CPU {
public:
	virtual void calcuate() = 0;
};
// �Կ�
class VideoCard {
public:
	virtual void display() = 0;
};
// �ڴ�
class Memory {
public:
	virtual void storage() = 0;
};
// ����
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
// ����ĳ���
class IntelCPU :public CPU {
public:
	virtual void calcuate() {
		cout << "Interl��CPU" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Interl���Կ� " << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Interl���ڴ�" << endl;
	}
};
// ��Ϊ
class HuaWeiCPU :public CPU {
public:
	virtual void calcuate() {
		cout << "HuaWei��CPU" << endl;
	}
};
class HuaWeiVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "HuaWei���Կ� " << endl;
	}
};
class HuaWeiMemory :public Memory {
public:
	virtual void storage() {
		cout << "HuaWei���ڴ�" << endl;
	}
};


// ��װ
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