#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("test.txt");
    vector<int> intVector;
    int i;
    while (fin >> i) {
        intVector.push_back(i);
    }
    cout << intVector.size() << endl;
}
