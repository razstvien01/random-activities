// report.h
#pragma once
#include "student.h"

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

