#ifndef DATARECORD_H_INCLUDED
#define DATARECORD_H_INCLUDED

#include <iostream>
#include <string>
#include "Flavor.h"
#include "TimeRecord.h"

using namespace std;

class DataRecord {
public:
    string flavorID;
    Flavor flavor;
    TimeRecord timeRecord;
};

istream& operator>>(istream& in, DataRecord& dataRecord) {
    in >> dataRecord.flavorID >> dataRecord.flavor.name >> dataRecord.timeRecord;
    return in;
}

ostream& operator<<(ostream& out, DataRecord& dataRecord) {
    out << dataRecord.flavorID << dataRecord.flavor << dataRecord.timeRecord;
    return out;
}

#endif // DATARECORD_H_INCLUDED
