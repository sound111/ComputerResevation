#include"Manager.h"
#include"Student.h"
#include"Teacher.h"
#include"GlobalFile.h"
#include<fstream>
#include<string>
#include <algorithm>
using namespace std;

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->Name = name;
	this->Password = pwd;

	initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.ID && ifs >> c.Capacity)
	{
		vCom.push_back(c);
	}

	ifs.close();

	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
}

Manager::~Manager()
{

}

void printStudent(Student& s)
{
	cout << "ID:" << s.ID <<" " << "Name:" << s.Name <<" " << "Password:" << s.Password << endl;
}

void printTeacher(Teacher& s)
{
	cout << "ID:" << s.ID<<" " << "Name:" << s.Name <<" " << "Password:" << s.Password << endl;

}

void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.ѧ���˺�" << endl;
	cout << "2.��ʦ�˺�" << endl;

	int choice;
	cin >> choice;

	if (choice == 1)
	{
		cout << "����ѧ���˺���Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (choice == 2)
	{
		cout << "���н�ʦ�˺���Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

bool Manager::checkRepeat(string id, int type)
{
	if (type == 1)//ѧ��
	{
		for (vector<Student> ::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->ID)
			{
				return true;
			}
		}
	}
	else if (type == 2)//��ʦ
	{
		for (vector<Teacher> ::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->ID)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;

	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "ID:" << it->ID << " " << "Name:" << it->Capacity << endl;

	}

	system("pause");
	system("cls");
}

void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);

	ofs.close();

	cout << "��ճɹ�" << endl;

	system("pause");
	system("cls");
}

void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1.���ѧ���˺�" << endl;
	cout << "2.�����ʦ�˺�" << endl;

	int choice;
	cin >> choice;

	string filename;
	ofstream ofs;

	string id;
	string name;
	string pwd;

	string errorTip;

	if (choice == 1)
	{
		filename = STUDENT_FILE;
		cout << "������ѧ�ţ�" << endl;
		errorTip = "ѧ���ظ������������룡";
	}
	else if (choice == 2)
	{
		filename = TEACHER_FILE;
		cout << "������ְ���ţ�" << endl;
		errorTip = "ְ�����ظ������������룡";
	}

	while (true)
	{
		cin >> id;

		bool result = this->checkRepeat(id, choice);

		if (result)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	

	ofs.open(filename,  ios::app);

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;

	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	initVector();
}

void Manager::Menu()
{
	cout << "����ԤԼϵͳ" << endl;
	cout << "����Ա���幦��" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "5.�˳���¼" << endl;
}


void Manager::initVector()
{
	ifstream ifs;

	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;

	while (ifs >> s.ID && ifs >> s.Name && ifs >> s.Password)
	{
		vStu.push_back(s);
	}

	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;

	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;

	while (ifs >> t.ID && ifs >> t.Name && ifs >> t.Password)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;

	ifs.close();
}