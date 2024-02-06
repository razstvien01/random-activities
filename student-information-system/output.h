// menu.h
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "student.h"

using namespace std;

// Function to write student data to output.txt
void writeToOutputFile(mine student[], int num) {
    // Open the file in write mode and write all student information to output.txt
    ofstream outputOutputFile("output.txt");
    if (outputOutputFile.is_open()) {
        outputOutputFile << left << setw(15) << "SN" << setw(20) << "Name"
                 	     << setw(11) << "Program" << setw(15) << "Credit Units"
                         << setw(13) << "Status" << setw(20) << "GWA" << setw(15) << "Honors" << "\n";
        outputOutputFile << "=====================================================================================================" << "\n";
        for (int i = 1; i <= num; ++i) {
            outputOutputFile << left << setw(15) << student[i].SN << setw(20) << student[i].name
                             << setw(11) << student[i].program << setw(15) << student[i].credit
                             << setw(13) << student[i].status << setw(20) << student[i].gwa
                             << setw(15) << student[i].honors << "\n";
        }
        outputOutputFile.close();
    } else {
        cerr << "Error opening file output.txt for writing!" << endl;
    }
}

