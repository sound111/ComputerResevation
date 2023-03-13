#pragma once
#include"Person.h"
#include"Student.h"
#include"Manager.h"
#include"Teacher.h"
#include"ComputerRoom.h"
#include<string>
#include<vector>
using namespace std;

class Manager :public Person
{
public:
	Manager();

	Manager(string name, string pwd);

	~Manager();

	void addPerson();

	void showPerson();

	bool checkRepeat(string id, int type);

	void showComputer();

	void cleanFile();

	void initVector();

	virtual void Menu();

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};