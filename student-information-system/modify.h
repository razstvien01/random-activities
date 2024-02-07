//#include "student.h"


// Function to display and modify existing students
void modify(mine student[], int &num) {
    // Display all students
    cout << "List of Students:" << endl;
    cout << left << setw(15) << "SN" << setw(20) << "Name" << setw(11) << "Program"
         << setw(15) << "Credit Units" << setw(13) << "Status" << setw(20) << "GWA"
         << setw(15) << "Honors" << endl;
    cout << "=====================================================================================================" << endl;

    for (int k = 1; k <= num; ++k) {
        cout << left << setw(15) << student[k].SN << setw(20) << student[k].name
             << setw(11) << student[k].program << setw(15) << student[k].credit
             << setw(13) << student[k].status << setw(20) << student[k].gwa
             << setw(15) << student[k].honors << endl;
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
                student[i].honors = "Summa_Cum_Laude";
            } else if ((student[i].status == "Graduates" || student[i].status == "Graduating") &&
                       student[i].gwa >= 93 && student[i].gwa <= 95) {
                student[i].honors = "Magna_Cum_Laude";
            } else if ((student[i].status == "Graduates" || student[i].status == "Graduating") &&
                       student[i].gwa >= 90 && student[i].gwa <= 92) {
                student[i].honors = "Cum_Laude";
            } else if (student[i].gwa >= 96 && student[i].gwa <= 100) {
                student[i].honors = "First_Honor";
            } else if (student[i].gwa >= 93 && student[i].gwa <= 95) {
                student[i].honors = "Second_Honor";
            } else if (student[i].gwa >= 90 && student[i].gwa <= 92) {
                student[i].honors = "Third_Honor";
            } else {
                student[i].honors = "No_Honor";
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
            
            // Write to output.txt
        	writeToOutputFile(student, num);

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



