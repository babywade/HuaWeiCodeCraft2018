#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Flavor.h"
#include "TimeRecord.h"
#include "DataRecord.h"

using namespace std;

#define BOX_X 56
#define BOX_Y 128

class Box {
private:
    int box_x;
    int box_y;
public:
    box(int x, int y) {
        box_x = x;
        box_y = y;
    }
};
class Block {
public:
    int block_x;
    int block_y;
};
//void logisticRegression();

int main() {
    vector<Box> boxLists;
    Box box(BOX_X, BOX_Y);
    boxLists.push_back(box);

    vector<Block> blockLists;
    fstream fin("testBox.txt");
    if(fin.fail()) {
        cout << "failed to open testBox.txt" << endl;
    }
    Block block;
    while(fin >> block) {

    }
    return 0;
}

//void logisticRegression() {
//    alpha = 0.001;
//    num_iters = 1000;
//
//}
