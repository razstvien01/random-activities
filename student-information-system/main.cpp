#include <iostream>

#include "file_functions.h"
#include "student.h"

using namespace std;

int main(int argc, char** argv) {
    mine student[30];

	loadFromFile(student);
   
	return 0;
}

