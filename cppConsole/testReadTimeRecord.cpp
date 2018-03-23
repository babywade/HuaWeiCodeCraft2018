#include <iostream>
#include <fstream>
#include <vector>
#include "TimeRecord.h"

using namespace std;

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
