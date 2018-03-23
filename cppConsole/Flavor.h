#ifndef FLAVOR_H_INCLUDED
#define FLAVOR_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Flavor {
public:
    string name;
    int cpu;
    int memory;
    int cnt = 0;
    //int hardDiskStorage;
};

istream& operator>>(istream& in, Flavor& flavor) {
    in >> flavor.name >> flavor.cpu >> flavor.memory;
    return in;
}

ostream& operator<<(ostream& out, Flavor& flavor) {
    out << flavor.name << " " << flavor.cpu << " " << flavor.memory << flavor.cnt << endl;
    return out;
}

#endif // FLAVOR_H_INCLUDED
