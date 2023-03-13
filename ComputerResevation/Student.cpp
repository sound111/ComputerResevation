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
	cout << "机房预约系统" << endl;
	cout << "学生具体功能" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看自身的预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "5.退出登录" << endl;
}

void Student::apply()
{
	cout << "申请预约" << endl;

	cout << "请选择预约时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date;

	while (true)
	{
		cin >> date;
		if (date < 1 || date>5)
		{
			cout << "输入错误，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "请选择具体时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;

	int noon;

	while (true)
	{
		cin >> noon;
		if (noon!=1 && noon!=2)
		{
			cout << "输入错误，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "请选择机房："<<endl;
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
			cout << "输入错误，请重新输入！" << endl;
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

	cout << "预约成功，等待审核！" << endl;
	system("pause");
	system("cls");


}

void Student::printMyApply()
{
	OrderFile of;

	if (of.Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.Size; i++)
	{
		if (of.OrderData[i]["StudentID"] == this->ID)
		{
			cout << "预约日期：周" << of.OrderData[i]["date"];
			cout << " 时段："
				<< (of.OrderData[i]["noon"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.OrderData[i]["room"];
			
			cout << " 状态：";
			// 0 取消的预约   1 审核中   2 已预约 -1 预约失败

			if (of.OrderData[i]["status"] == "1")
			{
				cout << "审核中"<<endl;
			}
			else if (of.OrderData[i]["status"] == "2")

			{
				cout << "已预约" << endl;
			}
			else if (of.OrderData[i]["status"] == "-1")
			{
				cout << "预约失败" << endl;
			}
			else if (of.OrderData[i]["status"] == "0")
			{
				cout << "已取消" << endl;
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.Size; i++)
	{
		cout << i + 1 << ":" << endl;
		cout << "预约日期：周" << of.OrderData[i]["date"];
		cout << " 时段："
			<< (of.OrderData[i]["noon"] == "1" ? "上午" : "下午");
		cout << " 机房：" << of.OrderData[i]["room"];

		cout << " 状态：";
		// 0 取消的预约   1 审核中   2 已预约 -1 预约失败

		if (of.OrderData[i]["status"] == "1")
		{
				cout << "审核中" << endl;
		}
		else if (of.OrderData[i]["status"] == "2")

			{
				cout << "已预约" << endl;
			}
			else if (of.OrderData[i]["status"] == "-1")
			{
				cout << "预约失败" << endl;
			}
			else if (of.OrderData[i]["status"] == "0")
			{
				cout << "已取消" << endl;
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int> v;
	int index = 1;
	cout << "\"审核中\"和\"预约成功\"状态的预约申请可以取消" << endl;
	for (int i = 0; i < of.Size; i++)
	{
		if (of.OrderData[i]["StudentID"] == this->ID)
		{
			if (of.OrderData[i]["status"] == "1" || of.OrderData[i]["status"] == "2")
			{

				v.push_back(i);
				cout << index << ":" << endl;
				index++;
				cout << "预约日期：周" << of.OrderData[i]["date"];
				cout << " 时段："
					<< (of.OrderData[i]["noon"] == "1" ? "上午" : "下午");
				cout << " 机房：" << of.OrderData[i]["room"];

				cout << " 状态：";
				// 0 取消的预约   1 审核中   2 已预约 -1 预约失败

				if (of.OrderData[i]["status"] == "1")
				{
					cout << "审核中" << endl;
				}
				else if (of.OrderData[i]["status"] == "2")
				{
					cout << "已预约" << endl;
				}
			}
		}
	}

	cout << "请输入要取消的预约序号：(0代表退出)" << endl;
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
			cout << "取消预约成功" << endl;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入：" << endl;
		}
	}

	system("pause");
	system("cls");
	return;
}