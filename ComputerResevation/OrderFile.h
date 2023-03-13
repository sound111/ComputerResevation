#pragma once
#include<iostream>
#include<map>
#include"GlobalFile.h"
#include<string>
using namespace std;

class OrderFile
{
public:

	OrderFile();

	void updateOrder();

	map<int, map<string, string>> OrderData;
	
	int Size;
};