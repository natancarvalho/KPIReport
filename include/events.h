//
// Created by natan on 28/09/22.
//
#include <iostream>
#include <string>
#include <list>

#ifndef KPIREPORT_EVENTS_H
#define KPIREPORT_EVENTS_H

using namespace std;

class Event{
public:
    //Event (string);
    string get_name(string) const;
    double get_lap_time(double);

private:
    string name;
    double min_lap_time, max_lap_time;
    list <string> sections;
};

#endif //KPIREPORT_EVENTS_H
