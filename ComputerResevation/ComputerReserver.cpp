#include"ComputerReserver.h"
#include<fstream>

void studentMenu(Person*& student)
{
	while (true)
	{
		Student* s = (Student*)student;
		s->Menu();

		cout << "����������ѡ��" << endl;
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

			cout << "�˳��ɹ�" << endl;
			system("pause");
			system("cls");

			return;
		default:
			cout << "����������������룡" << endl;

			system("pause");
			system("cls");
		}
	}
}

//��̬
void managerMenu(Person*& manager)
{
	while (true)
	{
		manager->Menu();

		Manager* m = (Manager*)manager;//����ָ��ǿת������ָ�룬����ֻ�ܵ��ù����Ľӿ�

		cout << "����������ѡ��" << endl;

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
			cout << "�˳��ɹ�" << endl;

			system("pause");
			system("cls");

			return;
		default:
			cout << "����������������룺";

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

		cout << "����������ѡ��" << endl;

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

			cout << "�˳��ɹ�" << endl;
			
			system("pause");
			system("cls");
			return;
		default:
			cout << "����������������룡" << endl;

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
	cout << "����ԤԼϵͳ" << endl;
	cout << "****��¼****" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	cout << "3.����Ա" << endl;
	cout << "4.�˳�ϵͳ" << endl;
}

ComputerReserver::~ComputerReserver()
{

}

void ComputerReserver::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;

	system("pause");

	exit(0);
}

void LoginIn(string filename, int type)
{
	Person* person = NULL;

	ifstream ifs(filename,ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	string id;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
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
				cout << "ѧ����¼�ɹ���" << endl;

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
				cout << "��ʦ��¼�ɹ���" << endl;

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
				cout << "����Ա��¼�ɹ���" << endl;

				system("pause");
				system("cls");

				person = new Manager(name, pwd);//��̬��̬
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��¼ʧ��" << endl;

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

		cout << "����������ѡ��" << endl;

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
			cout << "������������������:" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");

	return 0;
}