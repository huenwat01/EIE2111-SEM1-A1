//Wat Wing Huen 21085591d
#include <string>
#include <iostream> 
#include <iomanip>

using std::pow;
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;
using std::setw;
using std::right;


#include "Record.h"
char number;//input a number 
int re = 0;//keep the programme run again
char choice;// sub-menu choice
int l = 0;
int main()
{
	Record Record1;
	Record1.resetarray();
	for(;re==0;)
	{
		Record1.displaymainmenu();
		//number == '0';
		cin >> number;	
		switch (number)
		{
		case '1':
			Record1.initialize();
			break;

		case '2':
			Record1.create();
			break;
			
		case '3':
			l = 0;
			for (; l == 0;)
			{
				Record1.submenu();
				cin >> choice;
				switch (choice)
				{
				case 'a':
					Record1.searchname();
					l = 1;
					break;
				case 'b':
					Record1.searchemail();
					l = 1;
					break;
				case 'c':
					Record1.searchphoneno();
					l = 1;
					break;
				case 'd':
					l = 1;
					break;
				default:
					cout << "Invalid input. Please enter again!" << endl;
				}
			}
			break;

		case '4':
			Record1.showrecord();
			break;

		case '5':
			cout << "Goodbye!";
			re = 1;
			break;

		default:
			cout << "Invalid input. Please enter again!" << endl;
			cout << endl;
			break;
		}
		/*if (number >5 or number <= 0)
		{
			cout << "Invalid input. Please enter again!" << endl;
			cout << endl;
			Record1.displaymainmenu();
		}*/
		/*if (number == 1)
		{
			Record1.resetarray();
			Record1.initialize();
		}*/
		/*if (number == 2)
		{
			Record1.create();
		}*/
		/*if (number == 3)
		{
			l = 0;
			for(;l==0;)
			{
				Record1.submenu();
				cin >> choice;
				switch (choice)
				{
				case 'a':
					Record1.searchname();
					l = 1;
					break;
				case 'b':
					Record1.searchemail();
					l = 1;
					break;
				case 'c':
					Record1.searchphoneno();
					l = 1;
					break;
				case 'd':
					l = 1;
					break;
				default:
					cout << "Invalid input. Please enter again!" << endl;
				}
			}
			
		}*/
		/*if (number == 4)
		{
			Record1.showrecord();
		}*/
		/*if (number == 5)
		{
			cout << "Goodbye!";
			re = 1;			
		}*/
	}

}