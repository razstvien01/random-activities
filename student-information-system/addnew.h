// addnew.h
#include <iostream>
#include <fstream>
#include <iomanip>
//#include "student.h"
#include "output.h"

using namespace std;

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
            student[num].honors = "Summa_Cum_Laude";
        } else if ((student[num].status == "Graduates" || student[num].status == "Graduating") &&
                   student[num].gwa >= 93 && student[num].gwa <= 95) {
            student[num].honors = "Magna_Cum_Laude";
        } else if ((student[num].status == "Graduates" || student[num].status == "Graduating") &&
                   student[num].gwa >= 90 && student[num].gwa <= 92) {
            student[num].honors = "Cum_Laude";
        } else if (student[num].gwa >= 96 && student[num].gwa <= 100) {
            student[num].honors = "First_Honor";
        } else if (student[num].gwa >= 93 && student[num].gwa <= 95) {
            student[num].honors = "Second_Honor";
        } else if (student[num].gwa >= 90 && student[num].gwa <= 92) {
            student[num].honors = "Third_Honor";
        } else {
            student[num].honors = "No_Honor";
        }

        // Open the file in append mode and write the new student information
        ofstream outputFile("student_data.txt", ios::app);
        if (outputFile.is_open()) {
            // Adjust the spacing for each field
            outputFile << student[num].SN << " " << student[num].name << " " << student[num].program << " "
                       << student[num].gwa << " " << student[num].status << " " << student[num].honors
                       << " " << student[num].credit << "\n";
            outputFile.close();
        } else {
            cerr << "Error opening file for writing!" << endl;
        }
        
        // Write to output.txt
        writeToOutputFile(student, num);

        cout << "[A] Again?";
        cin >> choice;

        // Print a newline for the next data entry
        if (choice == 'a' || choice == 'A') {
            cout << endl;
        }
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


