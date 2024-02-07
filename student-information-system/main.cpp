#include <iostream>

#include "file_functions.h"
//#include "student.h"

using namespace std;

/*
NOTE: MAKE SURE TO USE '_' as space
SAMPLE INPUT

Enter SN: 2023-02-099
Enter Name: Pedeo_Evanz
Enter Program: BSCPE
Enter Credit Units: 300
Enter GWA: 99
*/

/*
FILES:
 - main.cpp
 - file_functions.h - use to read and write student_data.txt
 - student.h
 - menu.h
 - addnew.h
 - modify.h
 - report.h
 - output.h - for output purposes (output.txt)
 - student_data.txt - use as a database in order to retrieve and save the data
*/

int main(int argc, char** argv) {
    mine student[30];

	loadFromFile(student);
   
	return 0;
}

