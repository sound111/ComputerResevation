#include"Teacher.h"
#include"OrderFile.h"
#include<vector>

Teacher::Teacher()
{

}

Teacher::Teacher(string id,string name,string pwd)
{
	this->ID = id;
	this->Name = name;
	this->Password = pwd;
}

Teacher::~Teacher()
{

}

void Teacher::Menu()
{
	cout << "����ԤԼϵͳ" << endl;
	cout << "��ʦ���幦��" << endl;
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ" << endl;
	cout << "3.�˳���¼" << endl;
}

void Teacher::CheckAllApply()
{
	OrderFile of;

	for (int i = 0; i < of.Size; i++)
	{
		cout << i + 1 << ":" << endl;

		cout << "ԤԼ���ڣ���" << of.OrderData[i]["date"] << " ";
		cout << "ʱ�Σ�" << (of.OrderData[i]["noon"] == "1" ? "����" : "����") << " ";
		cout << "������" << of.OrderData[i]["room"] << " ";
		cout << "ѧ��������" << of.OrderData[i]["name"] << " ";
		cout << "ѧ��ID��" << of.OrderData[i]["StudentID"] << " ";
		cout << "״̬��";

		if (of.OrderData[i]["status"] == "1")
		{
			cout << "�����" << endl;
		}
		else if (of.OrderData[i]["status"] == "2")
		{
			cout << "��ԤԼ" << endl;
		}
		else if (of.OrderData[i]["status"] == "0")
		{
			cout << "��ȡ��" << endl;
		}
		else if (of.OrderData[i]["status"] == "-1")
		{
			cout << "ԤԼʧ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

void Teacher::AuditApply()
{
	OrderFile of;

	vector<int> v;
	cout << "����˵�ԤԼΪ��" << endl;
	for (int i = 0; i < of.Size; i++)
	{
		if (of.OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << v.size() << ":" << endl;
			cout << "ԤԼ���ڣ���" << of.OrderData[i]["date"] << " ";
			cout << "ʱ�Σ�" << (of.OrderData[i]["noon"] == "1" ? "����" : "����") << " ";
			cout << "������" << of.OrderData[i]["room"] << " ";
			cout << "ѧ��������" << of.OrderData[i]["name"] << " ";
			cout << "ѧ��ID��" << of.OrderData[i]["StudentID"] << endl;
		}
	}

	cout << "������Ҫ��˵�ԤԼ��ţ�������0�����˳���" << endl;

	int choice;

	while (true)
	{
		cin >> choice;

		if (choice == 0)
		{
			return;
		}
		else if (choice >= 1 && choice <= of.Size)
		{
			cout << "������Ҫִ�еĲ�����" << endl;
			cout << "1.��˳ɹ�" << endl;
			cout << "2.���ʧ��" << endl;

			int select;

			while (true)
			{
				cin >> select;

				if (select == 1)
				{
					of.OrderData[v[choice - 1]]["status"] = "2";
					of.updateOrder();
					break;
				}
				else if (select == 2)
				{
					of.OrderData[v[choice - 1]]["status"] = "-1";
					of.updateOrder();
					break;
				}
				else
				{
					cout << "����������������룡" << endl;
				}
			}
			break;
		}
	}
	
	system("pause");
	system("cls");
}
