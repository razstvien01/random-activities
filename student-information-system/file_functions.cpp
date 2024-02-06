#include "file_functions.h"
#include <fstream>
#include <iostream>

using namespace std;

// Function to save data to a text file
void saveToFile(mine student[]) {
    ofstream outputFile("student_data.txt");

    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    // Save data to the file
    for (int i = 1; i <= num; ++i) {
        outputFile << student[i].SN << " "
                    << student[i].name << " "
                    << student[i].program << " "
                    << student[i].gwa << " "
                    << student[i].honors << " "
                    << student[i].status << " "
                    << student[i].credit << endl;
    }

    outputFile.close();
}

// Function to load data from a text file
void loadFromFile(mine student[]) {
    ifstream inputFile("student_data.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    int i = 0; // Start index for array
    while (inputFile >> student[i].SN >> student[i].name >> student[i].program
                    >> student[i].gwa >> student[i].honors >> student[i].status
                    >> student[i].credit) {
        i++;
    }

    inputFile.close();
    num = i - 1; // Update the global variable 'num' with the actual number of students
    
    menu(student);
}
