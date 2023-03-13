#pragma once
#include"Person.h"
#include"ComputerRoom.h"
#include<vector>

class Student:public Person
{
public:
	Student();
	
	Student(string id, string name, string pwd);

	~Student();

	virtual void Menu() ;

	void apply();

	void printMyApply();

	void printAllApply();

	void cancelApply();

	string ID;

	vector<ComputerRoom> vCom;
};