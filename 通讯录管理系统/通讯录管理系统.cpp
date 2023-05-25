#include<iostream>
#include<string>
using namespace std;
#include "showMenu.h"
#define MAX 1000

// ��ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_sex;
	int m_age;
	string m_Phone;
	string m_Addr;
};

// ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];
	// ��ǰ��ϵ����
	int m_Size;
};


void addPerson(Addressbooks* abs) {
	// �ж��Ƿ�����
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼����,�޷���ӣ���" << endl;
		return;
	}
	else {
		// ���
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		int sex;
		cout << "�������Ա�-->[1 --- ��,0 --- Ů]��" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 0) {
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		// ��������
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "û����ϵ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "����:" << abs->personArray[i].m_Name << "\t"
				<< "�Ա�:" << (abs->personArray[i].m_sex == 1 ? "��":"Ů") << "\t"
				<< "����:" << abs->personArray[i].m_age << "\t"
				<< "�绰:" << abs->personArray[i].m_Phone << "\t"
				<< "��ַ:" << abs->personArray[i].m_Addr << endl;
		}
		system("pause");
		system("cls");
	}
}

// �ж���ϵ���Ƿ����
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	// ����û�еĻ�
	return -1;
}

void deletePerson(Addressbooks *abs) {
	cout << "������Ҫɾ������ϵ�˵�����:" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int i = result; i < abs->m_Size; i++) {
			// ����ǰ�ƽ��и���
			abs->personArray[i] = abs->personArray[i + 1];
		}
		// ���� ����
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs) {
	cout << "������Ҫ�ҵ���:" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "����:" << abs->personArray[result].m_Name << "\t"
			<< "�Ա�:" << (abs->personArray[result].m_sex == 1 ? "��" : "Ů") << "\t"
			<< "����:" << abs->personArray[result].m_age << "\t"
			<< "�绰:" << abs->personArray[result].m_Phone << "\t"
			<< "��ַ:" << abs->personArray[result].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "����:" << abs->personArray[result].m_Name << "\t"
			<< "�Ա�:" << (abs->personArray[result].m_sex == 1 ? "��" : "Ů") << "\t"
			<< "����:" << abs->personArray[result].m_age << "\t"
			<< "�绰:" << abs->personArray[result].m_Phone << "\t"
			<< "��ַ:" << abs->personArray[result].m_Addr << endl;

		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[result].m_Name = name;
		int sex;
		cout << "�������Ա�-->[1 --- ��,0 --- Ů]��" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 0) {
				abs->personArray[result].m_sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[result].m_age = age;
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[result].m_Phone = phone;
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[result].m_Addr = address;
	}
	system("pause");
	system("cls");

};

void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "�����" << endl;
	system("pause");
	system("cls");
}

int main() {

	Addressbooks abs;
	abs.m_Size = 0;

	while (true) {
		// 1.��ʾ�˵�
		showMenu();
		// ����ı���
		int select = 0;
		cin >> select;

		switch (select)
		{
			case 1:
				// �����ϵ��
				addPerson(&abs);
				break;
			case 2:
				// ��ʾ��ϵ��
				showPerson(&abs);
				break;
			case 3:
				// ɾ����ϵ��
				deletePerson(&abs);
			case 4:
				// ������ϵ��
				findPerson(&abs);
				break;
			case 5:
				// �޸���ϵ��
				modifyPerson(&abs);
				break;
			case 6:
				cleanPerson(&abs);
				// �����ϵ��
				break;
			case 0:
				// �˳�
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	}
	
	return 0;
}