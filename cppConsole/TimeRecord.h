#ifndef TIMERECORD_H_INCLUDED
#define TIMERECORD_H_INCLUDED

#include <iostream>

using namespace std;

class TimeRecord {
public:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

istream& operator>>(istream& in, TimeRecord& timeRecord) {
    char d;
    in >> timeRecord.year >> d >> timeRecord.month >> d >> timeRecord.day;
    in >> timeRecord.hour >> d >> timeRecord.minute >> d >> timeRecord.second;
    return in;
}

ostream& operator<<(ostream& out, TimeRecord& timeRecord) {
    out << timeRecord.year << "-" << timeRecord.month << "-" << timeRecord.day << " "
    << timeRecord.hour << ":" << timeRecord.minute << ":" << timeRecord.second << endl;
    return out;
}

#endif // TIMERECORD_H_INCLUDED
