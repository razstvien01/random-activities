// functions.cpp

#include <iostream>
#include <fstream>
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

// Function to add new students and save to file
void addnew(mine student[], int &num) {
    char choice = 'a';

    while (choice == 'a' || choice == 'A') {
        num++;
        cin.ignore();
        cout << "Enter SN: ";
        getline(cin, student[num].SN);

        cout << "Enter Name: ";
        getline(cin, student[num].name);

        cout << "Enter Program: ";
        cin >> student[num].program;

        do {
            cout << "Enter Credit Units: ";
            cin >> student[num].credit;

        } while (student[num].credit > 400 || student[num].credit < 0);

        // Calculate status
        if (student[num].credit >= 0 && student[num].credit <= 100) {
            student[num].status = "Freshmen";
        } else if (student[num].credit >= 101 && student[num].credit <= 200) {
            student[num].status = "Sophomore";
        } else if (student[num].credit >= 201 && student[num].credit <= 300) {
            student[num].status = "Junior";
        } else if (student[num].credit >= 301 && student[num].credit <= 350) {
            student[num].status = "Senior";
        } else if (student[num].credit >= 351 && student[num].credit <= 399) {
            student[num].status = "Graduating";
        } else if (student[num].credit == 400) {
            student[num].status = "Graduates";
        }

        cout << "Enter GWA: ";
        cin >> student[num].gwa;

        // Calculate honors
        if ((student[num].status == "Graduates" || student[num].status == "Graduating") &&
            student[num].gwa >= 96 && student[num].gwa <= 100) {
            student[num].honors = "Summa Cum Laude";
        } else if ((student[num].status == "Graduates" || student[num].status == "Graduating") &&
                   student[num].gwa >= 93 && student[num].gwa <= 95) {
            student[num].honors = "Magna Cum Laude";
        } else if ((student[num].status == "Graduates" || student[num].status == "Graduating") &&
                   student[num].gwa >= 90 && student[num].gwa <= 92) {
            student[num].honors = "Cum Laude";
        } else if (student[num].gwa >= 96 && student[num].gwa <= 100) {
            student[num].honors = "First Honor";
        } else if (student[num].gwa >= 93 && student[num].gwa <= 95) {
            student[num].honors = "Second Honor";
        } else if (student[num].gwa >= 90 && student[num].gwa <= 92) {
            student[num].honors = "Third Honor";
        } else {
            student[num].honors = " ";
        }

        // Open the file in append mode and write the new student information
        ofstream outputFile("student_data.txt", ios::app);
        if (outputFile.is_open()) {
            outputFile << student[num].SN << " " << student[num].name << " " << student[num].program << " "
                       << student[num].gwa << " " << student[num].honors << " " << student[num].status << " "
                       << student[num].credit << "\n";
            outputFile.close();
        } else {
            cerr << "Error opening file for writing!" << endl;
        }

        cout << "Again?[A]";
        cin >> choice;
    }

    char back;
    cout << "back? [Y]: ";
    cin >> back;
    if (back == 'y' || back == 'Y') {
        menu(student);
    } else {
        exit(0);
    }
}

// Function to display and modify existing students
void modify(mine student[], int &num) {
    // Display all students
    cout << "List of Students:" << endl;
    for (int k = 1; k <= num; ++k) {
        cout << "Student " << k << ": " << student[k].name << ", Program: " << student[k].program
             << ", GWA: " << student[k].gwa << ", Status: " << student[k].status << endl;
    }

    cout << "Enter the Student Number (SN) of the student you want to modify: ";
    string targetSN;
    cin.ignore();
    getline(cin, targetSN);

    bool found = false;
    for (int i = 1; i <= num; ++i) {
        if (student[i].SN == targetSN) {
            found = true;
            cout << "Enter new information for student with SN " << targetSN << ":" << endl;

            cout << "Enter Name: ";
            getline(cin, student[i].name);

            cout << "Enter Program: ";
            cin >> student[i].program;

            do {
                cout << "Enter Credit Units: ";
                cin >> student[i].credit;
            } while (student[i].credit > 400 || student[i].credit < 0);

            // Calculate status
            // (Assuming the status should be recalculated based on the new credit units)
            if (student[i].credit >= 0 && student[i].credit <= 100) {
                student[i].status = "Freshmen";
            } else if (student[i].credit >= 101 && student[i].credit <= 200) {
                student[i].status = "Sophomore";
            } else if (student[i].credit >= 201 && student[i].credit <= 300) {
                student[i].status = "Junior";
            } else if (student[i].credit >= 301 && student[i].credit <= 350) {
                student[i].status = "Senior";
            } else if (student[i].credit >= 351 && student[i].credit <= 399) {
                student[i].status = "Graduating";
            } else if (student[i].credit == 400) {
                student[i].status = "Graduates";
            }

            cout << "Enter GWA: ";
            cin >> student[i].gwa;

            // Calculate honors
            // (Assuming the honors should be recalculated based on the new GWA and status)
            if ((student[i].status == "Graduates" || student[i].status == "Graduating") &&
                student[i].gwa >= 96 && student[i].gwa <= 100) {
                student[i].honors = "Summa Cum Laude";
            } else if ((student[i].status == "Graduates" || student[i].status == "Graduating") &&
                       student[i].gwa >= 93 && student[i].gwa <= 95) {
                student[i].honors = "Magna Cum Laude";
            } else if ((student[i].status == "Graduates" || student[i].status == "Graduating") &&
                       student[i].gwa >= 90 && student[i].gwa <= 92) {
                student[i].honors = "Cum Laude";
            } else if (student[i].gwa >= 96 && student[i].gwa <= 100) {
                student[i].honors = "First Honor";
            } else if (student[i].gwa >= 93 && student[i].gwa <= 95) {
                student[i].honors = "Second Honor";
            } else if (student[i].gwa >= 90 && student[i].gwa <= 92) {
                student[i].honors = "Third Honor";
            } else {
                student[i].honors = " ";
            }

            // Update the modified student information in the file
            ofstream outputFile("student_data.txt");
            if (outputFile.is_open()) {
                for (int j = 1; j <= num; ++j) {
                    outputFile << student[j].SN << " " << student[j].name << " " << student[j].program << " "
                               << student[j].gwa << " " << student[j].honors << " " << student[j].status << " "
                               << student[j].credit << "\n";
                }
                outputFile.close();
            } else {
                cerr << "Error opening file for writing!" << endl;
            }

            cout << "Student with SN " << targetSN << " has been modified." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student with SN " << targetSN << " not found." << endl;
    }

    char back;
    cout << "Back to menu? [Y]: ";
    cin >> back;
    if (back == 'y' || back == 'Y') {
        menu(student);
    } else {
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


void report(mine student[], int &num) {
    char choice;
    cout << "Show: " << endl << endl;
    cout << "[A] All Freshmen" << endl;
    cout << "[B] All Graduating Students" << endl;
    cout << "[C] All Students with SN containing 2023" << endl;

    do {
        try {
            cout << "CHOICE: ";
            cin >> choice;
            choice = toupper(choice);
            if (choice != 'A' && choice != 'B' && choice != 'C') {
                throw choice;
            }
        } catch (...) {
            cout << "INVALID. TRY AGAIN!" << endl;
        }

    } while (choice != 'A' && choice != 'B' && choice != 'C');

    cout << fixed << setprecision(1);
    cout << left;
    cout << setw(15) << "SN" << setw(20) << "Name" << setw(11) << "Program" << setw(15) << "Credit Units" << setw(13)
         << "Status" << setw(20) << "GWA" << setw(15) << "Honors" << endl;
    cout << "====================================================================================================="
         << endl;

    if (choice == 'A') {
        for (int i = 1; i <= num; i++) {
            if (student[i].status == "Freshmen") {
                cout << left;
                cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program
                     << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa
                     << setw(15) << student[i].honors << endl;
            }
        }
    } else if (choice == 'B') {
        for (int i = 1; i <= num; i++) {
            if (student[i].status == "Graduating") {
                cout << left;
                cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program
                     << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa
                     << setw(15) << student[i].honors << endl;
            }
        }
    } else if (choice == 'C') {
        for (int i = 1; i <= num; i++) {
            if (student[i].SN.find("2023") != string::npos) {
                cout << left;
                cout << setw(15) << student[i].SN << setw(20) << student[i].name << setw(11) << student[i].program
                     << setw(15) << student[i].credit << setw(13) << student[i].status << setw(20) << student[i].gwa
                     << setw(15) << student[i].honors << endl;
            }
        }
    }

    cout << endl;

    char back;
    cout << "back? [Y]: ";
    cin >> back;
    if (back == 'y' || back == 'Y') {
        menu(student);
    } else {
        exit(0);
    }
}

