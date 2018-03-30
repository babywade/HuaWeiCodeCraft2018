//��ά����װ������
#include <iostream>
#include <vector>
#include <algorithm>
#include "hwpair.h"

using namespace std;
//�������
#define VOLUMN_X 10
#define VOLUMN_Y 10

static hwpair VOLUMN(VOLUMN_X, VOLUMN_Y);

//�����㷨
void nextFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
void firstFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
void bestFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
//�ѻ��㷨
void firstFitDecreasing(vector<hwpair>& blocks, vector<int>& answer, int& cnt, vector<hwpair>& volumns);
void bestFitDecreasing(vector<hwpair>& blocks, vector<int>& answer, int& cnt, vector<hwpair>& volumns);

int main() {
    hwpair block;
    vector<int> answer;
    vector<hwpair> volumns;
    //#1���ӳ�ʼ��ΪVOLUMN
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

    //������
    for(auto& s:answer) {
        cout << s << " ";
    }
    cout << endl;
    for(auto& s:volumns) {
        cout << s << " ";
    }
    return 0;
}
    //������Ӧ�㷨
void nextFit(hwpair& block, vector<int>& answer, int& cnt, vector<hwpair>& volumns) {
    //��Ҫ����>=������
    if(volumns[cnt - 1] >= block) {
        answer.push_back(cnt);
        //��Ҫ����-=������
        volumns[cnt - 1] -= block;
    } else {
        ++cnt;
        answer.push_back(cnt);
        //��Ҫ����-������
        volumns.push_back(hwpair(VOLUMN_X - block.getFirst(), VOLUMN_Y - block.getSecond()));
    }
}
    //�״���Ӧ�㷨
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
    //�����Ӧ�㷨
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
