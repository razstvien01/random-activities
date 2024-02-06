#include "student.h"

#include <fstream>
#include <iostream>
#include "menu.h"
using namespace std;

void loadFromFile(mine student[]);

// Load data from file
void loadFromFile(mine student[]) {
    ifstream inputFile("student_data.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    int i = 1; // Start index for array
    while (inputFile >> student[i].SN >> student[i].name >> student[i].program
                    >> student[i].gwa >> student[i].honors >> student[i].status
                    >> student[i].credit) {
                    	cout<<"Student: "<<i<<endl;
        i++;
    }

    inputFile.close();
    num = i - 1; // Update the global variable 'num' with the actual number of students

    menu(student);
}

