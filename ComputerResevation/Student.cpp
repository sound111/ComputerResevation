#include"Student.h"
#include"GlobalFile.h"
#include"OrderFile.h"
#include<fstream>

Student::Student(string id, string name, string pwd)
{
	this->ID = id;
	this->Name = name;
	this->Password = pwd;

	ifstream ifs(COMPUTER_FILE, ios::in);

	ComputerRoom cr;

	while (ifs >> cr.ID && ifs >> cr.Capacity)
	{
		vCom.push_back(cr);
	}
}

Student::~Student()
{

}

Student::Student()
{

}

void Student::Menu()
{
	cout << "����ԤԼϵͳ" << endl;
	cout << "ѧ�����幦��" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�����ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "5.�˳���¼" << endl;
}

void Student::apply()
{
	cout << "����ԤԼ" << endl;

	cout << "��ѡ��ԤԼʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date;

	while (true)
	{
		cin >> date;
		if (date < 1 || date>5)
		{
			cout << "����������������룡" << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "��ѡ�����ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	int noon;

	while (true)
	{
		cin >> noon;
		if (noon!=1 && noon!=2)
		{
			cout << "����������������룡" << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "��ѡ�������"<<endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << ".ID:" << vCom[i].ID << " "
			<< "Capacity:" << vCom[i].Capacity << endl;
	}

	int room;
	
	while (true)
	{
		cin >> room;
		if (date < 1 || date>3)
		{
			cout << "����������������룡" << endl;
		}
		else
		{
			break;
		}
	}

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "noon:" << noon << " ";
	ofs<< "room:" << room << " ";
	ofs<< "StudentID:" << this->Name << " ";
	ofs<< "status:" <<1<< endl;

	cout << "ԤԼ�ɹ����ȴ���ˣ�" << endl;
	system("pause");
	system("cls");


}

void Student::printMyApply()
{
	OrderFile of;

	if (of.Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.Size; i++)
	{
		if (of.OrderData[i]["StudentID"] == this->ID)
		{
			cout << "ԤԼ���ڣ���" << of.OrderData[i]["date"];
			cout << " ʱ�Σ�"
				<< (of.OrderData[i]["noon"] == "1" ? "����" : "����");
			cout << " ������" << of.OrderData[i]["room"];
			
			cout << " ״̬��";
			// 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��

			if (of.OrderData[i]["status"] == "1")
			{
				cout << "�����"<<endl;
			}
			else if (of.OrderData[i]["status"] == "2")

			{
				cout << "��ԤԼ" << endl;
			}
			else if (of.OrderData[i]["status"] == "-1")
			{
				cout << "ԤԼʧ��" << endl;
			}
			else if (of.OrderData[i]["status"] == "0")
			{
				cout << "��ȡ��" << endl;
			}
		}
	}	
	
	system("pause");
	system("cls");
}

void Student::printAllApply() 
{
	OrderFile of;

	if (of.Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.Size; i++)
	{
		cout << i + 1 << ":" << endl;
		cout << "ԤԼ���ڣ���" << of.OrderData[i]["date"];
		cout << " ʱ�Σ�"
			<< (of.OrderData[i]["noon"] == "1" ? "����" : "����");
		cout << " ������" << of.OrderData[i]["room"];

		cout << " ״̬��";
		// 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��

		if (of.OrderData[i]["status"] == "1")
		{
				cout << "�����" << endl;
		}
		else if (of.OrderData[i]["status"] == "2")

			{
				cout << "��ԤԼ" << endl;
			}
			else if (of.OrderData[i]["status"] == "-1")
			{
				cout << "ԤԼʧ��" << endl;
			}
			else if (of.OrderData[i]["status"] == "0")
			{
				cout << "��ȡ��" << endl;
			}
	}
	system("pause");
			system("cls");
}

void Student::cancelApply()
{
	OrderFile of;

	if (of.Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int> v;
	int index = 1;
	cout << "\"�����\"��\"ԤԼ�ɹ�\"״̬��ԤԼ�������ȡ��" << endl;
	for (int i = 0; i < of.Size; i++)
	{
		if (of.OrderData[i]["StudentID"] == this->ID)
		{
			if (of.OrderData[i]["status"] == "1" || of.OrderData[i]["status"] == "2")
			{

				v.push_back(i);
				cout << index << ":" << endl;
				index++;
				cout << "ԤԼ���ڣ���" << of.OrderData[i]["date"];
				cout << " ʱ�Σ�"
					<< (of.OrderData[i]["noon"] == "1" ? "����" : "����");
				cout << " ������" << of.OrderData[i]["room"];

				cout << " ״̬��";
				// 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��

				if (of.OrderData[i]["status"] == "1")
				{
					cout << "�����" << endl;
				}
				else if (of.OrderData[i]["status"] == "2")
				{
					cout << "��ԤԼ" << endl;
				}
			}
		}
	}

	cout << "������Ҫȡ����ԤԼ��ţ�(0�����˳�)" << endl;
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		else if(choice<=v.size())
		{
			of.OrderData[v[choice - 1]]["status"] = "0";
			of.updateOrder();
			cout << "ȡ��ԤԼ�ɹ�" << endl;
			break;
		}
		else
		{
			cout << "�����������������룺" << endl;
		}
	}

	system("pause");
	system("cls");
	return;
}