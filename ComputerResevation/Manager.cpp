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

	cout << "当前机房数量为：" << vCom.size() << endl;
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
	cout << "请选择查看内容：" << endl;
	cout << "1.学生账号" << endl;
	cout << "2.教师账号" << endl;

	int choice;
	cin >> choice;

	if (choice == 1)
	{
		cout << "所有学生账号信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (choice == 2)
	{
		cout << "所有教师账号信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

bool Manager::checkRepeat(string id, int type)
{
	if (type == 1)//学生
	{
		for (vector<Student> ::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->ID)
			{
				return true;
			}
		}
	}
	else if (type == 2)//老师
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
	cout << "机房信息如下：" << endl;

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

	cout << "清空成功" << endl;

	system("pause");
	system("cls");
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1.添加学生账号" << endl;
	cout << "2.添加老师账号" << endl;

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
		cout << "请输入学号：" << endl;
		errorTip = "学号重复，请重新输入！";
	}
	else if (choice == 2)
	{
		filename = TEACHER_FILE;
		cout << "请输入职工号：" << endl;
		errorTip = "职工号重复，请重新输入！";
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

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;

	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	initVector();
}

void Manager::Menu()
{
	cout << "机房预约系统" << endl;
	cout << "管理员具体功能" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "5.退出登录" << endl;
}


void Manager::initVector()
{
	ifstream ifs;

	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;

	while (ifs >> s.ID && ifs >> s.Name && ifs >> s.Password)
	{
		vStu.push_back(s);
	}

	cout << "当前学生数量为：" << vStu.size() << endl;

	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;

	while (ifs >> t.ID && ifs >> t.Name && ifs >> t.Password)
	{
		vTea.push_back(t);
	}

	cout << "当前教师数量为：" << vTea.size() << endl;

	ifs.close();
}