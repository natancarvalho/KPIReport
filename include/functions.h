//
// Created by natan on 21/09/22.
//
#ifndef DBCONNECT_FUNCTIONS_H
#define DBCONNECT_FUNCTIONS_H

using namespace std;

#include <string>
#include <vector>

void cgiPage();

void createDB();

void pythonAPI();

void connectDB();

vector <string> read_csv_header(const char* pathCSV);

vector <string> read_csv_data(const char* pathCSV);

#endif //DBCONNECT_FUNCTIONS_H
