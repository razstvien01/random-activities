// menu.h

#include <iostream>
#include <fstream>
#include <iomanip>
#include "student.h"
#include "addnew.h"
#include "modify.h"
#include "report.h"
//#include "menu.h"  // Include menu.h

using namespace std;



using namespace std;

int num = 9;
int ctr = 0;

void menu(mine student[])
{
	system("cls");
    char choice;
    cout << "MAIN MENU" << endl;
    cout << "[A] Add record" << endl;
    cout << "[B] Modify record" << endl;
    cout << "[C] Display record" << endl;
    cout << "[D] Exit" << endl;
    
    do	{	
    try
    {
    	cin >> choice;
      choice = toupper(choice);
      if(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D')
      {
		throw choice;
		}
	 }
	 
	 catch(...)
	 
	 {
		cout<<"Invalid. Try Again."<<endl;
	 }
	 
	 }	while(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D');
	 
    
    switch (choice)
    {
      case 'A':
	  {
      		addnew(student, num);
			break;	}
		
		case 'B':{
			modify(student, num);
//      	deletes(deleted_student, student, num, ctr);
			break;
		}
		
		case 'C':{
      		report(student, num);
			break;
		}
		
		case 'D':{
      	exit(0);
			
		}
    }
}

