#pragma once

#include <string>

struct mine {
    std::string SN;
    std::string name;
    std::string program;
    int credit;
    std::string status;
    int gwa;
    std::string honors;
};

extern int num;
extern int ctr;
//
void addnew(mine student[], int &num);
void report(mine student[], int &num);
void menu(mine student[]);
void modify(mine student[], int &num);
