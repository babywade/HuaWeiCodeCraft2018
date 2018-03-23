#include <iostream>
#include <fstream>
#include <vector>

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
    out << timeRecord.year << endl << timeRecord.month << endl << timeRecord.day << endl
    << timeRecord.hour << endl << timeRecord.minute << endl << timeRecord.second << endl;
    return out;
}
int main() {
    ifstream fin("test.txt");
    vector<TimeRecord> timeRecords;
    TimeRecord timeRecord;
    while (fin >> timeRecord) {
        timeRecords.push_back(timeRecord);
    }
    cout << timeRecords.size() << endl;
    //cout << timeRecords[0];
    for (auto &timeRecord : timeRecords) {
        cout << timeRecord;
    }
}
