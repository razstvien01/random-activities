// functions.cpp

#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

int num = 9;
int ctr = 0;

mine deleted_student[30];

void menu(mine student[])
{
	system("cls");
    char choice;
    cout << "MENU" << endl;
    cout << "Select your operation" << endl;
    cout << "Add new Student [A]: " << endl;
    cout << "Delete Student [B]: " << endl;
    cout << "Report [C]: " << endl;
    cout << "EXIT [D]: "<<endl;
    
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
      	deletes(deleted_student, student, num, ctr);
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

//ADD NEW STUDENTS
void addnew(mine student[], int &num)
{
    char choice = 'a';
    
    while (choice == 'a' || choice == 'A')
    {
        num++;
        cin.ignore();
        cout << "Enter SN: ";
        getline(cin, student[num].SN);

        cout << "Enter Name: ";
        getline(cin, student[num].name);

        cout << "Enter Program: ";
        cin >> student[num].program;
        
        do
        {
		cout << "Enter Credit Units: ";
        cin >> student[num].credit;
  		  
		}	while(student[num].credit > 400 || student[num].credit < 0);
        
	//get status
	for(int i = 0; i < num; i++)
	{
		if(student[num].credit >= 0 && student[num].credit <= 100 )
		{
			student[num].status = "Freshmen";
		}
		
		else if(student[num].credit >= 101 && student[num].credit <= 200 )
		{
			student[num].status = "Sophomore";
		}
		
		else if(student[num].credit >= 201 && student[num].credit <= 300 )
		{
			student[num].status = "Junior";
		}
		
		else if(student[num].credit >= 300 && student[num].credit <= 350 )
		{
			student[num].status = "Senior";
		}
		
		else if(student[num].credit >= 351 && student[num].credit <= 399 )
		{
			student[num].status = "Graduating";
		}
		
		else if(student[num].credit = 400 )
		{
			student[num].status = "Graduates";
		}
		
	}
	
        cout << "Enter GWA: ";
        cin >> student[num].gwa;
        
        for(int i = 0; i < num; i++)
        {
        	if(student[num].status == "Graduates" || student[num].status == "Graduating" )
        	{
        			if(student[num].gwa >= 96 && student[num].gwa >= 100  )
        			
        	      {
        		      student[num].honors = "Summa Cum Laude";
			      }
			      
			      else if(student[num].gwa >= 93 && student[num].gwa >= 95  )
        	      {
        		      student[num].honors = "Magna Cum Laude";
			      }
			      
			      else if(student[num].gwa >= 90 && student[num].gwa >= 92  )
        	      {
        		      student[num].honors = "Cum Laude";
			      }
			      
			      else
			      {
			      	student[num].honors = " ";
					}
			  }
			  
			  if(student[num].status == "Freshmen" || student[num].status == "Sophomore" || student[num].status == "Junior" || student[num].status == "Senior"   )
        	{
        			if(student[num].gwa >= 96 && student[num].gwa >= 100  )
        			
        	      {
        		      student[num].honors = "First Honor";
			      }
			      
			      else if(student[num].gwa >= 93 && student[num].gwa >= 95  )
        	      {
        		      student[num].honors = "Second Honor";
			      }
			      
			      else if(student[num].gwa >= 90 && student[num].gwa >= 92  )
        	      {
        		      student[num].honors = "Third Honor";
			      }
			      
			      else
			      {
			      	student[num].honors = " ";
					}
			  }
        
		  }

        cout << "Again?[A]";
        cin >> choice;
    }
    
   char back;
	cout << "back? [Y]: ";
	cin >> back;
	if(back == 'y' || back == 'Y')
	
	{
		menu(student);
	}
	
	else
	{
		exit(0);
	}
}

void deletes(mine deleted_student[], mine student[], int &num, int &dels) {
    int del;

    cout << "List of Students:" << endl;
    for (int i = 0; i <= num; i++) 
	{
        cout << i << ". " << student[i].name << endl;
    }

    cout << "Delete student. Choose a number: ";
    cin >> del;

    if (del >= 0 && del <= num) {
        deleted_student[dels] = student[del];

        for (int i = del; i < num; i++) 
		{
            student[i] = student[i + 1];
        }

        dels++;
        num--;

        cout << "Student deleted successfully." << endl;
    } else 
    
	{
        cout << "INVALID NUMBER." << endl;
    }

    // Display deleted student/s
    cout << fixed << setprecision(1);
    cout << left;
    cout << setw(15) << "SN" << setw(20) << "Name" << setw(11) << "Program" << setw(15) << "Credit Units" << setw(13) << "Status" << setw(20) << "GWA" <<setw(15)<< "Honors" << endl;
    cout << "=====================================================================================================" << endl;

    for (int i = 0; i < dels; i++) 
	{
        cout << left;
        cout << setw(15) << deleted_student[i].SN << setw(20) << deleted_student[i].name << setw(11) << deleted_student[i].program << setw(15) << deleted_student[i].credit << setw(13) << deleted_student[i].status << setw(20) << deleted_student[i].gwa <<setw(15)<<deleted_student[i].honors << endl;
    }

    char back;
    cout << "Back? [Y]: ";
    cin >> back;
    if (back == 'y' || back == 'Y') 
	{
        menu(student);
    } else 
    
	{
        exit(0);
    }
}



void report(mine student[], int &num)
{
	char choice;
	cout << "Show: " << endl << endl;
	cout << "[A] Freshmen" << endl;
	cout << "[B] Sophomore" << endl;
	cout << "[C] Junior" << endl;
	cout << "[D] Senior" << endl;
	cout << "[E] Graduating" << endl;
	cout << "[F] Graduates" << endl;
	cout << "[G] ALL" << endl;
	
	do
	{
	try
	{
		cout << "CHOICE: ";
	   cin >> choice;
	   choice = toupper(choice);
	   if(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E' && choice != 'F' && choice != 'G')
	   
	   {
	   	throw choice;
		}
	   
	}
	catch(...)
	
	{
		cout<<"INVALID. TRY AGAIN!"<<endl;
	}
	
}while(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E' && choice != 'F' && choice != 'G');
	
	cout << fixed << setprecision(1);
	cout << left;
	cout << setw(15) << "SN" << setw(20) << "Name" << setw(11) << "Program" << setw(15) << "Credit Units" << setw(13) << "Status" << setw(20) << "GWA" <<setw(15)<< "Honors" << endl;
	cout << "=====================================================================================================" << endl;
	
	if(choice == 'A')
	{
		for(int i = 0; i <= num; i++)
	   {
		   if(student[i].status == "Freshmen")
		   {
			   
               cout << left;
               cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa <<setw(15)<< student[i].honors << endl;
            }
	  	}
   }
   
   if(choice == 'B')
	{
		for(int i = 0; i <= num; i++)
	   {
		   if(student[i].status == "Sophomore")
		   {
			   
               cout << left;
               cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa << setw(15)<< student[i].honors << endl;
            }
	  	}
   }
   
   if(choice == 'C')
	{
		for(int i = 0; i <= num; i++)
	   {
		   if(student[i].status == "Junior")
		   {
			   
               cout << left;
               cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa <<setw(15)<< student[i].honors << endl;
            }
	  	}
   }
   
   if(choice == 'D')
	{
		for(int i = 0; i <= num; i++)
	   {
		   if(student[i].status == "Senior")
		   {
			   
               cout << left;
               cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa <<setw(15)<< student[i].honors << endl;
            }
	  	}
   }
   
   if(choice == 'E')
	{
		for(int i = 0; i <= num; i++)
	   {
		   if(student[i].status == "Graduating")
		   {
			   
               cout << left;
               cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa <<setw(15)<< student[i].honors << endl;
            }
	  	}
   }
   
   if(choice == 'F')
	{
		for(int i = 0; i <= num; i++)
	   {
		   if(student[i].status == "Graduate")
		   {
			   
               cout << left;
               cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa <<setw(15)<< student[i].honors << endl;
            }
	  	}
   }
   
   if(choice == 'G')
	{
		for(int i = 0; i <= num; i++)
	   {			   
         cout << left;
               cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa <<setw(15)<< student[i].honors << endl; 
	  	}
   }
	
	cout << endl;
	
	char back;
	cout << "back? [Y]: ";
	cin >> back;
	if(back == 'y' || back == 'Y')
	
	{
		menu(student);
	}
	
	else
	{
		exit(0);
	}
}

