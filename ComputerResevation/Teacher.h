#pragma once
#include"Person.h"

class Teacher :public Person
{
public:
	Teacher();

	Teacher(string id, string name, string pwd);

	~Teacher();

	virtual void Menu();

	string ID;

	void CheckAllApply();

	void AuditApply();
};