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
	cout << "机房预约系统" << endl;
	cout << "教师具体功能" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "3.退出登录" << endl;
}

void Teacher::CheckAllApply()
{
	OrderFile of;

	for (int i = 0; i < of.Size; i++)
	{
		cout << i + 1 << ":" << endl;

		cout << "预约日期：周" << of.OrderData[i]["date"] << " ";
		cout << "时段：" << (of.OrderData[i]["noon"] == "1" ? "上午" : "下午") << " ";
		cout << "机房：" << of.OrderData[i]["room"] << " ";
		cout << "学生姓名：" << of.OrderData[i]["name"] << " ";
		cout << "学生ID：" << of.OrderData[i]["StudentID"] << " ";
		cout << "状态：";

		if (of.OrderData[i]["status"] == "1")
		{
			cout << "审核中" << endl;
		}
		else if (of.OrderData[i]["status"] == "2")
		{
			cout << "已预约" << endl;
		}
		else if (of.OrderData[i]["status"] == "0")
		{
			cout << "已取消" << endl;
		}
		else if (of.OrderData[i]["status"] == "-1")
		{
			cout << "预约失败" << endl;
		}
	}

	system("pause");
	system("cls");
}

void Teacher::AuditApply()
{
	OrderFile of;

	vector<int> v;
	cout << "待审核的预约为：" << endl;
	for (int i = 0; i < of.Size; i++)
	{
		if (of.OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << v.size() << ":" << endl;
			cout << "预约日期：周" << of.OrderData[i]["date"] << " ";
			cout << "时段：" << (of.OrderData[i]["noon"] == "1" ? "上午" : "下午") << " ";
			cout << "机房：" << of.OrderData[i]["room"] << " ";
			cout << "学生姓名：" << of.OrderData[i]["name"] << " ";
			cout << "学生ID：" << of.OrderData[i]["StudentID"] << endl;
		}
	}

	cout << "请输入要审核的预约序号：（输入0代表退出）" << endl;

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
			cout << "请输入要执行的操作：" << endl;
			cout << "1.审核成功" << endl;
			cout << "2.审核失败" << endl;

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
					cout << "输入错误，请重新输入！" << endl;
				}
			}
			break;
		}
	}
	
	system("pause");
	system("cls");
}
