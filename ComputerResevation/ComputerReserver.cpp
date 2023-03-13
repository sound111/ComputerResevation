#include"ComputerReserver.h"
#include<fstream>

void studentMenu(Person*& student)
{
	while (true)
	{
		Student* s = (Student*)student;
		s->Menu();

		cout << "请输入您的选择：" << endl;
		int choice=0;
		cin >> choice;

		switch (choice)
		{
		case 1:
			s->apply();
			break;
		case 2:
			s->printMyApply();
			break;
		case 3:
			s->printAllApply();
			break;
		case 4:
			s->cancelApply();
			break;
		case 5:
			delete s;

			cout << "退出成功" << endl;
			system("pause");
			system("cls");

			return;
		default:
			cout << "输入错误，请重新输入！" << endl;

			system("pause");
			system("cls");
		}
	}
}

//多态
void managerMenu(Person*& manager)
{
	while (true)
	{
		manager->Menu();

		Manager* m = (Manager*)manager;//父类指针强转成子类指针，否则只能调用公共的接口

		cout << "请输入您的选择：" << endl;

		int choice = 0;

		cin >> choice;

		switch (choice)
		{
		case 1:
			m->addPerson();
			break;
		case 2:
			m->showPerson();
			break;
		case 3:
			m->showComputer();
			break;
		case 4:
			m->cleanFile();
			break;
		case 5:
			delete manager;
			cout << "退出成功" << endl;

			system("pause");
			system("cls");

			return;
		default:
			cout << "输入错误，请重新输入：";

			system("pause");
			system("cls");
			break;
		}
	}
}

void teacherMenu(Person*& teacher)
{
	while (true)
	{
		Teacher* t = (Teacher*)teacher;

		t->Menu();

		cout << "请输入您的选择：" << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			t->CheckAllApply();
			break;
		case 2:
			t->AuditApply();
			break;
		case 3:
			delete t;

			cout << "退出成功" << endl;
			
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误，请重新输入！" << endl;

			system("pause");
			system("cls");
			break;
		}
	}
}

ComputerReserver::ComputerReserver()
{

}

void ComputerReserver::showMenu()
{
	cout << "机房预约系统" << endl;
	cout << "****登录****" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;
	cout << "3.管理员" << endl;
	cout << "4.退出系统" << endl;
}

ComputerReserver::~ComputerReserver()
{

}

void ComputerReserver::exitSystem()
{
	cout << "欢迎下次使用！" << endl;

	system("pause");

	exit(0);
}

void LoginIn(string filename, int type)
{
	Person* person = NULL;

	ifstream ifs(filename,ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	string id;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入职工号：" << endl;
		cin >> id;
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	string fid;
	string fname;
	string fpwd;


	if (type == 1)
	{
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生登录成功！" << endl;

				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师登录成功！" << endl;

				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "管理员登录成功！" << endl;

				system("pause");
				system("cls");

				person = new Manager(name, pwd);//静态多态
				managerMenu(person);

				return;
			}
		}
	}

	cout << "登录失败" << endl;

	system("pause");
	system("cls");

	return;
}



int main()
{
	ComputerReserver cr;

	while (true)
	{
		cr.showMenu();

		cout << "请输入您的选择：" << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(MANAGER_FILE, 3);
			break;
		case 4:
			cr.exitSystem();
			break;
		default:
			cout << "输入有误，请重新输入:" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");

	return 0;
}