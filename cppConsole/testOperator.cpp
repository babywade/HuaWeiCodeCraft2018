#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Record {
public:
    string name;
    int score;
};

istream& operator>>(istream& in, Record& record) {
    in >> record.name >> record.score;
    return in;
}

int main() {
    ifstream fin("test.txt");
    vector<Record> records;
    Record record;
    while (fin >> record) {
        records.push_back(record);
    }
    cout << records.size() << endl;
}
