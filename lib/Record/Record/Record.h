#pragma once
//Record.h
#include <string>
#include <iostream> 
#include <iomanip>
#include <cmath>
using std::pow;
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;
using std::setw;
using std::right;
using std::string;

class Record
{
public:

	void displaymainmenu();
	void initialize();
	void resetarray();
	void create();
	void showrecord();
	void submenu();
	void searchname();
	void searchemail();
	void searchphoneno();
private:
	void setname(string);
	void setemail(string);
	void setphoneno(int);
	void getname(int);
	void getemail(int);
	void getphoneno(int);
};
