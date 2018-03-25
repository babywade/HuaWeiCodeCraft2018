#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Flavor.h"
#include "TimeRecord.h"
#include "DataRecord.h"

using namespace std;

//void logisticRegression();

int main() {
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
        flavors.push_back(flavor);
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
            break;
        case 2:
            ++flavors[1].cnt;
            break;
        case 3:
            ++flavors[2].cnt;
            break;
        case 4:
            ++flavors[3].cnt;
            break;
        case 5:
            ++flavors[4].cnt;
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

    return 0;
}

//void logisticRegression() {
//    alpha = 0.001;
//    num_iters = 1000;
//
//}
