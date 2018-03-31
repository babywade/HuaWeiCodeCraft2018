//二维近似装箱问题
#include <iostream>
#include <vector>
#include <algorithm>
#include "hwpair.h"
#include "Flavor.h"
#include "TimeRecord.h"
#include "DataRecord.h"

using namespace std;
//箱子体积
#define VOLUMN_X 56
#define VOLUMN_Y 128
#define RADIX 1024

static hwpair VOLUMN(VOLUMN_X, VOLUMN_Y);

//联机算法
void nextFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
void firstFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
void bestFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
//脱机算法
void firstFitDecreasing(vector<hwpair>& blocks, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
void bestFitDecreasing(vector<hwpair>& blocks, vector<int>& answer, int& cnt, vector<hwpair>& volumns);

double assessFunction();

int main() {
    vector<hwpair> trainData;
    vector<hwpair> blockKinds;
    vector<int> timeData;
    enum month {JAN=31, FEB=28, MAR=31, APR=30, MAY=31, JUN=30,
                JUL=31, AUG=31, SEP=30, OCT=31, NOV=30, DEC=31};

    //变量声明
    int totalCPU, totalMemory, totalHardDiskStorage, totalFlavor;
    Flavor flavor;
    vector<Flavor> flavors;
    string resourceName;
    TimeRecord predictionBegin, predictionEnd;

    //读入input_5flavors_cpu_7days.txt
    ifstream fin("input_5flavors_cpu_7days.txt");
    if (fin.fail()) {
        cout << "failed to open input_5flavors_cpu_7days.txt" << endl;
    }
    fin >> totalCPU >> totalMemory >> totalHardDiskStorage >> totalFlavor;
    for (int i = 0; i < totalFlavor; ++i) {
        fin >> flavor;
        flavor.memory /= RADIX;
        flavors.push_back(flavor);
        blockKinds.push_back(pair(flavor.cpu, flavor.memory));
    }
    fin >> resourceName;
    fin >> predictionBegin >> predictionEnd;
    fin.close();

//    测试读取
//    cout << totalCPU << " " << totalMemory << " " << totalHardDiskStorage << endl
//    << totalFlavor << endl;
//    for (auto &flavor : flavors) {
//        cout << flavor;
//    }
//    cout << resourceName << endl
//    << predictionBegin << predictionEnd;

//  预测
    fin.clear();
    fin.open("TrainData_2015.1.1_2015.2.19.txt");
//    ifstream fpin("TrainData_2015.1.1_2015.2.19.txt");
    DataRecord dataRecord;
    int cntRecord = 0;
    while(fin >> dataRecord) {
        auto s = dataRecord.flavor.name.size();
        string sub = dataRecord.flavor.name.substr(6, s - 1);
//        cout << sub << " ";
        int number = stoi(sub);
//        cout << number << endl;
        ++cntRecord;
        switch(number) {
        case 1:
            ++flavors[0].cnt;
            trainData.push_back(blockKinds[0]);
            break;
        case 2:
            ++flavors[1].cnt;
            trainData.push_back(blcokKinds[1]);
            break;
        case 3:
            ++flavors[2].cnt;
            trainData.push_back(blockKinds[2]);
            break;
        case 4:
            ++flavors[3].cnt;
            trainData.push_back(blockKinds[3]);
            break;
        case 5:
            ++flavors[4].cnt;
            trainData.push_back(blockKinds[4]);
            break;
        default:
            continue;
        }
    }
    int a = flavors[0].cnt;
    int b = flavors[1].cnt;
    int c = flavors[2].cnt;
    int d = flavors[3].cnt;
    int e = flavors[4].cnt;

    cout << "flavor1:" << a << endl
    << "flavor2:" << b << endl
    << "flavor3:" << c << endl
    << "flavor4:" << d << endl
    << "flavor5:" << e << endl
    << "cntRecord:" << cntRecord << endl;

    a = a * 7 / 50;
    b = b * 7 / 50;
    c = c * 7 / 50;
    d = d * 7 / 50;
    e = e * 7 / 50;
    int sum = a + b + c + d + e;
    cout << sum << endl;
    cout << "flavor1 " << a << endl
    << "flavor2 " << b << endl
    << "flavor3 " << c << endl
    << "flavor4 " << d << endl
    << "flavor5 " << e << endl << endl;
//  放置


    hwpair block;
    vector<int> answer;
    vector<hwpair> volumns;
    //#1箱子初始化为VOLUMN
    volumns.push_back(VOLUMN);
    int cnt = 1;
    vector<hwpair> blocks;

    while(cin >> block) {
        nextFit(block, answer, cnt, volumns);
//        firstFit(block, answer, cnt, volumns);
//        bestFit(block, answer, cnt, volumns);

//        blocks.push_back(block);
    }
//    firstFitDecreasing(blocks, answer, cnt, volumns);

    //输出结果
    for(auto& s:answer) {
        cout << s << " ";
    }
    cout << endl;
    for(auto& s:volumns) {
        cout << s << " ";
    }
    return 0;
}
    //下项适应算法
void nextFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns) {
    //需要定义>=操作符
    if(volumns[cnt - 1] >= block) {
        answer.push_back(cnt);
        //需要定义-=操作符
        volumns[cnt - 1] -= block;
    } else {
        ++cnt;
        answer.push_back(cnt);
        //需要定义-操作符
        volumns.push_back(hwpair(VOLUMN_X - block.getFirst(), VOLUMN_Y - block.getSecond()));
    }
}
    //首次适应算法
void firstFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns) {
    for(vector<hwpair>::iterator iter = volumns.begin(); iter != volumns.end(); ++iter) {
        if((*iter) >= block) {
            answer.push_back(iter - volumns.cbegin() + 1);
            *iter -= block;
            return;
        }
    }

    volumns.push_back(hwpair(VOLUMN_X - block.getFirst(), VOLUMN_Y - block.getSecond()));
    ++cnt;
    answer.push_back(cnt);
}
    //最佳适应算法
void bestFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns) {
    int bestPosition = cnt + 1;
    hwpair min_volumn = volumns[0];
    for(vector<hwpair>::iterator iter = volumns.begin(); iter != volumns.end(); ++iter) {
        if((*iter) >= block && (*iter) - block <= min_volumn) {
            bestPosition = iter - volumns.cbegin() + 1;
            min_volumn = (*iter) - block;
            cout << min_volumn << " " << bestPosition << endl;
        }
    }

    if(bestPosition == (cnt + 1)) {
        volumns.push_back(VOLUMN - block);
        ++cnt;
        answer.push_back(cnt);
    } else {
        answer.push_back(bestPosition);
        volumns[bestPosition - 1] -= block;
    }
}

void firstFitDecreasing(vector<hwpair>& blocks, vector<int>& answer, int& cnt, vector<hwpair>& volumns) {
    sort(blocks.begin(), blocks.end());
    for(auto& block:blocks) {
        firstFit(block, answer, cnt, volumns);
    }
}

void bestFitDecreasing(vector<hwpair>& blocks, vector<int>& answer, int& cnt, vector<hwpair>& volumns) {
    sort(blocks.begin(), blocks.end());
    for(auto& block:blocks) {
        bestFit(block, answer, cnt, volumns);
    }
}
