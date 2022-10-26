#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "include/functions.h"
#include "include/events.h"
#include "include/constants.h"

using namespace std;

int main() {

    Event event;
    vector <string> csv_header;
    vector <string> csv_data;
    string collon = ":";
    string event_name;
    vector <string> lines;


    csv_header = read_csv_header("/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/OriginalOuting1.csv");

//    for (int i; i < 7; i++){
//        cout << csv_header[i];
//    }

    csv_data = read_csv_data("/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/OriginalOuting1.csv");

    csv_data.insert(csv_data.begin(), COLUMN_NAMES);

    size_t found = csv_header[0].rfind(collon);

    cout << csv_header[0] << '\n';

    int counter = found + 1;

    while (csv_header[0][counter] != '\r'){
        event_name += csv_header[0][counter];
        counter ++;
    }

    event.get_name(event_name);


//    connectDB();
//
//    cgiPage();
//
//    pythonAPI();

    return 0;
}
