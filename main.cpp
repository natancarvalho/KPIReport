#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "include/functions.h"
#include "include/events.h"

using namespace std;

int main() {

//    Event event;
//    vector <string> csv_header;
//    string csv_data;
//    string collon = ":";
//    string event_name;
//    string line;

//    csv_header = read_csv_header("/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/Outing1.csv");
//
//    for (int i; i < 7; i++){
//        cout << csv_header[i];
//    }
//
//    csv_data = read_csv_data("/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/Outing1.csv");
//
//    size_t found = csv_header[1].rfind(collon);
//
//    cout << csv_header[1] << '\n';
//
//    int counter = found + 1;
//
//    while (csv_header[1][counter] != '\r'){
//        event_name += csv_header[1][counter];
//        counter ++;
//    }
//
//    event.get_name(event_name);

//    cout << csv_data;

    cgiPage();

    pythonAPI();

    return 0;
}
