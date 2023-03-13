#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	string Name;
	string Password;

	virtual void Menu() = 0;//´¿Ðéº¯Êý
};