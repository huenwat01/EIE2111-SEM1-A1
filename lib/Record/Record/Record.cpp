#include <iostream>
#include <iostream> 
#include<iomanip>
#include<cmath>
#include "Record.h"
#include <regex>

using std::pow;
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;
using std::setw;
using std::right;
using std::string;
using std::regex_match;
using std::regex;
using std::isdigit;

//string name[100] = { "Lawrence Cheung", "Helen Wong", "Simon Sui", "Mary Ho" };
//string email[100] = { "encc2eie.polyu.edu.hk", "helenwong@yahoo,com.hk", "ss123@gmail.com", "ho.mary10@netvigator.com" };
string name[100];
string email[100];
int phoneno[100] = { 27666131,94665888,64441234,21111112 };

int noofrecord;//no of record
string name1;
string email1;
int phoneno1;
int spn;//save phone no
int d=0;//8-digit?

int n1 = 4;
int e1 = 4;
int p1 = 4;

string sn;//search name
string se;//search email
int sp;// search phone no

int tof = 0;//true of false
int ci = 0;// check integer or not

int useless = 1;
int cp;//check phone no


void Record::displaymainmenu()
{
	cout << "***********Main Menu*************" << endl;
	cout << "1. Initialize the address book" << endl;
	cout << "2. Create person contact information" << endl;
	cout << "3. Lookup person contact information" << endl;
	cout << "4. Lookup all person contact information" << endl;
	cout << "5. Quit" << endl;
	cout << endl;
	cout << "Please enter your choice <1, 2, 3, 4 or 5 to quit>:" << endl;
}
void Record::resetarray()
{
	for(int i=0;i<100;i++)
	{
		name[i] = "nnn";
		email[i] = "eee";
		phoneno[i] = 00000000;
	}
}
void Record::initialize()
{
	/*for (int i = 0; i<100; i++)
	{
		if(phoneno[i]==00000000)
		{
			break;
		}
		cout << "Name is:"<<name[i] << endl;
		cout <<"Email is:"<< email[i] << endl;
		cout <<"Telephone number is:"<<phoneno[i] << endl;
	}
	cout << "Initialization is completed"<<endl;
	cout << endl;*/
	for (int i = 0; i < 1; i++)
	{
		name[i] = "Lawrence Cheung";
		email[i] = "enccl@eie.polyu.edu.hk";
		phoneno[i] = 27666131;
		name[i+1] = "Helen Wong";
		email[i+1] = "helenwong@yahoo.com.hk";
		phoneno[i+1] = 94665888;
		name[i+2] = "Simon Sui";
		email[i+2] = "ss123@gmail.com";
		phoneno[i+2] = 64441234;
		name[i+3] = "Mary Ho";
		email[i+3] = "ho.mary10@netvigator.com";
		phoneno[i+3] = 21111112;
		cout << "Name is:" << name[i] << endl;
		cout << "Email is:" << email[i] << endl;
		cout << "Telephone number is:" << phoneno[i] << endl;
		cout << "Name is:" << name[i+1] << endl;
		cout << "Email is:" << email[i+1] << endl;
		cout << "Telephone number is:" << phoneno[i+1] << endl;
		cout << "Name is:" << name[i+2] << endl;
		cout << "Email is:" << email[i+2] << endl;
		cout << "Telephone number is:" << phoneno[i+2] << endl;
		cout << "Name is:" << name[i+3] << endl;
		cout << "Email is:" << email[i+3] << endl;
		cout << "Telephone number is:" << phoneno[i+3] << endl;
	}
	for (int i = 4; i < 100; i++)
	{
		name[i] = "nnn";
		email[i] = "eee";
		phoneno[i] = 00000000;
	}
	cout << "Initialization is completed" << endl;
	cout << endl;
}
void Record::create()
{
	noofrecord = 0;
	cout << "Please enter the total number of records to be created :";
	cin >> noofrecord;
	ci = noofrecord % 1;
	if(noofrecord>10 or noofrecord<0 or ci>0 or noofrecord==0)
	{
		cout << "The input is invalid. It must be an integer not greater than 10." << endl;
		create();
	}
	for (int i=0;i<noofrecord;i++)
	{
		phoneno1=0;
		cout << "Full name: ";
		getline(cin, name1);
		getline(cin, name1);
		regex n("[a-zA-Z0-9\\s]*");
		if(regex_match(name1, n))
		{
			useless++;
		}
		else
		{
			cout << "For a full name, only space characters and letters are allowed" << endl;
			create();
		}
		cout << "Email address: ";
		getline(cin, email1);
		regex e("[a-zA-Z0-9]*@[a-zA-Z0-9]*");
		if (regex_match(email1, e))
		{
			useless++;
		}
		else 
		{
			cout << "For an email address, one character '@' must be found. Moreover, there must be some character before and after the character '@' " << endl;
			create();
		}
		cout << "Telephone number :";
		cin>>phoneno1;
		spn = phoneno1;

		for(;spn>0;)
		{
			spn = spn / 10;
			d++;
		}	
		cp = phoneno1 / 10000000;
		if(cp==0 or d!=8 or phoneno1==0)
		{
			cout << "For a telephone number, it must be an 8-digit integer and the first digit cannot be zero" << endl;
			create();
		}
		cout << endl;

		setname(name1);
		setemail(email1);
		setphoneno(phoneno1);
	}
	cout << "All new records are saved!" << endl;
	cout << endl;
}
void Record::setname(string name1)
{
	name[n1] = name1;
	n1++;
}
void Record::setemail(string email1)
{
	email[e1] = email1;
	e1++;
}
void Record::setphoneno(int phoneno1)
{
	phoneno[p1] = phoneno1;
	p1++;
}

void Record::showrecord()
{
	for(int i=0;i<100;i++)
	{
		if(phoneno[i]==00000000)
		{
			break;
		}
		getname(i);
		getemail(i);
		getphoneno(i);
	}
	cout << endl;
	cout << "All record have been shown";
	cout << endl;
}
void Record::getname(int i)
{
	cout << "Name :" << name[i]<<endl;
}
void Record::getemail(int i)
{
	cout << "Email :" << email[i] << endl;
}
void Record::getphoneno(int i)
{
	cout << "Phone number :" << phoneno[i] << endl;
}
void Record::submenu()
{
	cout << "***********SUB-MENU*************" << endl;
	cout << "a. Search record by name" << endl;
	cout << "b. Search record by email address" << endl;
	cout << "c. Search record by telephone number" << endl;
	cout << "d. Return to main menu" << endl;
	cout << endl;
	cout << "Please enter your chioce <a, b, c or d to return " << endl;
}
void Record::searchname()
{
	cout << "Please enter a name to search :";
	getline(cin, sn);
	getline(cin, sn);
	for(int i=0;i<100;i++)
	{
		if(name[i]==sn)
		{
			cout << "Name :" << name[i] << endl;
			cout << "Email address :" << email[i] << endl;
			cout << "Telephone number is :" << phoneno[i] << endl;
			cout << endl;
			tof = 1;
			break;
		}
		
	}
	if (tof == 0)
	{
		cout << "Sorry, no record is found" << endl;
	}
}
void Record::searchemail()
{
	cout << "Please enter a email to search :";
	getline(cin, se);
	getline(cin, se);
	for (int i = 0; i < 100; i++)
	{
		if (email[i] == se)
		{
			cout << "Name :" << name[i] << endl;
			cout << "Email address :" << email[i] << endl;
			cout << "Telephone number is :" << phoneno[i] << endl;
			cout << endl;
			tof = 1;
			break;
		}
		
	}
	if (tof == 0)
	{
		cout << "Sorry, no record is found" << endl;
	}
}
void Record::searchphoneno()
{
	cout << "Please enter a telephone number to search :";
	cin >> sp;
	for (int i = 0; i < 100; i++)
	{
		if (phoneno[i] == sp)
		{
			cout << "Name :" << name[i] << endl;
			cout << "Email address :" << email[i] << endl;
			cout << "Telephone number is :" << phoneno[i] << endl;
			cout << endl;
			tof = 1;
			break;
		}
		
	}
	if (tof == 0)
	{
		cout << "Sorry, no record is found" << endl;
	}
}