#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include"GlobalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
using namespace std;

class ComputerReserver
{
public:
	ComputerReserver();

	void showMenu();

	void exitSystem();

	~ComputerReserver();


};